// SPDX-License-Identifier: ISC
/* Copyright (C) 2023 MediaTek Inc. */

#include <linux/module.h>
#include <linux/pci.h>

#include "mt7902.h"
#include "mcu.h"
#include "../../include/compat.h"

static int
mt7902_mcu_send_message(struct mt7902_mt76_dev *mdev, struct sk_buff *skb,
			int cmd, int *seq)
{
	struct mt7902_mt792x_dev *dev = container_of(mdev, struct mt7902_mt792x_dev, mt76);
	enum mt7902_mt76_mcuq_id txq = MT_MCUQ_WM;
	int ret;

	ret = mt7902_mcu_fill_message(mdev, skb, cmd, seq);
	if (ret)
		return ret;

	mdev->mcu.timeout = 3 * HZ * MT7902_MCU_TIMEOUT_MULTIPLIER;

	if (cmd == MCU_CMD(FW_SCATTER))
		txq = MT_MCUQ_FWDL;

	return mt7902_mt76_tx_queue_skb_raw(dev, mdev->q_mcu[txq], skb, 0);
}

int mt7902e_mcu_init(struct mt7902_mt792x_dev *dev)
{
	static const struct mt7902_mt76_mcu_ops mt7902_mcu_ops = {
		.headroom = sizeof(struct mt7902_mt76_connac2_mcu_txd),
		.mcu_skb_send_msg = mt7902_mcu_send_message,
		.mcu_parse_response = mt7902_mcu_parse_response,
	};
	int err;

	dev->mt76.mcu_ops = &mt7902_mcu_ops;

	err = mt7902_mt792xe_mcu_fw_pmctrl(dev);
	if (err)
		return err;

	err = __mt7902_mt792xe_mcu_drv_pmctrl(dev);
	if (err)
		return err;

	mt7902_mt76_rmw_field(dev, MT_PCIE_MAC_PM, MT_PCIE_MAC_PM_L0S_DIS, 1);

	err = mt7902_run_firmware(dev);

	mt7902_mt76_queue_tx_cleanup(dev, dev->mt76.q_mcu[MT_MCUQ_FWDL], false);

	return err;
}
