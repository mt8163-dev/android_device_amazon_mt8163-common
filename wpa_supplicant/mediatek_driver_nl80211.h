/*
 * Driver interaction with Linux nl80211/cfg80211
 * Copyright (c) 2002-2010, Jouni Malinen <j@w1.fi>
 * Copyright (c) 2003-2004, Instant802 Networks, Inc.
 * Copyright (c) 2005-2006, Devicescape Software, Inc.
 * Copyright (c) 2007, Johannes Berg <johannes@sipsolutions.net>
 * Copyright (c) 2009-2010, Atheros Communications
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 * See README and COPYING for more details.
 */

#ifndef _MTK_DRIVER_NL80211_H_
#define _MTK_DRIVER_NL80211_H_


#ifndef BITS
/* Eddie */
/* bits range: for example BITS(16,23) = 0xFF0000
 *   ==>  (BIT(m)-1)   = 0x0000FFFF     ~(BIT(m)-1)   => 0xFFFF0000
 *   ==>  (BIT(n+1)-1) = 0x00FFFFFF
 */
#define BITS(m,n)                       (~(BIT(m)-1) & ((BIT(n) - 1) | BIT(n)))
#endif /* BIT */


enum nl80211_testmode_sta_link_statistics_attr{
    __NL80211_TESTMODE_STA_STATISTICS_INVALID = 0,
    NL80211_TESTMODE_STA_STATISTICS_VERSION,
    NL80211_TESTMODE_STA_STATISTICS_MAC,
    NL80211_TESTMODE_STA_STATISTICS_LINK_SCORE,
    NL80211_TESTMODE_STA_STATISTICS_FLAG,

    NL80211_TESTMODE_STA_STATISTICS_PER,
    NL80211_TESTMODE_STA_STATISTICS_RSSI,
    NL80211_TESTMODE_STA_STATISTICS_PHY_MODE,
    NL80211_TESTMODE_STA_STATISTICS_TX_RATE,

    NL80211_TESTMODE_STA_STATISTICS_TOTAL_CNT,
    NL80211_TESTMODE_STA_STATISTICS_THRESHOLD_CNT,

    NL80211_TESTMODE_STA_STATISTICS_AVG_PROCESS_TIME,
    NL80211_TESTMODE_STA_STATISTICS_MAX_PROCESS_TIME,
    NL80211_TESTMODE_STA_STATISTICS_AVG_HIF_PROCESS_TIME,
    NL80211_TESTMODE_STA_STATISTICS_MAX_HIF_PROCESS_TIME,


    NL80211_TESTMODE_STA_STATISTICS_FAIL_CNT,
    NL80211_TESTMODE_STA_STATISTICS_TIMEOUT_CNT,
    NL80211_TESTMODE_STA_STATISTICS_AVG_AIR_TIME,

    NL80211_TESTMODE_STA_STATISTICS_TC_EMPTY_CNT_ARRAY,
    NL80211_TESTMODE_STA_STATISTICS_TC_QUE_LEN_ARRAY,

    NL80211_TESTMODE_STA_STATISTICS_TC_AVG_QUE_LEN_ARRAY,
    NL80211_TESTMODE_STA_STATISTICS_TC_CUR_QUE_LEN_ARRAY,

    /*
     * how many packages TX during statistics interval
     */
    NL80211_TESTMODE_STA_STATISTICS_ENQUEUE,

    /*
     * how many packages TX during statistics interval
     */
    NL80211_TESTMODE_STA_STATISTICS_STA_ENQUEUE,

    /*
     * how many packages dequeue during statistics interval
     */
    NL80211_TESTMODE_STA_STATISTICS_DEQUEUE,

    /*
     * how many packages dequeue during statistics interval
     */
    NL80211_TESTMODE_STA_STATISTICS_STA_DEQUEUE,

    /*
     * how many TC[0-3] resource back from firmware during
     * statistics interval
     */
    NL80211_TESTMODE_STA_STATISTICS_RB_ARRAY,
    NL80211_TESTMODE_STA_STATISTICS_NO_TC_ARRAY,
    NL80211_TESTMODE_STA_STATISTICS_TC_USED_ARRAY,
    NL80211_TESTMODE_STA_STATISTICS_TC_WANTED_ARRAY,

    NL80211_TESTMODE_STA_STATISTICS_IRQ_ISR_CNT,
    NL80211_TESTMODE_STA_STATISTICS_IRQ_ISR_PASS_CNT,
    NL80211_TESTMODE_STA_STATISTICS_IRQ_TASK_CNT,
    NL80211_TESTMODE_STA_STATISTICS_IRQ_AB_CNT,
    NL80211_TESTMODE_STA_STATISTICS_IRQ_SW_CNT,
    NL80211_TESTMODE_STA_STATISTICS_IRQ_TX_CNT,
    NL80211_TESTMODE_STA_STATISTICS_IRQ_RX_CNT,

    NL80211_TESTMODE_STA_STATISTICS_RESERVED_ARRAY,

    NL80211_TESTMODE_STA_STATISTICS_NUM,
    NL80211_TESTMODE_STA_STATISTICS_MAX = NL80211_TESTMODE_STA_STATISTICS_NUM - 1
};

enum nl80211_testmode_link_detect_attr{
    NL80211_TESTMODE_LINK_INVALID = 0,
    NL80211_TESTMODE_LINK_TX_FAIL_CNT,
    NL80211_TESTMODE_LINK_TX_RETRY_CNT,
    NL80211_TESTMODE_LINK_TX_MULTI_RETRY_CNT,
    NL80211_TESTMODE_LINK_ACK_FAIL_CNT,
    NL80211_TESTMODE_LINK_FCS_ERR_CNT,
    NL80211_TESTMODE_LINK_TX_OK_CNT,
    NL80211_TESTMODE_LINK_RX_OK_CNT,
    NL80211_TESTMODE_LINK_RST_REASON,
    NL80211_TESTMODE_LINK_RST_TIME,
    NL80211_TESTMODE_LINK_ROAM_FAIL_TIMES,
    NL80211_TESTMODE_LINK_ROAM_FAIL_TIME,
    NL80211_TESTMODE_LINK_TX_DONE_DELAY_IS_ARP,
    NL80211_TESTMODE_LINK_ARRIVE_DRV_TICK,
    NL80211_TESTMODE_LINK_ENQUE_TICK,
    NL80211_TESTMODE_LINK_DEQUE_TICK,
    NL80211_TESTMODE_LINK_LEAVE_DRV_TICK,
    NL80211_TESTMODE_LINK_CURR_TICK,
    NL80211_TESTMODE_LINK_CURR_TIME,
    NL80211_TESTMODE_LINK_DETECT_NUM,
    NL80211_TESTMODE_LINK_DETECT_MAX = NL80211_TESTMODE_LINK_DETECT_NUM - 1
};

#define BUG_REPORT_NUM    47

typedef enum _ENUM_TRAFFIC_CLASS_INDEX_T {
    TC0_INDEX = 0,
    TC1_INDEX,
    TC2_INDEX,
    TC3_INDEX,
    TC_DATA_NUM,
    TC4_INDEX = TC_DATA_NUM,
    TC5_INDEX,
    TC_NUM
} ENUM_TRAFFIC_CLASS_INDEX_T;

struct wpa_driver_sta_statistics_s {
    u8      version;
    u8      addr[ETH_ALEN];
    u32     flag;

    u32     link_score;
    u8      per;
    int     rssi;
    u32     phy_mode;
    double  tx_rate;

    u32     tx_total_cnt;
    u32     enqueue_total_cnt;
    u32     dequeue_total_cnt;
    u32     enqueue_sta_total_cnt;
    u32     dequeue_sta_total_cnt;
    u32     tx_exc_threshold_cnt;

    u32     tx_avg_process_time;
    u32     tx_max_process_time;
    u32     tx_avg_hif_process_time;
    u32     tx_max_hif_process_time;

    u32     tx_fail_cnt;
    u32     tx_timeout_cnt;
    u32     tx_avg_air_time;

    u32     tc_buf_full_cnt[TC_DATA_NUM];
    u32     tc_que_len[TC_DATA_NUM];

    /*
     * how many TC[0-3] resource back from firmware during
     * statistics intervals
     */
    u32     tc_back_count[TC_DATA_NUM];

    /*
     * how many times that no TC[0-3] resource when dequeue
     * statistics intervals
     */
    u32     dequeue_no_tc_res[TC_DATA_NUM];
    u32     tc_wanted_res[TC_DATA_NUM];
    u32     tc_used_res[TC_DATA_NUM];

    /*
     * wlan interrupt info
     * statistics intervals
     */
    u32     isr_cnt;
    u32     isr_pass_cnt;
    u32     isr_task_cnt;
    u32     isr_ab_cnt;
    u32     isr_sw_cnt;
    u32     isr_tx_cnt;
    u32     isr_rx_cnt;

    u32     tc_avg_que_len[TC_DATA_NUM];
    u32     tc_cur_que_len[TC_DATA_NUM];

    u8      reserved[32];
};

struct wpa_driver_sta_link_detect_s {
    u64     tx_fail_cnt;
    u64     tx_retry_cnt;
    u64     tx_multi_retry_cnt;
    u64     ack_fail_cnt;
    u64     fcs_err_cnt;
    u64     tx_ok_cnt;
    u64     rx_ok_cnt;
    u32     rst_reason;
    u64     rst_time;
    u32     roam_fail_times;
    u64     roam_fail_time;
    u8      tx_done_delay_is_arp;
    u32     arrive_drv_tick;
    u32     en_que_tick;
    u32     de_que_tick;
    u32     leave_drv_tick;
    u32     curr_tick;
    u64     curr_time;
    u32     bug_report[BUG_REPORT_NUM];
};

/* SIOCSIWENCODEEXT definitions */
#define IW_ENCODE_ALG_SMS4  0x20

/* P2P Sigma*/
struct wpa_driver_test_mode_info {
    u32  index;
    u32  buflen;
};

struct wpa_driver_testmode_params {
    struct wpa_driver_test_mode_info hdr;
    u8  *buf;
};

struct wpa_driver_get_sta_statistics_params {
    struct wpa_driver_test_mode_info hdr;
    u32 version;
    u32 flag;
    u8  addr[ETH_ALEN];
    u8  *buf;
};

struct wpa_driver_p2p_sigma_params {
    struct wpa_driver_test_mode_info hdr;
    u32 idx;
    u32 value;
};

struct wpa_driver_get_sta_link_detect_params {
    struct wpa_driver_test_mode_info hdr;
    u8  *buf;
};

/* Hotspot Client Management */
struct wpa_driver_hotspot_params {
    struct wpa_driver_test_mode_info hdr;
    u8  blocked;
    u8  bssid[ETH_ALEN];
};

struct wpa_driver_hotspot_set_config_params {
    struct wpa_driver_test_mode_info hdr;
    u32 index;
    u32 value;
};

#ifdef CONFIG_MTK_LTE_COEX
enum nl80211_testmode_available_chan_attr{
    __NL80211_TESTMODE_AVAILABLE_CHAN_ATTR_INVALID,
    NL80211_TESTMODE_AVAILABLE_CHAN_ATTR_2G_BASE_1,
    NL80211_TESTMODE_AVAILABLE_CHAN_ATTR_5G_BASE_36,
    NL80211_TESTMODE_AVAILABLE_CHAN_ATTR_5G_BASE_52,
    NL80211_TESTMODE_AVAILABLE_CHAN_ATTR_5G_BASE_100,
    NL80211_TESTMODE_AVAILABLE_CHAN_ATTR_5G_BASE_149,

    __NL80211_TESTMODE_AVAILABLE_CHAN_ATTR_AFTER_LAST,
    NL80211_TESTMODE_AVAILABLE_CHAN_ATTR_MAX = __NL80211_TESTMODE_AVAILABLE_CHAN_ATTR_AFTER_LAST - 1
};

struct wpa_driver_available_chan_s {
    u32 ch_2g_base1;
    u32 ch_5g_base36;
    u32 ch_5g_base52;
    u32 ch_5g_base100;
    u32 ch_5g_base149;
};

struct wpa_driver_get_available_channel_params {
    struct wpa_driver_test_mode_info hdr;
    u8  *buf;
};
#endif

/* SW CMD */
struct wpa_driver_sw_cmd_params {
    struct wpa_driver_test_mode_info hdr;
    u8  set;
    u32 adr;
    u32 data;
};

struct wpa_driver_suspendmode_params {
    struct wpa_driver_test_mode_info hdr;
    u8  suspend;
};

/* WAPI */
struct iw_encode_exts {
    u32 ext_flags; /* IW_ENCODE_EXT_* */
    u8  tx_seq[IW_ENCODE_SEQ_MAX_SIZE]; /* LSB first */
    u8  rx_seq[IW_ENCODE_SEQ_MAX_SIZE]; /* LSB first */
    u8  addr[ETH_ALEN]; /* ff:ff:ff:ff:ff:ff for broadcast/multicast
			       * (group) keys or unicast address for
			       * individual keys */
    u16 alg; /* IW_ENCODE_ALG_* */
    u16 key_len;
    u8  key[32];
};

struct wpa_driver_rx_filter_params {
    struct wpa_driver_test_mode_info hdr;
    u32 Ipv4FilterHigh;
    u32 Ipv4FilterLow;
    u32 Ipv6FilterHigh;
    u32 Ipv6FilterLow;
    u32 SnapFilterHigh;
    u32 SnapFilterLow;
};

struct wpa_driver_wapi_key_params {
    struct wpa_driver_test_mode_info hdr;
    u8  key_index;
    u8  key_len;
    struct iw_encode_exts extparams;
};

/* CONFIG_MTK_P2P */
struct wpa_driver_wfd_data_s {
    struct wpa_driver_test_mode_info hdr;
    u32 WfdCmdType;
    u8  WfdEnable;
    u8  WfdCoupleSinkStatus;
    u8  WfdSessionAvailable;
    u8  WfdSigmaMode;
    u16 WfdDevInfo;
    u16 WfdControlPort;
    u16 WfdMaximumTp;
    u16 WfdExtendCap;
    u8  WfdCoupleSinkAddress[ETH_ALEN];
    u8  WfdAssociatedBssid[ETH_ALEN];
    u8  WfdVideoIp[4];
    u8  WfdAudioIp[4];
    u16 WfdVideoPort;
    u16 WfdAudioPort;
    u32 WfdFlag;
    u32 WfdPolicy;
    u32 WfdState;
    u8  WfdSessionInformationIE[24*8];  /* Include Subelement ID, length */
    u16 WfdSessionInformationIELen;
    u8  Reverved1[2];
    u8  WfdPrimarySinkMac[ETH_ALEN];
    u8  WfdSecondarySinkMac[ETH_ALEN];
    u32 WfdAdvancedFlag;
    /* Group 1 64 bytes */
    u8  WfdLocalIp[4];
    u16 WfdLifetimeAc2; /* Unit is 2 TU */
    u16 WfdLifetimeAc3; /* Unit is 2 TU */
    u16 WfdCounterThreshold;  /* Unit is ms */
    u8  Reverved2[54];
    /* Group 2 64 bytes */
    u8  Reverved3[64];
    /* Group 3 64 bytes */
    u8  Reverved4[64];
} wfd_data;

struct wpa_driver_set_beamplus_params {
    struct wpa_driver_test_mode_info hdr;
    u32 value;
};

enum nl80211_testmode_params {
    /* Old test mode command id, compatible with exist testmode command */
    NL80211_TESTMODE_SW_CMD = 1,
    NL80211_TESTMODE_WAPI = 2,
    NL80211_TESTMODE_HS20 = 3,
    NL80211_TESTMODE_POORLINK = 4,
    NL80211_TESTMODE_STATISTICS = 0x10,
    NL80211_TESTMODE_LINK_DETECT = 0x20,

    // Hotspot manager testmode command
    NL80211_TESTMODE_HS_SET_CONFIG = 51,

    /* New test mode command id, should greater than TESTMODE_CMD_ID_NEW_BEGIN */
    NL80211_TESTMODE_NEW_BEGIN = 100,
    NL80211_TESTMODE_SUSPEND = 101,
    NL80211_TESTMODE_STR_CMD = 102,
    NL80211_TESTMODE_RXFILTER = 103
};

#endif
