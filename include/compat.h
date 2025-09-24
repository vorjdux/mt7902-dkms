/* SPDX-License-Identifier: ISC */
/* Copyright (C) 2024 MediaTek Inc. */

#ifndef __MT7902_COMPAT_H
#define __MT7902_COMPAT_H

#include <linux/version.h>
/* pull in kernel bool/u32 types when this header is included early */
#include <linux/types.h>
/* delay helpers (msleep) */
#include <linux/delay.h>

/* forward declarations to avoid implicit-function-declaration when this
 * compat header is included before the mt76 mcu implementation that
 * defines mt7902_mt76_connac_mcu_patch_sem_ctrl().
 */
struct mt7902_mt76_dev;
int mt7902_mt76_connac_mcu_patch_sem_ctrl(struct mt7902_mt76_dev *dev, bool get);

/* Compatibility layer for kernel API changes between 6.8 and 6.16 */

/* mac80211 get_txpower callback signature changed in 6.14+ */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 14, 0)
#define MT7902_GET_TXPOWER_SIGNATURE(hw, vif, dbm) \
	mt7902_get_txpower_compat(struct ieee80211_hw *hw, struct ieee80211_vif *vif, unsigned int *dbm)
#define MT7902_GET_TXPOWER_CALL(hw, vif, dbm) \
	mt7902_mt76_get_txpower(hw, vif, (int *)dbm)
#else
#define MT7902_GET_TXPOWER_SIGNATURE(hw, vif, dbm) \
	mt7902_mt76_get_txpower(struct ieee80211_hw *hw, struct ieee80211_vif *vif, int *dbm)
#define MT7902_GET_TXPOWER_CALL(hw, vif, dbm) \
	mt7902_mt76_get_txpower(hw, vif, dbm)
#endif

/* Survey callback changes in 6.15+ */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 15, 0)
#define MT7902_SURVEY_SIGNATURE(hw, idx, survey) \
	mt7902_get_survey_compat(struct ieee80211_hw *hw, int idx, struct survey_info *survey, u32 flags)
#else
#define MT7902_SURVEY_SIGNATURE(hw, idx, survey) \
	mt7902_get_survey(struct ieee80211_hw *hw, int idx, struct survey_info *survey)
#endif

/* Station add/remove callback changes */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 14, 0)
#define MT7902_STA_STATE_SIGNATURE(hw, vif, sta, old_state, new_state) \
	mt7902_sta_state_compat(struct ieee80211_hw *hw, struct ieee80211_vif *vif, \
			       struct ieee80211_sta *sta, enum ieee80211_sta_state old_state, \
			       enum ieee80211_sta_state new_state, bool link_sta)
#else
#define MT7902_STA_STATE_SIGNATURE(hw, vif, sta, old_state, new_state) \
	mt7902_sta_state(struct ieee80211_hw *hw, struct ieee80211_vif *vif, \
			struct ieee80211_sta *sta, enum ieee80211_sta_state old_state, \
			enum ieee80211_sta_state new_state)
#endif

/* Config callback signature changes */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 15, 0)
#define MT7902_CONFIG_SIGNATURE(hw, changed) \
	mt7902_config_compat(struct ieee80211_hw *hw, u32 changed, struct ieee80211_conf *conf)
#else
#define MT7902_CONFIG_SIGNATURE(hw, changed) \
	mt7902_config(struct ieee80211_hw *hw, u32 changed)
#endif

/* BSS info changed callback updates */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 16, 0)
#define MT7902_BSS_INFO_CHANGED_SIGNATURE(hw, vif, info, changed) \
	mt7902_bss_info_changed_compat(struct ieee80211_hw *hw, struct ieee80211_vif *vif, \
				      struct ieee80211_bss_conf *info, u64 changed, unsigned int link_id)
#else
#define MT7902_BSS_INFO_CHANGED_SIGNATURE(hw, vif, info, changed) \
	mt7902_bss_info_changed(struct ieee80211_hw *hw, struct ieee80211_vif *vif, \
			       struct ieee80211_bss_conf *info, u64 changed)
#endif

/* Key management callback changes */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 14, 0)
#define MT7902_SET_KEY_SIGNATURE(hw, cmd, vif, sta, key) \
	mt7902_set_key_compat(struct ieee80211_hw *hw, enum set_key_cmd cmd, \
			     struct ieee80211_vif *vif, struct ieee80211_sta *sta, \
			     struct ieee80211_key_conf *key, unsigned int link_id)
#else
#define MT7902_SET_KEY_SIGNATURE(hw, cmd, vif, sta, key) \
	mt7902_set_key(struct ieee80211_hw *hw, enum set_key_cmd cmd, \
		      struct ieee80211_vif *vif, struct ieee80211_sta *sta, \
		      struct ieee80211_key_conf *key)
#endif

/* Ampdu action callback changes */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 15, 0)
#define MT7902_AMPDU_ACTION_SIGNATURE(hw, vif, params) \
	mt7902_ampdu_action_compat(struct ieee80211_hw *hw, struct ieee80211_vif *vif, \
				  struct ieee80211_ampdu_params *params, unsigned int link_id)
#else
#define MT7902_AMPDU_ACTION_SIGNATURE(hw, vif, params) \
	mt7902_ampdu_action(struct ieee80211_hw *hw, struct ieee80211_vif *vif, \
			   struct ieee80211_ampdu_params *params)
#endif

/* Single place for MCU timeout and patch semaphore retry settings.
 * Use a larger timeout multiplier and more retries on newer kernels
 * (6.14+), which have different timing characteristics observed in
 * firmware loading paths.
 */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 14, 0)
#define MT7902_MCU_TIMEOUT_MULTIPLIER 3
#define MT7902_PATCH_SEM_RETRIES 5
#else
#define MT7902_MCU_TIMEOUT_MULTIPLIER 1
#define MT7902_PATCH_SEM_RETRIES 3
#endif

/* init_dummy_netdev compatibility for kernel 6.14+: provide a no-op
 * replacement when the helper is not available. This keeps driver
 * source files clean and avoids sprinkling #ifdefs.
 */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 14, 0)
static inline void init_dummy_netdev(struct net_device *dev)
{
	/* No-op: embedded netdev structures are zero-initialized */
}
#endif

/* Patch semaphore retry wrapper for improved firmware loading reliability.
 * Provide an unconditional helper so callers can use it without an
 * extra forward declaration. On newer kernels we retry with a small
 * delay; on older kernels we simply forward the call.
 */
static inline int mt7902_patch_sem_ctrl_with_retry(struct mt7902_mt76_dev *dev, bool get)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 14, 0)
	int ret, retries = MT7902_PATCH_SEM_RETRIES;

	do {
		ret = mt7902_mt76_connac_mcu_patch_sem_ctrl(dev, get);
		if (ret >= 0)
			break;

		/* Add small delay between retries for newer kernels */
		msleep(50);
	} while (--retries > 0);

	return ret;
#else
	return mt7902_mt76_connac_mcu_patch_sem_ctrl(dev, get);
#endif
}

/* Helper macros for version-specific code */
#define MT7902_KERNEL_VERSION_GE(major, minor, patch) \
	(LINUX_VERSION_CODE >= KERNEL_VERSION(major, minor, patch))

#define MT7902_KERNEL_VERSION_LT(major, minor, patch) \
	(LINUX_VERSION_CODE < KERNEL_VERSION(major, minor, patch))

#endif /* __MT7902_COMPAT_H */