#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

KSYMTAB_FUNC(mt7902_mac_write_txwi, "_gpl", "");
KSYMTAB_FUNC(mt7902_txwi_free, "_gpl", "");
KSYMTAB_FUNC(mt7902_rx_check, "_gpl", "");
KSYMTAB_FUNC(mt7902_queue_rx_skb, "_gpl", "");
KSYMTAB_FUNC(mt7902_usb_sdio_tx_prepare_skb, "_gpl", "");
KSYMTAB_FUNC(mt7902_usb_sdio_tx_complete_skb, "_gpl", "");
KSYMTAB_FUNC(mt7902_usb_sdio_tx_status_data, "_gpl", "");
KSYMTAB_FUNC(mt7902_mcu_parse_response, "_gpl", "");
KSYMTAB_FUNC(mt7902_mcu_regval, "_gpl", "");
KSYMTAB_FUNC(mt7902_mcu_set_deep_sleep, "_gpl", "");
KSYMTAB_FUNC(mt7902_run_firmware, "_gpl", "");
KSYMTAB_FUNC(mt7902_mcu_set_eeprom, "_gpl", "");
KSYMTAB_FUNC(mt7902_mcu_hw_scan, "_gpl", "");
KSYMTAB_FUNC(mt7902_mcu_sched_scan_req, "_gpl", "");
KSYMTAB_FUNC(mt7902_mcu_cancel_hw_scan, "_gpl", "");
KSYMTAB_FUNC(mt7902_mcu_set_channel_domain, "_gpl", "");
KSYMTAB_FUNC(mt7902_mcu_fill_message, "_gpl", "");
KSYMTAB_FUNC(__mt7902_start, "_gpl", "");
KSYMTAB_FUNC(mt7902_mac_sta_add, "_gpl", "");
KSYMTAB_FUNC(mt7902_mac_sta_assoc, "_gpl", "");
KSYMTAB_FUNC(mt7902_mac_sta_remove, "_gpl", "");
KSYMTAB_DATA(mt7902_ops, "_gpl", "");
KSYMTAB_FUNC(mt7902_mac_init, "_gpl", "");
KSYMTAB_FUNC(mt7902_register_device, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_tx_stats_show, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_queues_acq, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_queues_read, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_pm_stats, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_pm_idle_timeout_set, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_pm_idle_timeout_get, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_tx, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_stop, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_remove_interface, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_conf_tx, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_get_stats, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_get_tsf, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_set_tsf, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_tx_worker, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_roc_timer, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_flush, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_assign_vif_chanctx, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_unassign_vif_chanctx, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_set_wakeup, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_get_et_strings, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_get_et_sset_count, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_get_et_stats, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_sta_statistics, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_set_coverage_class, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_init_wiphy, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_get_mac80211_ops, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_init_wcid, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_mcu_drv_pmctrl, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_mcu_fw_pmctrl, "_gpl", "");
KSYMTAB_FUNC(__mt7902_mt792xe_mcu_drv_pmctrl, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792xe_mcu_drv_pmctrl, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792xe_mcu_fw_pmctrl, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_load_firmware, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_mac_work, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_mac_set_timeing, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_mac_update_mib_stats, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_rx_get_wcid, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_mac_assoc_rssi, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_mac_reset_counters, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_update_channel, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_reset, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_mac_init_band, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_pm_wake_work, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_pm_power_save_work, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_init_acpi_sar, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_init_acpi_sar_power, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_acpi_get_flags, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_acpi_get_mtcl_conf, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_irq_handler, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_irq_tasklet, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_rx_poll_complete, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_dma_enable, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_wpdma_reset, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_wpdma_reinit_cond, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_dma_disable, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_dma_cleanup, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_poll_tx, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_poll_rx, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt792x_wfsys_reset, "_gpl", "");
KSYMTAB_DATA(mt7902_mt76_rates, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_set_stream_caps, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_alloc_phy, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_register_phy, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_unregister_phy, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_create_page_pool, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_alloc_device, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_register_device, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_unregister_device, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_free_device, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_rx, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_has_tx_pending, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_update_survey_active_time, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_update_survey, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_set_channel, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_get_survey, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_wcid_key_setup, "", "");
KSYMTAB_FUNC(mt7902_mt76_rx_signal, "", "");
KSYMTAB_FUNC(mt7902_mt76_rx_poll_complete, "_gpl", "");
KSYMTAB_FUNC(__mt7902_mt76_sta_remove, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_sta_state, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_sta_pre_rcu_remove, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_wcid_init, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_wcid_cleanup, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_get_txpower, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_init_sar_power, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_get_sar_power, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_csa_finish, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_csa_check, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_set_tim, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_insert_ccmp_hdr, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_get_rate, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_sw_scan, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_sw_scan_complete, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_get_antenna, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_init_queue, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_calculate_default_rate, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_ethtool_worker, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_ethtool_page_pool_stats, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_phy_dfs_state, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_start_firmware, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_patch_sem_ctrl, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_start_patch, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_init_download, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_set_channel_domain, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_set_mac_enable, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_set_vif_ps, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_set_rts_thresh, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_beacon_loss_iter, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_add_nested_tlv, "_gpl", "");
KSYMTAB_FUNC(__mt7902_mt76_connac_mcu_alloc_sta_req, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_alloc_wtbl_req, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_bss_omac_tlv, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_sta_basic_tlv, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_sta_uapsd, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_wtbl_hdr_trans_tlv, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_sta_update_hdr_trans, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_wtbl_update_hdr_trans, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_wtbl_generic_tlv, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_sta_he_tlv_v2, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_get_phy_mode_v2, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_sta_tlv, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_wtbl_smps_tlv, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_wtbl_ht_tlv, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_sta_cmd, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_wtbl_ba_tlv, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_uni_add_dev, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_sta_ba_tlv, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_sta_wed_update, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_sta_ba, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_get_phy_mode, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_get_phy_mode_ext, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_get_he_phy_cap, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_get_eht_phy_cap, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_uni_set_chctx, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_uni_add_bss, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_hw_scan, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_cancel_hw_scan, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_sched_scan_req, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_sched_scan_enable, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_chip_config, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_set_deep_sleep, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_sta_state_dp, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_coredump_event, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_get_ch_power, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_set_rate_txpower, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_update_arp_filter, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_set_p2p_oppps, "_gpl", "");
KSYMTAB_DATA(mt7902_mt76_connac_wowlan_support, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_update_gtk_rekey, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_set_gtk_rekey, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_set_suspend_mode, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_set_wow_ctrl, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_set_hif_suspend, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_set_suspend_iter, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_reg_rr, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_reg_wr, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_add_key, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_bss_ext_tlv, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_bss_basic_tlv, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_set_pm, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_restart, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_mcu_rdd_cmd, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac2_load_ram, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac2_load_patch, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac2_mcu_fill_message, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac3_mac_decode_he_radiotap, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_tx_check_agg_ssn, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_tx_status_lock, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_tx_status_unlock, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_tx_status_skb_done, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_tx_status_skb_add, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_tx_status_skb_get, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_tx_status_check, "_gpl", "");
KSYMTAB_FUNC(__mt7902_mt76_tx_complete_skb, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_tx, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_release_buffered_frames, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_txq_schedule, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_txq_schedule_all, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_tx_worker_run, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_stop_tx_queues, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_wake_tx_queue, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_ac_to_hwq, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_skb_adjust_pad, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_queue_tx_complete, "_gpl", "");
KSYMTAB_FUNC(__mt7902_mt76_set_tx_blocked, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_token_consume, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_rx_token_consume, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_token_release, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_rx_token_release, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_rx_aggr_start, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_rx_aggr_stop, "_gpl", "");
KSYMTAB_FUNC(__mt7902_mt76_poll, "_gpl", "");
KSYMTAB_FUNC(____mt7902_mt76_poll_msec, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_wcid_alloc, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_get_min_avg_rssi, "_gpl", "");
KSYMTAB_FUNC(__mt7902_mt76_worker_fn, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_get_of_data_from_mtd, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_get_of_data_from_nvmem, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_eeprom_override, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_find_power_limits_node, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_find_channel_node, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_get_rate_power_limits, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_eeprom_init, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_queues_read, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_seq_puts_array, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_register_debugfs_fops, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_get_rxwi, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_put_txwi, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_put_rxwi, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_free_pending_rxwi, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_dma_rx_poll, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_dma_attach, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_dma_cleanup, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_gen_ppe_thresh, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_pm_wake, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_power_save_sched, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_free_pending_tx_skbs, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_pm_queue_skb, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_pm_dequeue_skbs, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_tx_complete_skb, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_write_hw_txp, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_txp_skb_unmap, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac_init_tx_queues, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac2_mac_tx_rate_val, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac2_mac_write_txwi, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac2_mac_fill_txs, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac2_mac_add_txs_skb, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac2_mac_decode_he_radiotap, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac2_reverse_frag0_hdr_trans, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac2_mac_fill_rx_rate, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac2_tx_check_aggr, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac2_txwi_free, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_connac2_tx_token_put, "_gpl", "");
KSYMTAB_FUNC(__mt7902_mt76_mcu_msg_alloc, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_mcu_get_response, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_mcu_rx_event, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_mcu_send_and_get_msg, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_mcu_skb_send_and_get_msg, "_gpl", "");
KSYMTAB_FUNC(__mt7902_mt76_mcu_send_firmware, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_pci_disable_aspm, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_set_irq_mask, "_gpl", "");
KSYMTAB_FUNC(mt7902_mt76_mmio_init, "_gpl", "");

SYMBOL_CRC(mt7902_mac_write_txwi, 0x8c22bd28, "_gpl");
SYMBOL_CRC(mt7902_txwi_free, 0xeec67f05, "_gpl");
SYMBOL_CRC(mt7902_rx_check, 0x01f83803, "_gpl");
SYMBOL_CRC(mt7902_queue_rx_skb, 0x1149bdd8, "_gpl");
SYMBOL_CRC(mt7902_usb_sdio_tx_prepare_skb, 0xa1174287, "_gpl");
SYMBOL_CRC(mt7902_usb_sdio_tx_complete_skb, 0x5de108d0, "_gpl");
SYMBOL_CRC(mt7902_usb_sdio_tx_status_data, 0x2e4e6984, "_gpl");
SYMBOL_CRC(mt7902_mcu_parse_response, 0xee0d1eb4, "_gpl");
SYMBOL_CRC(mt7902_mcu_regval, 0x75e721a1, "_gpl");
SYMBOL_CRC(mt7902_mcu_set_deep_sleep, 0x18294be3, "_gpl");
SYMBOL_CRC(mt7902_run_firmware, 0x059e439a, "_gpl");
SYMBOL_CRC(mt7902_mcu_set_eeprom, 0xf4c8fb0d, "_gpl");
SYMBOL_CRC(mt7902_mcu_hw_scan, 0x36f2cd2e, "_gpl");
SYMBOL_CRC(mt7902_mcu_sched_scan_req, 0xa3d1c1b7, "_gpl");
SYMBOL_CRC(mt7902_mcu_cancel_hw_scan, 0x56c6e66f, "_gpl");
SYMBOL_CRC(mt7902_mcu_set_channel_domain, 0x88a08f74, "_gpl");
SYMBOL_CRC(mt7902_mcu_fill_message, 0xbe1cf043, "_gpl");
SYMBOL_CRC(__mt7902_start, 0x2edb4d68, "_gpl");
SYMBOL_CRC(mt7902_mac_sta_add, 0xddb425a4, "_gpl");
SYMBOL_CRC(mt7902_mac_sta_assoc, 0x124981c4, "_gpl");
SYMBOL_CRC(mt7902_mac_sta_remove, 0xe693422f, "_gpl");
SYMBOL_CRC(mt7902_ops, 0x7d975b6f, "_gpl");
SYMBOL_CRC(mt7902_mac_init, 0x7abd33e6, "_gpl");
SYMBOL_CRC(mt7902_register_device, 0x610a26c1, "_gpl");
SYMBOL_CRC(mt7902_mt792x_tx_stats_show, 0x0f53fca7, "_gpl");
SYMBOL_CRC(mt7902_mt792x_queues_acq, 0xb09565bb, "_gpl");
SYMBOL_CRC(mt7902_mt792x_queues_read, 0x67edd6bd, "_gpl");
SYMBOL_CRC(mt7902_mt792x_pm_stats, 0xbb43d2b6, "_gpl");
SYMBOL_CRC(mt7902_mt792x_pm_idle_timeout_set, 0xb27ad48a, "_gpl");
SYMBOL_CRC(mt7902_mt792x_pm_idle_timeout_get, 0xf630d44b, "_gpl");
SYMBOL_CRC(mt7902_mt792x_tx, 0xd3daac97, "_gpl");
SYMBOL_CRC(mt7902_mt792x_stop, 0xc6b2f83e, "_gpl");
SYMBOL_CRC(mt7902_mt792x_remove_interface, 0x8d487ab4, "_gpl");
SYMBOL_CRC(mt7902_mt792x_conf_tx, 0xb040294f, "_gpl");
SYMBOL_CRC(mt7902_mt792x_get_stats, 0x9ee5968e, "_gpl");
SYMBOL_CRC(mt7902_mt792x_get_tsf, 0x707db2bd, "_gpl");
SYMBOL_CRC(mt7902_mt792x_set_tsf, 0x68d08d35, "_gpl");
SYMBOL_CRC(mt7902_mt792x_tx_worker, 0x3ef6ca89, "_gpl");
SYMBOL_CRC(mt7902_mt792x_roc_timer, 0x689ba656, "_gpl");
SYMBOL_CRC(mt7902_mt792x_flush, 0xfa6c0e8d, "_gpl");
SYMBOL_CRC(mt7902_mt792x_assign_vif_chanctx, 0x74554647, "_gpl");
SYMBOL_CRC(mt7902_mt792x_unassign_vif_chanctx, 0xa9ce3762, "_gpl");
SYMBOL_CRC(mt7902_mt792x_set_wakeup, 0x64f6ff87, "_gpl");
SYMBOL_CRC(mt7902_mt792x_get_et_strings, 0xd973355b, "_gpl");
SYMBOL_CRC(mt7902_mt792x_get_et_sset_count, 0xa69f9daa, "_gpl");
SYMBOL_CRC(mt7902_mt792x_get_et_stats, 0x846f5ccf, "_gpl");
SYMBOL_CRC(mt7902_mt792x_sta_statistics, 0x46176bd4, "_gpl");
SYMBOL_CRC(mt7902_mt792x_set_coverage_class, 0xb1e0fa4c, "_gpl");
SYMBOL_CRC(mt7902_mt792x_init_wiphy, 0xe0ada1b5, "_gpl");
SYMBOL_CRC(mt7902_mt792x_get_mac80211_ops, 0xa0b0d281, "_gpl");
SYMBOL_CRC(mt7902_mt792x_init_wcid, 0x4a06c961, "_gpl");
SYMBOL_CRC(mt7902_mt792x_mcu_drv_pmctrl, 0xf4a2b13e, "_gpl");
SYMBOL_CRC(mt7902_mt792x_mcu_fw_pmctrl, 0x5d46c585, "_gpl");
SYMBOL_CRC(__mt7902_mt792xe_mcu_drv_pmctrl, 0xa7cc8739, "_gpl");
SYMBOL_CRC(mt7902_mt792xe_mcu_drv_pmctrl, 0x7f4a5851, "_gpl");
SYMBOL_CRC(mt7902_mt792xe_mcu_fw_pmctrl, 0x0b1740df, "_gpl");
SYMBOL_CRC(mt7902_mt792x_load_firmware, 0x606200a4, "_gpl");
SYMBOL_CRC(mt7902_mt792x_mac_work, 0x8ddc9655, "_gpl");
SYMBOL_CRC(mt7902_mt792x_mac_set_timeing, 0xa63f81f6, "_gpl");
SYMBOL_CRC(mt7902_mt792x_mac_update_mib_stats, 0x3fb62dd9, "_gpl");
SYMBOL_CRC(mt7902_mt792x_rx_get_wcid, 0x1f42fb54, "_gpl");
SYMBOL_CRC(mt7902_mt792x_mac_assoc_rssi, 0x2b5e7d2c, "_gpl");
SYMBOL_CRC(mt7902_mt792x_mac_reset_counters, 0xbc9cc237, "_gpl");
SYMBOL_CRC(mt7902_mt792x_update_channel, 0x2f3d06b6, "_gpl");
SYMBOL_CRC(mt7902_mt792x_reset, 0x1bcb443b, "_gpl");
SYMBOL_CRC(mt7902_mt792x_mac_init_band, 0xa90b5d7c, "_gpl");
SYMBOL_CRC(mt7902_mt792x_pm_wake_work, 0xb0c444ef, "_gpl");
SYMBOL_CRC(mt7902_mt792x_pm_power_save_work, 0xf5cf3907, "_gpl");
SYMBOL_CRC(mt7902_mt792x_init_acpi_sar, 0xc260ddc8, "_gpl");
SYMBOL_CRC(mt7902_mt792x_init_acpi_sar_power, 0x32e7aa44, "_gpl");
SYMBOL_CRC(mt7902_mt792x_acpi_get_flags, 0x9f525567, "_gpl");
SYMBOL_CRC(mt7902_mt792x_acpi_get_mtcl_conf, 0x2812fba6, "_gpl");
SYMBOL_CRC(mt7902_mt792x_irq_handler, 0x2899b3bd, "_gpl");
SYMBOL_CRC(mt7902_mt792x_irq_tasklet, 0x15731f57, "_gpl");
SYMBOL_CRC(mt7902_mt792x_rx_poll_complete, 0xafd06cad, "_gpl");
SYMBOL_CRC(mt7902_mt792x_dma_enable, 0x58b36d39, "_gpl");
SYMBOL_CRC(mt7902_mt792x_wpdma_reset, 0x7f51389b, "_gpl");
SYMBOL_CRC(mt7902_mt792x_wpdma_reinit_cond, 0x4f171c4a, "_gpl");
SYMBOL_CRC(mt7902_mt792x_dma_disable, 0x47037d57, "_gpl");
SYMBOL_CRC(mt7902_mt792x_dma_cleanup, 0xa4144475, "_gpl");
SYMBOL_CRC(mt7902_mt792x_poll_tx, 0x4c7a80a5, "_gpl");
SYMBOL_CRC(mt7902_mt792x_poll_rx, 0xd0be8d65, "_gpl");
SYMBOL_CRC(mt7902_mt792x_wfsys_reset, 0x4d620c5c, "_gpl");
SYMBOL_CRC(mt7902_mt76_rates, 0xb3fbaf56, "_gpl");
SYMBOL_CRC(mt7902_mt76_set_stream_caps, 0x9fa14edf, "_gpl");
SYMBOL_CRC(mt7902_mt76_alloc_phy, 0x24d0facd, "_gpl");
SYMBOL_CRC(mt7902_mt76_register_phy, 0xd1ab10e4, "_gpl");
SYMBOL_CRC(mt7902_mt76_unregister_phy, 0xc7af204c, "_gpl");
SYMBOL_CRC(mt7902_mt76_create_page_pool, 0xcd44d358, "_gpl");
SYMBOL_CRC(mt7902_mt76_alloc_device, 0x84c85bd8, "_gpl");
SYMBOL_CRC(mt7902_mt76_register_device, 0xe38a1725, "_gpl");
SYMBOL_CRC(mt7902_mt76_unregister_device, 0x66e52648, "_gpl");
SYMBOL_CRC(mt7902_mt76_free_device, 0x9264e7ce, "_gpl");
SYMBOL_CRC(mt7902_mt76_rx, 0xa884f47f, "_gpl");
SYMBOL_CRC(mt7902_mt76_has_tx_pending, 0xdb18b97c, "_gpl");
SYMBOL_CRC(mt7902_mt76_update_survey_active_time, 0x9f425568, "_gpl");
SYMBOL_CRC(mt7902_mt76_update_survey, 0xae98c112, "_gpl");
SYMBOL_CRC(mt7902_mt76_set_channel, 0x593a657f, "_gpl");
SYMBOL_CRC(mt7902_mt76_get_survey, 0xcbbb0ef2, "_gpl");
SYMBOL_CRC(mt7902_mt76_wcid_key_setup, 0xb217f849, "");
SYMBOL_CRC(mt7902_mt76_rx_signal, 0x07eab70b, "");
SYMBOL_CRC(mt7902_mt76_rx_poll_complete, 0xa89c23e2, "_gpl");
SYMBOL_CRC(__mt7902_mt76_sta_remove, 0xfd3d6432, "_gpl");
SYMBOL_CRC(mt7902_mt76_sta_state, 0x8f85d6a3, "_gpl");
SYMBOL_CRC(mt7902_mt76_sta_pre_rcu_remove, 0x439302f8, "_gpl");
SYMBOL_CRC(mt7902_mt76_wcid_init, 0x21281c7d, "_gpl");
SYMBOL_CRC(mt7902_mt76_wcid_cleanup, 0x681ea107, "_gpl");
SYMBOL_CRC(mt7902_mt76_get_txpower, 0xe009c91b, "_gpl");
SYMBOL_CRC(mt7902_mt76_init_sar_power, 0x4297c285, "_gpl");
SYMBOL_CRC(mt7902_mt76_get_sar_power, 0xfab0551f, "_gpl");
SYMBOL_CRC(mt7902_mt76_csa_finish, 0xfd9245ee, "_gpl");
SYMBOL_CRC(mt7902_mt76_csa_check, 0x0d801dae, "_gpl");
SYMBOL_CRC(mt7902_mt76_set_tim, 0x388b68e1, "_gpl");
SYMBOL_CRC(mt7902_mt76_insert_ccmp_hdr, 0x4cd378f3, "_gpl");
SYMBOL_CRC(mt7902_mt76_get_rate, 0x7a5a736b, "_gpl");
SYMBOL_CRC(mt7902_mt76_sw_scan, 0xa133c13c, "_gpl");
SYMBOL_CRC(mt7902_mt76_sw_scan_complete, 0x4cb3abff, "_gpl");
SYMBOL_CRC(mt7902_mt76_get_antenna, 0x21be878c, "_gpl");
SYMBOL_CRC(mt7902_mt76_init_queue, 0x6b2e3769, "_gpl");
SYMBOL_CRC(mt7902_mt76_calculate_default_rate, 0xa6269fff, "_gpl");
SYMBOL_CRC(mt7902_mt76_ethtool_worker, 0x63e8773f, "_gpl");
SYMBOL_CRC(mt7902_mt76_ethtool_page_pool_stats, 0x529adddd, "_gpl");
SYMBOL_CRC(mt7902_mt76_phy_dfs_state, 0xb2a2d1b1, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_start_firmware, 0xb22eed76, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_patch_sem_ctrl, 0xaad800f2, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_start_patch, 0x7eab258e, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_init_download, 0xec3ce824, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_set_channel_domain, 0xb2a1d435, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_set_mac_enable, 0x6c882bda, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_set_vif_ps, 0x47d6c932, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_set_rts_thresh, 0xcdca07c0, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_beacon_loss_iter, 0x870a9a93, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_add_nested_tlv, 0xecb81f46, "_gpl");
SYMBOL_CRC(__mt7902_mt76_connac_mcu_alloc_sta_req, 0x1a9d54b2, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_alloc_wtbl_req, 0xb3c0355c, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_bss_omac_tlv, 0x3ee137a0, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_sta_basic_tlv, 0x32bd4859, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_sta_uapsd, 0x9e78248d, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_wtbl_hdr_trans_tlv, 0x400834f7, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_sta_update_hdr_trans, 0x1bba6fbc, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_wtbl_update_hdr_trans, 0x35bfe2e6, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_wtbl_generic_tlv, 0xc758a540, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_sta_he_tlv_v2, 0x5eb4d9d3, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_get_phy_mode_v2, 0xadacb3a3, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_sta_tlv, 0xc079fe3c, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_wtbl_smps_tlv, 0x1c04f2d5, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_wtbl_ht_tlv, 0xf84f0ec0, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_sta_cmd, 0x9e79003b, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_wtbl_ba_tlv, 0x18f04d21, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_uni_add_dev, 0x24f205af, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_sta_ba_tlv, 0xe848cb8d, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_sta_wed_update, 0xd19bdaae, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_sta_ba, 0x97db1446, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_get_phy_mode, 0xf52ec517, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_get_phy_mode_ext, 0xf873632e, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_get_he_phy_cap, 0x1c4e0fa5, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_get_eht_phy_cap, 0x04b3fff1, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_uni_set_chctx, 0x2e193cdb, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_uni_add_bss, 0x2580cfdf, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_hw_scan, 0x0e9f1b91, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_cancel_hw_scan, 0x6c3319b4, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_sched_scan_req, 0xa5db3bb4, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_sched_scan_enable, 0x5d9e3b37, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_chip_config, 0x314db690, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_set_deep_sleep, 0x443154bf, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_sta_state_dp, 0x1ec8c2ff, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_coredump_event, 0x11676d9e, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_get_ch_power, 0x018fec16, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_set_rate_txpower, 0x6e4d325e, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_update_arp_filter, 0xd8efec09, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_set_p2p_oppps, 0xd3542ca3, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_wowlan_support, 0x9966710b, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_update_gtk_rekey, 0xa0ec762f, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_set_gtk_rekey, 0x7c55ae0f, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_set_suspend_mode, 0x373d98de, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_set_wow_ctrl, 0x3d5f9355, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_set_hif_suspend, 0x22feae5e, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_set_suspend_iter, 0xffc797bb, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_reg_rr, 0x69ec7ce5, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_reg_wr, 0x64d87c90, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_add_key, 0x28ca021a, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_bss_ext_tlv, 0x0e200feb, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_bss_basic_tlv, 0x3737a310, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_set_pm, 0xa6d5a9c5, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_restart, 0x316c10dd, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_mcu_rdd_cmd, 0x7d93ead0, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac2_load_ram, 0xc1bc5d72, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac2_load_patch, 0x3d0e9b14, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac2_mcu_fill_message, 0x8e65ea3d, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac3_mac_decode_he_radiotap, 0x25c19620, "_gpl");
SYMBOL_CRC(mt7902_mt76_tx_check_agg_ssn, 0xcde366a0, "_gpl");
SYMBOL_CRC(mt7902_mt76_tx_status_lock, 0x11d54a71, "_gpl");
SYMBOL_CRC(mt7902_mt76_tx_status_unlock, 0x4963895c, "_gpl");
SYMBOL_CRC(mt7902_mt76_tx_status_skb_done, 0x1339b14b, "_gpl");
SYMBOL_CRC(mt7902_mt76_tx_status_skb_add, 0x1d77259d, "_gpl");
SYMBOL_CRC(mt7902_mt76_tx_status_skb_get, 0x6a5a3bdf, "_gpl");
SYMBOL_CRC(mt7902_mt76_tx_status_check, 0x09e81767, "_gpl");
SYMBOL_CRC(__mt7902_mt76_tx_complete_skb, 0x47615819, "_gpl");
SYMBOL_CRC(mt7902_mt76_tx, 0xd11a0174, "_gpl");
SYMBOL_CRC(mt7902_mt76_release_buffered_frames, 0x3fa0ab37, "_gpl");
SYMBOL_CRC(mt7902_mt76_txq_schedule, 0x54db8fc6, "_gpl");
SYMBOL_CRC(mt7902_mt76_txq_schedule_all, 0x58ef2036, "_gpl");
SYMBOL_CRC(mt7902_mt76_tx_worker_run, 0xa4cc9c42, "_gpl");
SYMBOL_CRC(mt7902_mt76_stop_tx_queues, 0x78bb848d, "_gpl");
SYMBOL_CRC(mt7902_mt76_wake_tx_queue, 0x4772dfa4, "_gpl");
SYMBOL_CRC(mt7902_mt76_ac_to_hwq, 0x1ebbb357, "_gpl");
SYMBOL_CRC(mt7902_mt76_skb_adjust_pad, 0xc41b8bec, "_gpl");
SYMBOL_CRC(mt7902_mt76_queue_tx_complete, 0x5ddd325e, "_gpl");
SYMBOL_CRC(__mt7902_mt76_set_tx_blocked, 0x359935e1, "_gpl");
SYMBOL_CRC(mt7902_mt76_token_consume, 0x39193377, "_gpl");
SYMBOL_CRC(mt7902_mt76_rx_token_consume, 0xaaec6349, "_gpl");
SYMBOL_CRC(mt7902_mt76_token_release, 0xaa3d7b6f, "_gpl");
SYMBOL_CRC(mt7902_mt76_rx_token_release, 0x9086ea8e, "_gpl");
SYMBOL_CRC(mt7902_mt76_rx_aggr_start, 0x04341bb9, "_gpl");
SYMBOL_CRC(mt7902_mt76_rx_aggr_stop, 0xaf0fa8bc, "_gpl");
SYMBOL_CRC(__mt7902_mt76_poll, 0x6db03d56, "_gpl");
SYMBOL_CRC(____mt7902_mt76_poll_msec, 0xee8f889b, "_gpl");
SYMBOL_CRC(mt7902_mt76_wcid_alloc, 0x3571a761, "_gpl");
SYMBOL_CRC(mt7902_mt76_get_min_avg_rssi, 0x6fd9b507, "_gpl");
SYMBOL_CRC(__mt7902_mt76_worker_fn, 0xe96b64eb, "_gpl");
SYMBOL_CRC(mt7902_mt76_get_of_data_from_mtd, 0xe52ca994, "_gpl");
SYMBOL_CRC(mt7902_mt76_get_of_data_from_nvmem, 0x06c93a3b, "_gpl");
SYMBOL_CRC(mt7902_mt76_eeprom_override, 0xfef0f229, "_gpl");
SYMBOL_CRC(mt7902_mt76_find_power_limits_node, 0x20ec765d, "_gpl");
SYMBOL_CRC(mt7902_mt76_find_channel_node, 0x560b8e3a, "_gpl");
SYMBOL_CRC(mt7902_mt76_get_rate_power_limits, 0x79f9a5ff, "_gpl");
SYMBOL_CRC(mt7902_mt76_eeprom_init, 0xa2928db2, "_gpl");
SYMBOL_CRC(mt7902_mt76_queues_read, 0x729c138c, "_gpl");
SYMBOL_CRC(mt7902_mt76_seq_puts_array, 0x367490e7, "_gpl");
SYMBOL_CRC(mt7902_mt76_register_debugfs_fops, 0x068b8121, "_gpl");
SYMBOL_CRC(mt7902_mt76_get_rxwi, 0x89de59af, "_gpl");
SYMBOL_CRC(mt7902_mt76_put_txwi, 0x9e633dad, "_gpl");
SYMBOL_CRC(mt7902_mt76_put_rxwi, 0x69a13382, "_gpl");
SYMBOL_CRC(mt7902_mt76_free_pending_rxwi, 0x3d8d3900, "_gpl");
SYMBOL_CRC(mt7902_mt76_dma_rx_poll, 0xee95ac18, "_gpl");
SYMBOL_CRC(mt7902_mt76_dma_attach, 0x2aac008c, "_gpl");
SYMBOL_CRC(mt7902_mt76_dma_cleanup, 0x21e57270, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_gen_ppe_thresh, 0xd56d1074, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_pm_wake, 0xc9578da3, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_power_save_sched, 0xc36486c6, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_free_pending_tx_skbs, 0xd4b0e855, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_pm_queue_skb, 0xd70ed5b8, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_pm_dequeue_skbs, 0x2e66d911, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_tx_complete_skb, 0xe2d9e110, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_write_hw_txp, 0x71a9ca3e, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_txp_skb_unmap, 0x198257ac, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac_init_tx_queues, 0xfc97b4a3, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac2_mac_tx_rate_val, 0xf59a7bb2, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac2_mac_write_txwi, 0xae455805, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac2_mac_fill_txs, 0xb3a98758, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac2_mac_add_txs_skb, 0x5c7d5242, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac2_mac_decode_he_radiotap, 0x59267671, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac2_reverse_frag0_hdr_trans, 0x4bb15e96, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac2_mac_fill_rx_rate, 0x889ced00, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac2_tx_check_aggr, 0xbf422cfc, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac2_txwi_free, 0xf1ab7f45, "_gpl");
SYMBOL_CRC(mt7902_mt76_connac2_tx_token_put, 0xfe91b1fb, "_gpl");
SYMBOL_CRC(__mt7902_mt76_mcu_msg_alloc, 0xc73ffaf3, "_gpl");
SYMBOL_CRC(mt7902_mt76_mcu_get_response, 0x6027184d, "_gpl");
SYMBOL_CRC(mt7902_mt76_mcu_rx_event, 0x74046a5a, "_gpl");
SYMBOL_CRC(mt7902_mt76_mcu_send_and_get_msg, 0x241b915e, "_gpl");
SYMBOL_CRC(mt7902_mt76_mcu_skb_send_and_get_msg, 0x8fb5d06e, "_gpl");
SYMBOL_CRC(__mt7902_mt76_mcu_send_firmware, 0x6f70fe1f, "_gpl");
SYMBOL_CRC(mt7902_mt76_pci_disable_aspm, 0xe6bbcf3a, "_gpl");
SYMBOL_CRC(mt7902_mt76_set_irq_mask, 0x13b492c3, "_gpl");
SYMBOL_CRC(mt7902_mt76_mmio_init, 0x8237b967, "_gpl");

static const char ____versions[]
__used __section("__versions") =
	"\x1c\x00\x00\x00\xd7\x22\x7f\x58"
	"devmap_managed_key\0\0"
	"\x28\x00\x00\x00\x80\xb5\xd3\x38"
	"ieee80211_sta_register_airtime\0\0"
	"\x18\x00\x00\x00\xce\xb0\x1d\xc3"
	"is_vmalloc_addr\0"
	"\x24\x00\x00\x00\x07\x1d\x73\x8c"
	"pcie_capability_read_word\0\0\0"
	"\x24\x00\x00\x00\x33\x76\x96\x18"
	"device_set_wakeup_enable\0\0\0\0"
	"\x14\x00\x00\x00\xe1\xd9\x5c\xbf"
	"__skb_pad\0\0\0"
	"\x24\x00\x00\x00\xdd\x2c\x72\xe4"
	"ieee80211_connection_loss\0\0\0"
	"\x1c\x00\x00\x00\xa9\x9a\xd0\xc6"
	"release_firmware\0\0\0\0"
	"\x1c\x00\x00\x00\x27\xfb\x01\xcf"
	"is_acpi_device_node\0"
	"\x1c\x00\x00\x00\x0d\xf4\x16\xd2"
	"page_pool_get_stats\0"
	"\x1c\x00\x00\x00\x78\x6a\xca\xf8"
	"simple_attr_open\0\0\0\0"
	"\x18\x00\x00\x00\xed\x25\xcd\x49"
	"alloc_workqueue\0"
	"\x24\x00\x00\x00\x92\x49\x0e\x89"
	"__ieee80211_schedule_txq\0\0\0\0"
	"\x28\x00\x00\x00\xdb\x60\xc5\x56"
	"ieee80211_iterate_interfaces\0\0\0\0"
	"\x1c\x00\x00\x00\x55\xda\x91\xde"
	"debugfs_attr_write\0\0"
	"\x18\x00\x00\x00\x21\xb7\x93\xa1"
	"devm_kmalloc\0\0\0\0"
	"\x10\x00\x00\x00\x83\x7b\xe8\x0d"
	"skb_put\0"
	"\x18\x00\x00\x00\x14\x27\x52\x8d"
	"__rcu_read_lock\0"
	"\x20\x00\x00\x00\xf4\x57\x7a\xc7"
	"page_pool_alloc_frag\0\0\0\0"
	"\x1c\x00\x00\x00\x8f\x18\x02\x7f"
	"__msecs_to_jiffies\0\0"
	"\x14\x00\x00\x00\xca\xec\xe4\xd2"
	"consume_skb\0"
	"\x10\x00\x00\x00\xeb\x02\xe6\xb0"
	"memmove\0"
	"\x20\x00\x00\x00\x0a\x2b\x12\x46"
	"netif_napi_add_weight\0\0\0"
	"\x14\x00\x00\x00\x6e\x4a\x6e\x65"
	"snprintf\0\0\0\0"
	"\x18\x00\x00\x00\x36\xf2\xb6\xc5"
	"queue_work_on\0\0\0"
	"\x1c\x00\x00\x00\xab\x82\x43\x7a"
	"dmam_alloc_attrs\0\0\0\0"
	"\x20\x00\x00\x00\x49\xf1\x8b\x6b"
	"netif_receive_skb_list\0\0"
	"\x14\x00\x00\x00\xcf\xe4\x45\x96"
	"skb_dequeue\0"
	"\x20\x00\x00\x00\xb5\x41\x87\x60"
	"__init_swait_queue_head\0"
	"\x14\x00\x00\x00\xbf\x0f\x54\x92"
	"finish_wait\0"
	"\x1c\x00\x00\x00\x4c\x66\x8f\x1e"
	"ieee80211_free_hw\0\0\0"
	"\x20\x00\x00\x00\x8d\x5e\x74\x66"
	"dma_unmap_page_attrs\0\0\0\0"
	"\x28\x00\x00\x00\x2e\xc6\x06\xef"
	"ieee80211_txq_schedule_start\0\0\0\0"
	"\x18\x00\x00\x00\xb9\x34\xc1\x74"
	"__sw_hweight32\0\0"
	"\x1c\x00\x00\x00\x4b\x2d\xaa\x2b"
	"request_firmware\0\0\0\0"
	"\x24\x00\x00\x00\x6f\x6f\x23\x4c"
	"__x86_indirect_thunk_r15\0\0\0\0"
	"\x2c\x00\x00\x00\x97\x93\x69\x88"
	"ieee80211_iterate_stations_atomic\0\0\0"
	"\x24\x00\x00\x00\x84\x95\x07\xbd"
	"dma_sync_single_for_device\0\0"
	"\x18\x00\x00\x00\x03\xb1\x22\xe2"
	"skb_add_rx_frag\0"
	"\x20\x00\x00\x00\xd7\xcf\x68\xcb"
	"ieee80211_tx_status_ext\0"
	"\x1c\x00\x00\x00\xeb\x05\x5e\x3c"
	"debugfs_create_blob\0"
	"\x28\x00\x00\x00\x13\x73\x0d\x81"
	"ieee80211_start_tx_ba_session\0\0\0"
	"\x10\x00\x00\x00\x38\xdf\xac\x69"
	"memcpy\0\0"
	"\x20\x00\x00\x00\xb8\xf7\xa4\xc9"
	"ieee80211_beacon_loss\0\0\0"
	"\x10\x00\x00\x00\xba\x0c\x7a\x03"
	"kfree\0\0\0"
	"\x1c\x00\x00\x00\xad\x82\xb0\xae"
	"_raw_read_unlock_bh\0"
	"\x1c\x00\x00\x00\x2d\x72\xee\x8d"
	"_raw_read_lock_bh\0\0\0"
	"\x14\x00\x00\x00\x22\xf7\xaf\xb8"
	"pcpu_hot\0\0\0\0"
	"\x14\x00\x00\x00\x12\xf2\x69\x73"
	"seq_lseek\0\0\0"
	"\x18\x00\x00\x00\xf4\x22\x53\xf9"
	"kthread_parkme\0\0"
	"\x1c\x00\x00\x00\xa2\x11\xb3\x27"
	"page_pool_destroy\0\0\0"
	"\x28\x00\x00\x00\xa7\xdf\x92\x72"
	"__put_devmap_managed_page_refs\0\0"
	"\x20\x00\x00\x00\xa7\xa1\xad\x0b"
	"ieee80211_register_hw\0\0\0"
	"\x20\x00\x00\x00\x24\x76\x52\x5f"
	"led_classdev_unregister\0"
	"\x2c\x00\x00\x00\x22\xfe\x55\xb4"
	"__ieee80211_create_tpt_led_trigger\0\0"
	"\x1c\x00\x00\x00\x20\x5d\x05\xc3"
	"usleep_range_state\0\0"
	"\x20\x00\x00\x00\x95\xd4\x26\x8c"
	"prepare_to_wait_event\0\0\0"
	"\x1c\x00\x00\x00\x6e\x64\xf7\xb3"
	"kthread_should_stop\0"
	"\x1c\x00\x00\x00\xdc\x90\xee\x82"
	"timer_delete_sync\0\0\0"
	"\x1c\x00\x00\x00\x62\x85\xfe\x5f"
	"ieee80211_sta_eosp\0\0"
	"\x28\x00\x00\x00\x4f\x8e\x15\xa3"
	"ieee80211_get_hdrlen_from_skb\0\0\0"
	"\x14\x00\x00\x00\x44\x43\x96\xe2"
	"__wake_up\0\0\0"
	"\x1c\x00\x00\x00\x8c\x1c\x2d\x25"
	"__netif_napi_del\0\0\0\0"
	"\x20\x00\x00\x00\x0b\x05\xdb\x34"
	"_raw_spin_lock_irqsave\0\0"
	"\x18\x00\x00\x00\xd6\x22\x7b\xf3"
	"kthread_park\0\0\0\0"
	"\x1c\x00\x00\x00\x6c\xc6\x67\x20"
	"__dynamic_dev_dbg\0\0\0"
	"\x1c\x00\x00\x00\xad\x2e\xd7\x2e"
	"sched_set_fifo_low\0\0"
	"\x18\x00\x00\x00\x64\xbd\x8f\xba"
	"_raw_spin_lock\0\0"
	"\x1c\x00\x00\x00\xe1\xfb\xde\x79"
	"kthread_should_park\0"
	"\x18\x00\x00\x00\x8c\x89\xd4\xcb"
	"fortify_panic\0\0\0"
	"\x14\x00\x00\x00\xbb\x6d\xfb\xbd"
	"__fentry__\0\0"
	"\x18\x00\x00\x00\x59\x41\x0e\xf1"
	"wake_up_process\0"
	"\x20\x00\x00\x00\x09\x55\xe7\x68"
	"skb_queue_purge_reason\0\0"
	"\x1c\x00\x00\x00\xde\x76\x52\x1e"
	"dev_driver_string\0\0\0"
	"\x2c\x00\x00\x00\xd7\xce\xf8\x53"
	"page_pool_ethtool_stats_get_strings\0"
	"\x24\x00\x00\x00\x97\x70\x48\x65"
	"__x86_indirect_thunk_rax\0\0\0\0"
	"\x1c\x00\x00\x00\x7c\x63\x2b\xfa"
	"ieee80211_find_sta\0\0"
	"\x1c\x00\x00\x00\xe3\x41\xf0\xbb"
	"dma_map_page_attrs\0\0"
	"\x1c\x00\x00\x00\xc1\x2f\x09\x5b"
	"napi_complete_done\0\0"
	"\x20\x00\x00\x00\xf4\x96\x52\x50"
	"ieee80211_get_tx_rates\0\0"
	"\x14\x00\x00\x00\x60\xc0\x2d\x6b"
	"dump_stack\0\0"
	"\x1c\x00\x00\x00\x36\x2b\x4b\x96"
	"ieee80211_send_bar\0\0"
	"\x24\x00\x00\x00\x17\xa9\xb9\xae"
	"ieee80211_get_key_rx_seq\0\0\0\0"
	"\x14\x00\x00\x00\x51\x0e\x00\x01"
	"schedule\0\0\0\0"
	"\x1c\x00\x00\x00\xad\x8a\xdd\x8d"
	"schedule_timeout\0\0\0\0"
	"\x24\x00\x00\x00\xc5\x19\xd5\x03"
	"ieee80211_sta_uapsd_trigger\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x24\x00\x00\x00\x26\xd4\x9e\x64"
	"debugfs_create_devm_seqfile\0"
	"\x20\x00\x00\x00\x6d\xb5\xfc\xb2"
	"queue_delayed_work_on\0\0\0"
	"\x1c\x00\x00\x00\xca\x21\x60\xe4"
	"_raw_spin_unlock_bh\0"
	"\x18\x00\x00\x00\x42\xd8\x71\x89"
	"__napi_schedule\0"
	"\x14\x00\x00\x00\x65\x56\x8c\x4f"
	"__alloc_skb\0"
	"\x18\x00\x00\x00\xa3\x48\x7c\xc5"
	"idr_get_next\0\0\0\0"
	"\x14\x00\x00\x00\xfc\x11\x89\x61"
	"numa_node\0\0\0"
	"\x20\x00\x00\x00\xb3\x2f\xc3\xc0"
	"pci_disable_link_state\0\0"
	"\x10\x00\x00\x00\x49\xb3\xa9\x40"
	"vzalloc\0"
	"\x14\x00\x00\x00\x32\xf3\x31\x94"
	"_dev_info\0\0\0"
	"\x1c\x00\x00\x00\x47\x4e\xee\x06"
	"napi_gro_receive\0\0\0\0"
	"\x2c\x00\x00\x00\xa6\xd7\xf1\x23"
	"page_pool_ethtool_stats_get_count\0\0\0"
	"\x18\x00\x00\x00\x79\x37\x51\x0d"
	"skb_queue_tail\0\0"
	"\x28\x00\x00\x00\xb3\x1c\xa2\x87"
	"__ubsan_handle_out_of_bounds\0\0\0\0"
	"\x28\x00\x00\x00\x44\xd7\x2e\xf6"
	"ieee80211_stop_tx_ba_cb_irqsafe\0"
	"\x1c\x00\x00\x00\x5e\xd7\xd8\x7c"
	"page_offset_base\0\0\0\0"
	"\x24\x00\x00\x00\xf4\xc3\x60\xc0"
	"page_pool_ethtool_stats_get\0"
	"\x18\x00\x00\x00\x3e\x66\x22\x53"
	"acpi_get_handle\0"
	"\x1c\x00\x00\x00\x78\xd6\xdd\x03"
	"dev_set_threaded\0\0\0\0"
	"\x28\x00\x00\x00\xe4\x6f\xb3\xbc"
	"hugetlb_optimize_vmemmap_key\0\0\0\0"
	"\x14\x00\x00\x00\x5b\xa9\x65\x76"
	"idr_remove\0\0"
	"\x20\x00\x00\x00\x6b\x31\x3f\x8c"
	"wiphy_to_ieee80211_hw\0\0\0"
	"\x1c\x00\x00\x00\x97\x5a\xa2\x4a"
	"debugfs_attr_read\0\0\0"
	"\x1c\x00\x00\x00\x44\x7c\xf3\x9c"
	"__iowrite32_copy\0\0\0\0"
	"\x18\x00\x00\x00\x75\x79\x48\xfe"
	"init_wait_entry\0"
	"\x28\x00\x00\x00\xad\x4c\x33\xa3"
	"ieee80211_queue_delayed_work\0\0\0\0"
	"\x18\x00\x00\x00\x04\x80\x85\x32"
	"devm_kmemdup\0\0\0\0"
	"\x14\x00\x00\x00\xb2\xc6\xc7\x57"
	"devm_kfree\0\0"
	"\x14\x00\x00\x00\x35\x1e\x1f\x9c"
	"_dev_err\0\0\0\0"
	"\x14\x00\x00\x00\x29\xdb\x9d\x42"
	"skb_pull\0\0\0\0"
	"\x24\x00\x00\x00\x76\xc8\x64\xff"
	"debugfs_create_file_unsafe\0\0"
	"\x14\x00\x00\x00\x03\x16\xf1\xb8"
	"idr_alloc\0\0\0"
	"\x1c\x00\x00\x00\x27\xf2\x6d\x25"
	"simple_attr_release\0"
	"\x24\x00\x00\x00\x55\x91\xc5\xb8"
	"ieee80211_calc_rx_airtime\0\0\0"
	"\x1c\x00\x00\x00\x0f\x81\x69\x24"
	"__rcu_read_unlock\0\0\0"
	"\x20\x00\x00\x00\x91\x09\x2c\x92"
	"__SCK__tp_func_dev_irq\0\0"
	"\x14\x00\x00\x00\xb8\x83\x8c\xc3"
	"mod_timer\0\0\0"
	"\x28\x00\x00\x00\x6e\xac\xae\x47"
	"ieee80211_find_sta_by_ifaddr\0\0\0\0"
	"\x1c\x00\x00\x00\x4b\xc3\x94\xc4"
	"ieee80211_next_txq\0\0"
	"\x1c\x00\x00\x00\x63\xa5\x03\x4c"
	"random_kmalloc_seed\0"
	"\x1c\x00\x00\x00\x0c\xd2\x03\x8c"
	"destroy_workqueue\0\0\0"
	"\x2c\x00\x00\x00\x65\x7f\xe7\xa4"
	"ieee80211_remain_on_channel_expired\0"
	"\x34\x00\x00\x00\xd3\x6f\xf9\x32"
	"pcie_capability_clear_and_set_word_locked\0\0\0"
	"\x14\x00\x00\x00\x4b\x8d\xfa\x4d"
	"mutex_lock\0\0"
	"\x14\x00\x00\x00\x12\x7e\xf1\x03"
	"skb_push\0\0\0\0"
	"\x14\x00\x00\x00\x62\x14\xff\xfc"
	"napi_enable\0"
	"\x2c\x00\x00\x00\x28\xcc\x68\xe2"
	"ieee80211_beacon_cntdwn_is_complete\0"
	"\x18\x00\x00\x00\xad\x23\x4c\x36"
	"mutex_is_locked\0"
	"\x1c\x00\x00\x00\xac\xb8\x2a\x9d"
	"__tasklet_schedule\0\0"
	"\x24\x00\x00\x00\xe9\xc8\x79\x1a"
	"__x86_indirect_thunk_r13\0\0\0\0"
	"\x20\x00\x00\x00\x67\xc4\x7e\x59"
	"ieee80211_sta_pspoll\0\0\0\0"
	"\x20\x00\x00\x00\x4a\x54\xb0\xe7"
	"ieee80211_wake_queues\0\0\0"
	"\x18\x00\x00\x00\x6b\x77\x01\x38"
	"__ioread32_copy\0"
	"\x14\x00\x00\x00\xb0\x28\x9d\x4c"
	"phys_base\0\0\0"
	"\x28\x00\x00\x00\x0f\xc6\x7b\xe3"
	"ieee80211_beacon_get_template\0\0\0"
	"\x1c\x00\x00\x00\x71\x22\x5a\x5a"
	"__cpu_online_mask\0\0\0"
	"\x10\x00\x00\x00\xa7\xd0\x9a\x44"
	"memcmp\0\0"
	"\x20\x00\x00\x00\xb4\x88\xe1\x61"
	"ieee80211_iter_keys_rcu\0"
	"\x20\x00\x00\x00\x39\xce\x3f\x3c"
	"__local_bh_enable_ip\0\0\0\0"
	"\x18\x00\x00\x00\x23\x1b\xef\x02"
	"kthread_stop\0\0\0\0"
	"\x20\x00\x00\x00\xfb\x04\x48\x16"
	"ieee80211_free_txskb\0\0\0\0"
	"\x24\x00\x00\x00\xb7\xee\x76\x85"
	"led_classdev_register_ext\0\0\0"
	"\x18\x00\x00\x00\x14\x38\x84\xa7"
	"dev_coredumpv\0\0\0"
	"\x18\x00\x00\x00\x9f\x0c\xfb\xce"
	"__mutex_init\0\0\0\0"
	"\x20\x00\x00\x00\x08\x08\x98\x8e"
	"ieee80211_alloc_hw_nm\0\0\0"
	"\x1c\x00\x00\x00\x70\xfc\xbe\x37"
	"jiffies_to_msecs\0\0\0\0"
	"\x24\x00\x00\x00\x70\xce\x5c\xd3"
	"_raw_spin_unlock_irqrestore\0"
	"\x10\x00\x00\x00\xc7\x9a\x08\x11"
	"_ctype\0\0"
	"\x14\x00\x00\x00\xae\xb3\x17\x8e"
	"idr_destroy\0"
	"\x20\x00\x00\x00\x00\xde\xd6\x2b"
	"ieee80211_tx_dequeue\0\0\0\0"
	"\x1c\x00\x00\x00\x78\x99\xad\x3d"
	"cancel_delayed_work\0"
	"\x1c\x00\x00\x00\x4e\xae\x31\x50"
	"ieee80211_rx_list\0\0\0"
	"\x20\x00\x00\x00\xd4\x8c\x3c\xd3"
	"dma_sync_single_for_cpu\0"
	"\x1c\x00\x00\x00\xce\x3b\xff\xa9"
	"page_pool_create\0\0\0\0"
	"\x28\x00\x00\x00\x02\xf4\xed\x6b"
	"ieee80211_freq_khz_to_channel\0\0\0"
	"\x30\x00\x00\x00\x41\xd2\xaa\x61"
	"devm_hwmon_device_register_with_groups\0\0"
	"\x10\x00\x00\x00\xc5\x8f\x57\xfb"
	"memset\0\0"
	"\x24\x00\x00\x00\x2a\x9b\x54\x31"
	"__x86_indirect_thunk_r10\0\0\0\0"
	"\x18\x00\x00\x00\x43\x8f\xb1\x69"
	"rfc1042_header\0\0"
	"\x18\x00\x00\x00\x2d\x70\x1a\xc7"
	"__alloc_pages\0\0\0"
	"\x1c\x00\x00\x00\xca\x39\x82\x5b"
	"__x86_return_thunk\0\0"
	"\x1c\x00\x00\x00\x62\xe1\xd1\xf8"
	"debugfs_create_u32\0\0"
	"\x20\x00\x00\x00\x54\xea\xa5\xd9"
	"__init_waitqueue_head\0\0\0"
	"\x1c\x00\x00\x00\x76\xcb\xb7\xbd"
	"__pskb_pull_tail\0\0\0\0"
	"\x24\x00\x00\x00\xc9\xc2\x04\x48"
	"ieee80211_ready_on_channel\0\0"
	"\x20\x00\x00\x00\xe9\x96\x73\x3f"
	"ieee80211_stop_queues\0\0\0"
	"\x10\x00\x00\x00\xa6\x50\xba\x15"
	"jiffies\0"
	"\x20\x00\x00\x00\xd7\x7b\x33\x1f"
	"kthread_create_on_node\0\0"
	"\x18\x00\x00\x00\x27\x2f\xb2\xdc"
	"devm_kasprintf\0\0"
	"\x20\x00\x00\x00\x78\xbf\x7d\x30"
	"__tracepoint_dev_irq\0\0\0\0"
	"\x20\x00\x00\x00\xf9\x84\xd7\x79"
	"cfg80211_reg_can_beacon\0"
	"\x14\x00\x00\x00\x23\xb3\xd9\xc1"
	"seq_read\0\0\0\0"
	"\x10\x00\x00\x00\xfd\xf9\x3f\x3c"
	"sprintf\0"
	"\x18\x00\x00\x00\x6c\x1e\x65\x97"
	"vmemmap_base\0\0\0\0"
	"\x2c\x00\x00\x00\x61\xe5\x48\xa6"
	"__ubsan_handle_shift_out_of_bounds\0\0"
	"\x1c\x00\x00\x00\x1b\x72\x9a\xea"
	"debugfs_create_file\0"
	"\x18\x00\x00\x00\x52\x0a\xc1\x44"
	"kvfree_call_rcu\0"
	"\x20\x00\x00\x00\xcb\x28\x56\xe4"
	"__SCT__tp_func_dev_irq\0\0"
	"\x28\x00\x00\x00\xf2\xf3\xf6\xbe"
	"ieee80211_sched_scan_results\0\0\0\0"
	"\x24\x00\x00\x00\xc6\x7e\x1e\x52"
	"ieee80211_scan_completed\0\0\0\0"
	"\x34\x00\x00\x00\xdc\xba\x50\x75"
	"ieee80211_iterate_active_interfaces_atomic\0\0"
	"\x18\x00\x00\x00\x38\xf0\x13\x32"
	"mutex_unlock\0\0\0\0"
	"\x24\x00\x00\x00\x4a\x18\xa7\x9f"
	"cancel_delayed_work_sync\0\0\0\0"
	"\x18\x00\x00\x00\x39\x63\xf4\xc6"
	"init_timer_key\0\0"
	"\x18\x00\x00\x00\x3d\x24\x4b\x36"
	"param_ops_bool\0\0"
	"\x18\x00\x00\x00\xd6\xdf\xe3\xea"
	"__const_udelay\0\0"
	"\x20\x00\x00\x00\x6b\xeb\x2d\xd9"
	"acpi_evaluate_object\0\0\0\0"
	"\x20\x00\x00\x00\xa0\xee\x2a\xd7"
	"ieee80211_unregister_hw\0"
	"\x24\x00\x00\x00\xf9\xa4\xcc\x66"
	"__x86_indirect_thunk_rcx\0\0\0\0"
	"\x18\x00\x00\x00\xaa\xe2\x41\x1c"
	"napi_build_skb\0\0"
	"\x14\x00\x00\x00\x23\x90\xbc\x9c"
	"__folio_put\0"
	"\x1c\x00\x00\x00\x91\x5b\x5f\x6d"
	"radix_tree_tagged\0\0\0"
	"\x1c\x00\x00\x00\xfe\x2d\xc1\x03"
	"cancel_work_sync\0\0\0\0"
	"\x18\x00\x00\x00\x18\x01\x47\x56"
	"__warn_printk\0\0\0"
	"\x14\x00\x00\x00\x80\x2b\x0e\xc0"
	"seq_printf\0\0"
	"\x28\x00\x00\x00\x8a\x44\x84\x55"
	"ieee80211_channel_to_freq_khz\0\0\0"
	"\x20\x00\x00\x00\x6a\xdf\xee\xff"
	"delayed_work_timer_fn\0\0\0"
	"\x1c\x00\x00\x00\xfc\x90\x36\x0c"
	"_raw_spin_lock_bh\0\0\0"
	"\x1c\x00\x00\x00\xb3\x51\x73\xc0"
	"__SCT__cond_resched\0"
	"\x14\x00\x00\x00\x4b\x10\xb8\x76"
	"seq_puts\0\0\0\0"
	"\x18\x00\x00\x00\x8c\x92\x66\x8e"
	"single_release\0\0"
	"\x1c\x00\x00\x00\x09\x37\xed\x41"
	"get_random_bytes\0\0\0\0"
	"\x18\x00\x00\x00\x4c\x48\xc3\xd0"
	"kmalloc_trace\0\0\0"
	"\x20\x00\x00\x00\x2a\x5d\xea\xe0"
	"ieee80211_queue_work\0\0\0\0"
	"\x1c\x00\x00\x00\xdf\x1d\xf1\x07"
	"napi_schedule_prep\0\0"
	"\x1c\x00\x00\x00\x65\x45\x42\xf1"
	"napi_consume_skb\0\0\0\0"
	"\x2c\x00\x00\x00\xc6\xfa\xb1\x54"
	"__ubsan_handle_load_invalid_value\0\0\0"
	"\x10\x00\x00\x00\x9c\x53\x4d\x75"
	"strlen\0\0"
	"\x20\x00\x00\x00\xbd\xfc\x79\x18"
	"bridge_tunnel_header\0\0\0\0"
	"\x24\x00\x00\x00\x34\x7d\x06\xe2"
	"ieee80211_sta_ps_transition\0"
	"\x24\x00\x00\x00\x3b\xfa\xd1\x84"
	"dev_kfree_skb_any_reason\0\0\0\0"
	"\x28\x00\x00\x00\xe1\x72\x8e\x68"
	"__SCT__preempt_schedule_notrace\0"
	"\x1c\x00\x00\x00\xcf\xfc\x9d\x80"
	"debugfs_create_u8\0\0\0"
	"\x14\x00\x00\x00\x46\xbe\xb0\x46"
	"single_open\0"
	"\x1c\x00\x00\x00\x72\xa3\x92\x42"
	"debugfs_create_dir\0\0"
	"\x1c\x00\x00\x00\x34\x4b\xb5\xb5"
	"_raw_spin_unlock\0\0\0\0"
	"\x20\x00\x00\x00\x85\x1e\x0a\xf9"
	"__x86_indirect_thunk_r8\0"
	"\x1c\x00\x00\x00\x09\x07\x37\x78"
	"init_dummy_netdev\0\0\0"
	"\x10\x00\x00\x00\xf9\x82\xa4\xf9"
	"msleep\0\0"
	"\x20\x00\x00\x00\x12\xda\xf0\xc4"
	"ktime_get_with_offset\0\0\0"
	"\x20\x00\x00\x00\x63\x76\xd8\x58"
	"ieee80211_disconnect\0\0\0\0"
	"\x14\x00\x00\x00\x45\x3a\x23\xeb"
	"__kmalloc\0\0\0"
	"\x20\x00\x00\x00\x5d\x7b\xc1\xe2"
	"__SCT__might_resched\0\0\0\0"
	"\x18\x00\x00\x00\xc8\x00\xff\x1b"
	"kmalloc_caches\0\0"
	"\x20\x00\x00\x00\x6a\xc1\x95\x61"
	"ieee80211_csa_finish\0\0\0\0"
	"\x24\x00\x00\x00\xa2\x6b\x6b\xb3"
	"page_pool_put_unrefed_page\0\0"
	"\x14\x00\x00\x00\xd3\x85\x33\x2d"
	"system_wq\0\0\0"
	"\x18\x00\x00\x00\x7e\x1c\x9f\x60"
	"synchronize_net\0"
	"\x18\x00\x00\x00\xeb\x7b\x33\xe1"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "mac80211,cfg80211,mt76");


MODULE_INFO(srcversion, "4A8985E29B11B3EC1F75C60");
