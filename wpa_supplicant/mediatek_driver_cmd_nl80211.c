/*
 * Driver interaction with extended Linux CFG8021
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 */
#include "includes.h"
#include <linux/wireless.h>
#include "netlink/genl/genl.h"

#include "common.h"
#include "driver_nl80211.h"
#include "linux_ioctl.h"
#include "wpa_supplicant_i.h"
#include "config.h"
#ifdef ANDROID
#include "android_drv.h"
#endif

#include "mediatek_driver_nl80211.h"
#include "driver_i.h"

#include "p2p/p2p_i.h"

#include "eloop.h"
#define PRIV_CMD_SIZE 512

typedef struct android_wifi_priv_cmd {
    char buf[PRIV_CMD_SIZE];
    int used_len;
    int total_len;
} android_wifi_priv_cmd;

static int drv_errors = 0;

static void wpa_driver_send_hang_msg(struct wpa_driver_nl80211_data *drv)
{
    drv_errors++;
    if (drv_errors > DRV_NUMBER_SEQUENTIAL_ERRORS)
        drv_errors = 0;
}

static int testmode_sta_statistics_handler(struct nl_msg *msg, void *arg)
{
    struct nlattr *tb[NL80211_ATTR_MAX + 1] = {};
    struct genlmsghdr *gnlh = nlmsg_data(nlmsg_hdr(msg));
    struct nlattr *sinfo[NL80211_TESTMODE_STA_STATISTICS_NUM] = {};
    struct wpa_driver_sta_statistics_s *sta_statistics = (struct wpa_driver_sta_statistics_s *)arg;
    unsigned char i = 0;
    static struct nla_policy policy[NL80211_TESTMODE_STA_STATISTICS_NUM] = {
        [NL80211_TESTMODE_STA_STATISTICS_VERSION]               = { .type = NLA_U8 },
        [NL80211_TESTMODE_STA_STATISTICS_MAC]                   = { .type = NLA_UNSPEC },
        [NL80211_TESTMODE_STA_STATISTICS_LINK_SCORE]            = { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_FLAG]                  = { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_PER]                   = { .type = NLA_U8 },
        [NL80211_TESTMODE_STA_STATISTICS_RSSI]                  = { .type = NLA_U8 },
        [NL80211_TESTMODE_STA_STATISTICS_PHY_MODE]              = { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_TX_RATE]               = { .type = NLA_U16 },
        [NL80211_TESTMODE_STA_STATISTICS_FAIL_CNT]              = { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_TIMEOUT_CNT]           = { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_AVG_AIR_TIME]          = { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_TOTAL_CNT]             = { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_THRESHOLD_CNT]         = { .type = NLA_U32 },

        [NL80211_TESTMODE_STA_STATISTICS_AVG_PROCESS_TIME]      = { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_MAX_PROCESS_TIME]		= { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_AVG_HIF_PROCESS_TIME]		= { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_MAX_HIF_PROCESS_TIME]		= { .type = NLA_U32 },

        [NL80211_TESTMODE_STA_STATISTICS_TC_EMPTY_CNT_ARRAY]    = { .type = NLA_UNSPEC },
        [NL80211_TESTMODE_STA_STATISTICS_TC_QUE_LEN_ARRAY]      = { .type = NLA_UNSPEC },
        [NL80211_TESTMODE_STA_STATISTICS_TC_AVG_QUE_LEN_ARRAY]  = { .type = NLA_UNSPEC },
        [NL80211_TESTMODE_STA_STATISTICS_TC_CUR_QUE_LEN_ARRAY]  = { .type = NLA_UNSPEC },
        /*
         * how many packages TX during statistics interval
         */
        [NL80211_TESTMODE_STA_STATISTICS_ENQUEUE]		= { .type = NLA_U32 },
        /*
         * how many packages this sta TX during statistics interval
         */
        [NL80211_TESTMODE_STA_STATISTICS_STA_ENQUEUE]		= { .type = NLA_U32 },

        /*
         * how many packages dequeue during statistics interval
         */
        [NL80211_TESTMODE_STA_STATISTICS_DEQUEUE]		= { .type = NLA_U32 },

        /*
         * how many packages this sta dequeue during statistics interval
         */
        [NL80211_TESTMODE_STA_STATISTICS_STA_DEQUEUE]		= { .type = NLA_U32 },

        /*
         * how many TC[0-3] resource back from firmware during
         * statistics interval
         */
        [NL80211_TESTMODE_STA_STATISTICS_RB_ARRAY]		= { .type = NLA_UNSPEC },
        [NL80211_TESTMODE_STA_STATISTICS_NO_TC_ARRAY]		= { .type = NLA_UNSPEC },
        [NL80211_TESTMODE_STA_STATISTICS_TC_USED_ARRAY]		= { .type = NLA_UNSPEC },
        [NL80211_TESTMODE_STA_STATISTICS_TC_WANTED_ARRAY]		= { .type = NLA_UNSPEC },

        [NL80211_TESTMODE_STA_STATISTICS_IRQ_ISR_CNT]		= { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_IRQ_ISR_PASS_CNT]	= { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_IRQ_TASK_CNT]		= { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_IRQ_AB_CNT]		= { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_IRQ_SW_CNT]		= { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_IRQ_TX_CNT]		= { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_IRQ_RX_CNT]		= { .type = NLA_U32 },
        [NL80211_TESTMODE_STA_STATISTICS_RESERVED_ARRAY]        = { .type = NLA_UNSPEC }
    };

    nla_parse(tb, NL80211_ATTR_MAX, genlmsg_attrdata(gnlh, 0),
        genlmsg_attrlen(gnlh, 0), NULL);

    if (!tb[NL80211_ATTR_TESTDATA] ||
        nla_parse_nested(sinfo, NL80211_TESTMODE_STA_STATISTICS_MAX, tb[NL80211_ATTR_TESTDATA], policy))
        return NL_SKIP;

    for (i=1; i < NL80211_TESTMODE_STA_STATISTICS_NUM; i++) {

        if (!sinfo[i])
            continue;

        switch(i) {
        case NL80211_TESTMODE_STA_STATISTICS_VERSION:
            sta_statistics->version = nla_get_u8(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_MAC:
            nla_memcpy(sta_statistics->addr, sinfo[i], ETH_ALEN);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_LINK_SCORE:
            sta_statistics->link_score = nla_get_u32(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_FLAG:
            sta_statistics->flag = nla_get_u32(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_PER:
            sta_statistics->per = nla_get_u8(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_RSSI:
            sta_statistics->rssi = (((int)nla_get_u8(sinfo[i]) - 220) / 2);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_PHY_MODE:
            sta_statistics->phy_mode = nla_get_u32(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_TX_RATE:
            sta_statistics->tx_rate = (((double)nla_get_u16(sinfo[i])) / 2);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_FAIL_CNT:
            sta_statistics->tx_fail_cnt = nla_get_u32(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_TIMEOUT_CNT:
            sta_statistics->tx_timeout_cnt = nla_get_u32(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_AVG_AIR_TIME:
            sta_statistics->tx_avg_air_time = nla_get_u32(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_TOTAL_CNT:
            sta_statistics->tx_total_cnt = nla_get_u32(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_THRESHOLD_CNT:
            sta_statistics->tx_exc_threshold_cnt = nla_get_u32(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_AVG_PROCESS_TIME:
            sta_statistics->tx_avg_process_time = nla_get_u32(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_MAX_PROCESS_TIME:
            sta_statistics->tx_max_process_time = nla_get_u32(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_AVG_HIF_PROCESS_TIME:
            sta_statistics->tx_avg_hif_process_time = nla_get_u32(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_MAX_HIF_PROCESS_TIME:
            sta_statistics->tx_max_hif_process_time = nla_get_u32(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_TC_EMPTY_CNT_ARRAY:
            nla_memcpy(sta_statistics->tc_buf_full_cnt, sinfo[i], sizeof(sta_statistics->tc_buf_full_cnt));
            break;
        case NL80211_TESTMODE_STA_STATISTICS_TC_QUE_LEN_ARRAY:
            nla_memcpy(sta_statistics->tc_que_len, sinfo[i], sizeof(sta_statistics->tc_que_len));
            break;
        case NL80211_TESTMODE_STA_STATISTICS_TC_AVG_QUE_LEN_ARRAY:
            nla_memcpy(sta_statistics->tc_avg_que_len, sinfo[i], sizeof(sta_statistics->tc_avg_que_len));
            break;
        case NL80211_TESTMODE_STA_STATISTICS_TC_CUR_QUE_LEN_ARRAY:
            nla_memcpy(sta_statistics->tc_cur_que_len, sinfo[i], sizeof(sta_statistics->tc_cur_que_len));
            break;

        case NL80211_TESTMODE_STA_STATISTICS_ENQUEUE:
            sta_statistics->enqueue_total_cnt = nla_get_u32(sinfo[i]);
            break;

        case NL80211_TESTMODE_STA_STATISTICS_DEQUEUE:
            sta_statistics->dequeue_total_cnt = nla_get_u32(sinfo[i]);
            break;

        case NL80211_TESTMODE_STA_STATISTICS_STA_ENQUEUE:
            sta_statistics->enqueue_sta_total_cnt = nla_get_u32(sinfo[i]);
            break;

        case NL80211_TESTMODE_STA_STATISTICS_STA_DEQUEUE:
            sta_statistics->dequeue_sta_total_cnt = nla_get_u32(sinfo[i]);
            break;

        case NL80211_TESTMODE_STA_STATISTICS_IRQ_ISR_CNT:
            sta_statistics->isr_cnt = nla_get_u32(sinfo[i]);
            break;

        case NL80211_TESTMODE_STA_STATISTICS_IRQ_ISR_PASS_CNT:
            sta_statistics->isr_pass_cnt = nla_get_u32(sinfo[i]);
            break;
        case NL80211_TESTMODE_STA_STATISTICS_IRQ_TASK_CNT:
            sta_statistics->isr_task_cnt = nla_get_u32(sinfo[i]);
            break;

        case NL80211_TESTMODE_STA_STATISTICS_IRQ_AB_CNT:
            sta_statistics->isr_ab_cnt = nla_get_u32(sinfo[i]);
            break;

        case NL80211_TESTMODE_STA_STATISTICS_IRQ_SW_CNT:
            sta_statistics->isr_sw_cnt = nla_get_u32(sinfo[i]);
            break;

        case NL80211_TESTMODE_STA_STATISTICS_IRQ_TX_CNT:
            sta_statistics->isr_tx_cnt = nla_get_u32(sinfo[i]);
            break;

        case NL80211_TESTMODE_STA_STATISTICS_IRQ_RX_CNT:
            sta_statistics->isr_rx_cnt = nla_get_u32(sinfo[i]);
            break;

        case NL80211_TESTMODE_STA_STATISTICS_NO_TC_ARRAY:
            nla_memcpy(sta_statistics->dequeue_no_tc_res, sinfo[i],
                      sizeof(sta_statistics->dequeue_no_tc_res));
            break;

        case NL80211_TESTMODE_STA_STATISTICS_TC_USED_ARRAY:
            nla_memcpy(sta_statistics->tc_used_res, sinfo[i],
                      sizeof(sta_statistics->tc_used_res));
            break;
        case NL80211_TESTMODE_STA_STATISTICS_TC_WANTED_ARRAY:
            nla_memcpy(sta_statistics->tc_wanted_res, sinfo[i],
                      sizeof(sta_statistics->tc_wanted_res));
            break;

        case NL80211_TESTMODE_STA_STATISTICS_RB_ARRAY:
            nla_memcpy(sta_statistics->tc_back_count, sinfo[i],
                      sizeof(sta_statistics->tc_back_count));
            break;

        case NL80211_TESTMODE_STA_STATISTICS_RESERVED_ARRAY:
             nla_memcpy(sta_statistics->reserved, sinfo[i], sizeof(sta_statistics->reserved));
             break;
        default:
            break;
        }
    }

    return NL_SKIP;
}

static int wpa_driver_nl80211_testmode(void *priv, const u8 *data, size_t data_len)
{
    struct i802_bss *bss = priv;
    struct wpa_driver_nl80211_data *drv = bss->drv;
    struct nl_msg *msg;
    struct wpa_driver_testmode_params *params;
    int index;

    msg = nlmsg_alloc();
    if (!msg)
        return -1;

    wpa_printf(MSG_DEBUG, "nl80211 test mode: ifindex=%d", drv->ifindex);

    nl80211_cmd(drv, msg, 0, NL80211_CMD_TESTMODE);

    NLA_PUT_U32(msg, NL80211_ATTR_IFINDEX, drv->ifindex);
    NLA_PUT(msg, NL80211_ATTR_TESTDATA, data_len, data);

    params = (struct wpa_driver_testmode_params *)data;

    /* Mask version field */
    index = params->hdr.index & BITS(0, 23);

    switch(index) {
        case 0x10:
        {
            struct wpa_driver_get_sta_statistics_params *sta_params =
                           (struct wpa_driver_get_sta_statistics_params *)data;
            return send_and_recv_msgs(drv, msg, testmode_sta_statistics_handler, sta_params->buf);
        }
        default:
        {
            int ret = send_and_recv_msgs(drv, msg, NULL, NULL);
            wpa_printf(MSG_EXCESSIVE, "ret=%d, nl=%p", ret, drv->global->nl);
            return ret;
        }
    }

nla_put_failure:
    nlmsg_free(msg);
    return -ENOBUFS;
}

static int wpa_driver_nl80211_driver_sw_cmd(void *priv, int set, u32 *adr, u32 *dat)
{
    struct wpa_driver_sw_cmd_params params;

    os_memset(&params, 0, sizeof(params));

    params.hdr.index = NL80211_TESTMODE_SW_CMD;
    params.hdr.index = params.hdr.index | (0x01 << 24);
    params.hdr.buflen = sizeof(struct wpa_driver_sw_cmd_params);

    params.adr = *adr;
    params.data = *dat;

    if (set)
        params.set = 1;
    else
        params.set = 0;

    wpa_driver_nl80211_testmode(priv, (u8 *)&params, sizeof(struct wpa_driver_sw_cmd_params));
    return 0;
}

/**********************************************************************
* OVERLAPPED functins, previous defination is in driver_nl80211.c,
* it will be modified
***********************************************************************/

/**********************************************************************/
extern int wpa_config_write(const char *name, struct wpa_config *config);

static int wpa_driver_mediatek_set_country(void *priv, const char *alpha2_arg)
{
    struct i802_bss *bss = priv;
    struct wpa_driver_nl80211_data *drv = bss->drv;
    int ioctl_sock = -1;
    struct iwreq iwr;
    int ret = -1;
    char buf[11];

    ioctl_sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (ioctl_sock < 0) {
        wpa_printf(MSG_ERROR, "%s: socket(PF_INET,SOCK_DGRAM)", __func__);
        return -1;
    }
    os_memset(&iwr, 0, sizeof(iwr));
    os_strlcpy(iwr.ifr_name, drv->first_bss->ifname, IFNAMSIZ);

    snprintf(buf, sizeof(buf), "COUNTRY %s", alpha2_arg);
    iwr.u.data.pointer = buf;
    iwr.u.data.length = strlen(buf);
    if ((ret = ioctl(ioctl_sock, 0x8B0C, &iwr)) < 0) {  // SIOCSIWPRIV
        wpa_printf(MSG_DEBUG, "ioctl[SIOCSIWPRIV]: %s", buf);
        close(ioctl_sock);
        return ret;
    }
    else {
        close(ioctl_sock);
        return 0;
    }

}

/*
* update channel list in wpa_supplicant
* if coutry code chanaged
*/
static void wpa_driver_notify_country_change(struct wpa_global *global, char *cmd)
{
    struct wpa_supplicant *wpa_s;

    if (os_strncasecmp(cmd, "COUNTRY", 7) == 0) {
        union wpa_event_data event;

        os_memset(&event, 0, sizeof(event));
        event.channel_list_changed.initiator = REGDOM_SET_BY_USER;
        if (os_strncasecmp(cmd, "COUNTRY", 7) == 0) {
            event.channel_list_changed.type = REGDOM_TYPE_COUNTRY;
            if (os_strlen(cmd) > 9) {
                event.channel_list_changed.alpha2[0] = cmd[8];
                event.channel_list_changed.alpha2[1] = cmd[9];
            }
        } else {
            event.channel_list_changed.type = REGDOM_TYPE_UNKNOWN;
        }
        // Notify all interfaces
        for (wpa_s = global->ifaces; wpa_s; wpa_s = wpa_s->next) {
            wpa_supplicant_event(wpa_s, EVENT_CHANNEL_LIST_CHANGED, &event);
        }
    }
}

/**
 * mtk_p2p_get_device - Fetch a peer entry
 * @p2p: P2P module context from p2p_init()
 * @addr: P2P Device Address of the peer
 * Returns: Pointer to the device entry or %NULL if not found
 */
struct p2p_device *mtk_p2p_get_device(struct p2p_data *p2p, const u8 *addr)
{
    struct p2p_device *dev;

    dl_list_for_each(dev, &p2p->devices, struct p2p_device, list) {
        if (memcmp(dev->info.p2p_device_addr, addr, ETH_ALEN) == 0)
            return dev;
    }
    return NULL;
}
/*
 * we should use interface MAC address
 * instead of device MAC when query
 * STA statistics, as driver uses interface addr
 * to do TX/RX
 * In most cases, the interface addr and device addr
 * should be the same
 */
u8 *wpas_p2p_get_sta_mac(struct wpa_supplicant *wpa_s, u8 *org_addr)
{
    struct p2p_data *p2p = wpa_s->global->p2p;
    struct wpa_ssid *ssid = wpa_s->current_ssid;
    struct p2p_device *dev = NULL;
    int is_p2p_client = 0;

    if (!p2p) {
        wpa_printf(MSG_DEBUG, "interface %s not support p2p", wpa_s->ifname);
        return NULL;
    }

    if (!ssid) {
        wpa_printf(MSG_DEBUG, "P2P: ssid not connected");
        return NULL;
    }

    dev = mtk_p2p_get_device(p2p, org_addr);

    if (!dev) {
        wpa_printf(MSG_DEBUG, "P2P: device " MACSTR "not found",
                   MAC2STR(org_addr));
        return NULL;
    }

    is_p2p_client = ssid->mode == WPAS_MODE_INFRA ? 1 : 0;

    if (is_p2p_client) {
        if (memcmp(dev->info.p2p_device_addr, wpa_s->bssid, ETH_ALEN) &&
            !is_zero_ether_addr(wpa_s->bssid)) {
            wpa_printf(MSG_DEBUG, "P2P: we are GC, Use interface_addr "
                        MACSTR "instead of " MACSTR,
                        MAC2STR(wpa_s->bssid),
                        MAC2STR(org_addr));
            return wpa_s->bssid;
        }
    }

    /*
     * we are GO, interface_addr should be filled
     * when RX NL80211_CMD_NEW_STA event
     * if it is defferent between device addr and interface addr
     */
    if (memcmp(dev->info.p2p_device_addr, dev->interface_addr, ETH_ALEN) &&
        !is_zero_ether_addr(dev->interface_addr)) {
        wpa_printf(MSG_DEBUG, "P2P: we are GO, Use interface_addr " MACSTR
                 "instead of " MACSTR,
                 MAC2STR(dev->interface_addr),
                 MAC2STR(org_addr));
        return dev->interface_addr;
    }
    return NULL;
}

/* Move GET_STA_STATISTICS to "DRIVER GET_STA_STATISTICS", implement in 3rd part lib */
/* [ALPS00618361] [WFD Quality Enhancement] */
int wpas_get_sta_statistics(struct wpa_supplicant *wpa_s, u8 *sta_addr, u8 *buf)
{
    struct wpa_driver_get_sta_statistics_params params;

    os_memset(&params, 0, sizeof(params));

    if(sta_addr)
        os_memcpy(params.addr, sta_addr, ETH_ALEN);

    wpa_printf(MSG_DEBUG, "get_sta_statistics ["MACSTR"]", MAC2STR(params.addr));

    params.hdr.index = NL80211_TESTMODE_STATISTICS;
    params.hdr.index = params.hdr.index | (0x01 << 24);
    params.hdr.buflen = sizeof(struct wpa_driver_get_sta_statistics_params);

    /* buffer for return structure */
    params.buf = buf;

    return wpa_driver_nl80211_testmode(wpa_s->drv_priv, (u8 *)&params,
        sizeof(struct wpa_driver_get_sta_statistics_params));
}

/*  [ALPS00618361] [WFD Quality Enhancement] [changelist 1686130] */
static int print_sta_statistics(struct wpa_supplicant *wpa_s, struct wpa_driver_sta_statistics_s *sta_stats,
              unsigned long mask, char *buf, size_t buflen)
{
    size_t i;
    int ret;
    char *pos, *end;

    pos = buf;
    end = buf + buflen;

    ret = os_snprintf(pos, end - pos, "sta_addr="MACSTR"\n", MAC2STR(sta_stats->addr));
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "link_score=%d\n", sta_stats->link_score);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "per=%d\n", sta_stats->per);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "rssi=%d\n", sta_stats->rssi);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "phy=0x%08X\n", sta_stats->phy_mode);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "rate=%.1f\n", sta_stats->tx_rate);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "total_cnt=%d\n", sta_stats->tx_total_cnt);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "threshold_cnt=%d\n", sta_stats->tx_exc_threshold_cnt);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "fail_cnt=%d\n", sta_stats->tx_fail_cnt);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "timeout_cnt=%d\n", sta_stats->tx_timeout_cnt);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "apt=%d\n", sta_stats->tx_avg_process_time);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "aat=%d\n", sta_stats->tx_avg_air_time);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "TC_buf_full_cnt=%d:%d:%d:%d\n",
                      sta_stats->tc_buf_full_cnt[TC0_INDEX],
                      sta_stats->tc_buf_full_cnt[TC1_INDEX],
                      sta_stats->tc_buf_full_cnt[TC2_INDEX],
                      sta_stats->tc_buf_full_cnt[TC3_INDEX]);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "TC_sta_que_len=%d:%d:%d:%d\n",
                      sta_stats->tc_que_len[TC0_INDEX],
                      sta_stats->tc_que_len[TC1_INDEX],
                      sta_stats->tc_que_len[TC2_INDEX],
                      sta_stats->tc_que_len[TC3_INDEX]);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "TC_avg_que_len=%d:%d:%d:%d\n",
                      sta_stats->tc_avg_que_len[TC0_INDEX],
                      sta_stats->tc_avg_que_len[TC1_INDEX],
                      sta_stats->tc_avg_que_len[TC2_INDEX],
                      sta_stats->tc_avg_que_len[TC3_INDEX]);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "TC_cur_que_len=%d:%d:%d:%d\n",
                      sta_stats->tc_cur_que_len[TC0_INDEX],
                      sta_stats->tc_cur_que_len[TC1_INDEX],
                      sta_stats->tc_cur_que_len[TC2_INDEX],
                      sta_stats->tc_cur_que_len[TC3_INDEX]);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "flag=0x%08X\n", sta_stats->flag);
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "reserved0=");
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;
    for (i = 0; i < 16; i++) {
        ret = os_snprintf(pos, end - pos, "%02X", sta_stats->reserved[i]);
        if (ret < 0 || ret >= end - pos)
            return 0;
        pos += ret;

        if (((i + 1) % 4) == 0) {
            ret = os_snprintf(pos, end - pos, " ");
            if (ret < 0 || ret >= end - pos)
                return 0;
            pos += ret;
        }
    }
    ret = os_snprintf(pos, end - pos, "\n");
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "reserved1=");
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;
    for (i = 16; i < 32; i++) {
        ret = os_snprintf(pos, end - pos, "%02X", sta_stats->reserved[i]);
        if (ret < 0 || ret >= end - pos)
            return 0;
        pos += ret;

        if (((i + 1) % 4) == 0) {
            ret = os_snprintf(pos, end - pos, " ");
            if (ret < 0 || ret >= end - pos)
                return 0;
            pos += ret;
        }
    }
    ret = os_snprintf(pos, end - pos, "\n");
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    ret = os_snprintf(pos, end - pos, "====\n");
    if (ret < 0 || ret >= end - pos)
        return 0;
    pos += ret;

    return pos - buf;
}

/*  [ALPS00618361] [WFD Quality Enhancement] [changelist 1686130] */
static void format_sta_statistics(struct wpa_driver_sta_statistics_s *s)
{
	wpa_printf(MSG_DEBUG, "NWFD: Basic info* AVG:%4d:EN:%4d:DE:%4d:SEN:%4d:SDE:%4d:HIF:%4d",
		s->tx_avg_process_time,
		s->enqueue_total_cnt,
		s->dequeue_total_cnt,
		s->enqueue_sta_total_cnt,
		s->dequeue_sta_total_cnt,
		s->tx_total_cnt);

	wpa_printf(MSG_DEBUG, "NWFD: Time info* TTL:%4d:AVG:%4d:MAX:%4d:HIFAVG:%4d:HIFMAX:%4d",
		s->tx_total_cnt,
		s->tx_avg_process_time,
		s->tx_max_process_time,
		s->tx_avg_hif_process_time,
		s->tx_max_hif_process_time);

	wpa_printf(MSG_DEBUG, "NWFD: No TC RES* Score:%4d:EN:%4d#%4d#%4d#%4d:DE:%4d#%4d#%4d#%4d",
		s->link_score,
		s->tc_buf_full_cnt[TC0_INDEX],
		s->tc_buf_full_cnt[TC1_INDEX],
		s->tc_buf_full_cnt[TC2_INDEX],
		s->tc_buf_full_cnt[TC3_INDEX],
		s->dequeue_no_tc_res[TC0_INDEX],
		s->dequeue_no_tc_res[TC1_INDEX],
		s->dequeue_no_tc_res[TC2_INDEX],
		s->dequeue_no_tc_res[TC3_INDEX]);

	wpa_printf(MSG_DEBUG, "NWFD: Irq info* T:%4d:P:%4d:TT:%4d:A:%4d:S:%4d:R:%4d:T:%4d",
		s->isr_cnt,
		s->isr_pass_cnt,
		s->isr_task_cnt,
		s->isr_ab_cnt,
		s->isr_sw_cnt,
		s->isr_rx_cnt,
		s->isr_tx_cnt);

	/*
	 * TC resouce information: format:
	 * 1. how many TC resource wanted during statistics intervals
	 * 2. how many TC resource acquire successfully
	 * 3. how many TC resource back during statistics intervals
	 */
	wpa_printf(MSG_DEBUG, "NWFD: TC Res info[W:U:B]* Score:%4d:"
		"#%5d:%5d:%5d#"
		"#%5d:%5d:%5d#"
		"#%5d:%5d:%5d#"
		"#%5d:%5d:%5d#",
		s->link_score,
		s->tc_wanted_res[TC0_INDEX],
		s->tc_used_res[TC0_INDEX],
		s->tc_back_count[TC0_INDEX],

		s->tc_wanted_res[TC1_INDEX],
		s->tc_used_res[TC1_INDEX],
		s->tc_back_count[TC1_INDEX],

		s->tc_wanted_res[TC2_INDEX],
		s->tc_used_res[TC2_INDEX],
		s->tc_back_count[TC2_INDEX],

		s->tc_wanted_res[TC3_INDEX],
		s->tc_used_res[TC3_INDEX],
		s->tc_back_count[TC3_INDEX]);
}

int wpa_driver_get_sta_statistics(struct wpa_supplicant *wpa_s, char *addr,
                                char *buf, size_t buflen)
{
    int len = 0;
    u8 sta_addr[ETH_ALEN];
    u8 *mac = NULL;
    struct wpa_driver_sta_statistics_s sta_statistics;

    memset(&sta_statistics, 0 ,sizeof(sta_statistics));

    if (hwaddr_aton(addr, sta_addr)) {
        wpa_printf(MSG_DEBUG, "CTRL_IFACE GET_STA_STATISTICS: invalid "
                   "address '%s'", addr);
        return -1;
    }

    mac = wpas_p2p_get_sta_mac(wpa_s, sta_addr);

    if (wpas_get_sta_statistics(wpa_s, mac ? mac : sta_addr,
        (u8 *)&sta_statistics) < 0) {
        wpa_printf(MSG_DEBUG, "CTRL_IFACE GET_STA_STATISTICS: command failed");
        return -1;
    }
    len = print_sta_statistics(wpa_s, &sta_statistics, 0x00, buf, buflen);

    format_sta_statistics(&sta_statistics);
    return len;
}

/* utils for parse cmdline:
 * cmd: paramters in cmd line
 * argv: paramter vector
 * len: cmd lenght
 * example:
 * cmd = "driver P2P_SET_NOA 1 2 3"
 * argv[0] = "driver"
 * argv[1] = "P2P_SET_NOA"
 * argv[2] = "1"
 * argv[3] = "2"
 * argv[4] = "3"
 */

int tokenize_space(char *cmd, char *argv[], int len)
{
    char *pos;
    char *start;
    int argc = 0;

    start = pos = cmd;
    for (;;) {
        argv[argc] = pos;
        argc++;
        while (*pos != '\n' && *pos != ' ' && *pos != '\0') {
            pos++;
            if (pos - start >= len)
                break;
        }

        if (*pos == '\0')
            break;

        if (*pos == '\n' || *pos == ' ') {
            *pos++ = '\0';
            if (pos - start >= len)
                break;
        }
    }

    return argc;
}

static int p2p_ctrl_iface_set_noa(struct wpa_supplicant *wpa_s, char *cmd, char *buf, size_t buflen)
{
    struct wpa_driver_p2p_noa_params {
        struct wpa_driver_test_mode_info hdr;
        u32 idx;
        u32 value; /* should not be used in this case */
        u32 count;
        u32 interval;
        u32 duration;
    };
    char *argv[64] = { 0 };
    int argc;
    struct wpa_driver_p2p_noa_params noa_param;

    os_memset(&noa_param, 0, sizeof(noa_param));

    /* P2P_SET_NOA 255 100 3 */
    /*
     * argv format:
     * argv[0] = "P2P_SET_NOA"
     * argv[1] = "255"
     * argv[2] = "100"
     * argv[3] = "3"
     */
    argc = tokenize_space(cmd, argv, os_strlen(cmd));

    if (argc != 4) {
        wpa_printf(MSG_DEBUG, "P2P: NOA: invalid cmd format");
        return -1;
    }

    /* fill in the params structure */
    noa_param.hdr.index = 1;
    noa_param.hdr.index = noa_param.hdr.index | (0x01 << 24);
    noa_param.hdr.buflen = sizeof(struct wpa_driver_p2p_noa_params);

    noa_param.idx = 4;
    noa_param.count = (u32)atoi(argv[1]);
    noa_param.interval= (u32)atoi(argv[2]);
    noa_param.duration= (u32)atoi(argv[3]);

    wpa_printf(MSG_DEBUG, "P2P: set noa: %d %d %d",
               noa_param.count,
               noa_param.interval,
               noa_param.duration);

    return wpa_driver_nl80211_testmode(wpa_s->drv_priv, (u8 *)&noa_param,
                  sizeof(struct wpa_driver_p2p_noa_params));
}

static int p2p_ctrl_iface_set_ps(struct wpa_supplicant *wpa_s, char *cmd, char *buf, size_t buflen)
{
    char *argv[64] = { 0 };
    int argc;
    int enable;
    s32 ctw;
    struct wpa_driver_p2p_sigma_params opps_param;

    os_memset(&opps_param, 0, sizeof(opps_param));

    /* P2P_SET_PS 2 1 3
     * argv format:
     * argv[0] = "P2P_SET_PS"
     * argv[1] = "2"
     * argv[2] = "1"
     * argv[3] = "3"
     */
    argc = tokenize_space(cmd, argv, os_strlen(cmd));

    if (argc != 4) {
        wpa_printf(MSG_DEBUG, "P2P: Opps: invalid cmd format");
        return -1;
    }

    /* fill in the params structure */
    opps_param.hdr.index = 1;
    opps_param.hdr.index = opps_param.hdr.index | (0x01 << 24);
    opps_param.hdr.buflen = sizeof(struct wpa_driver_p2p_sigma_params);

    opps_param.idx = 107;

    enable = atoi(argv[2]);
    ctw = atoi(argv[3]);

    /* BIT 7 control OPPS on / off */
    if (enable)
        ctw |= BIT(7);

    opps_param.value = ctw;

    wpa_printf(MSG_DEBUG, "P2P: set opps: 0x%x",
               opps_param.value);

    return wpa_driver_nl80211_testmode(wpa_s->drv_priv, (u8 *)&opps_param,
             sizeof(struct wpa_driver_p2p_sigma_params));
}

int wpa_driver_nl80211_driver_cmd(void *priv, char *cmd, char *buf,
                  size_t buf_len )
{
    struct i802_bss *bss = priv;
    struct wpa_driver_nl80211_data *drv = bss->drv;
    struct ifreq ifr;
    android_wifi_priv_cmd priv_cmd;
    struct wpa_supplicant *wpa_s;
    struct hostapd_data *hapd;
    int handled = 0;
    int cmd_len = 0;
    int ret = -1;

    if (drv == NULL) {
        wpa_printf(MSG_ERROR, "%s: drv is NULL, exit", __func__);
        return -1;
    }
    if (drv->ctx == NULL) {
        wpa_printf(MSG_ERROR, "%s: drv->ctx is NULL, exit", __func__);
        return -1;
    }

    if (bss->drv->nlmode == NL80211_IFTYPE_AP) {
        hapd = (struct hostapd_data *)(drv->ctx);
    }
    else {
        wpa_s = (struct wpa_supplicant *)(drv->ctx);
        if (wpa_s->conf == NULL) {
            wpa_printf(MSG_ERROR, "%s: wpa_s->conf is NULL, exit", __func__);
            return -1;
        }
    }

    wpa_printf(MSG_INFO, "%s: %s recv cmd %s", __func__, bss->ifname, cmd);
    handled = 1;

    if (os_strncasecmp(cmd, "POWERMODE ", 10) == 0) {
        int state;
        state = atoi(cmd + 10);
        wpa_printf(MSG_DEBUG, "POWERMODE=%d", state);
    }  else if (os_strncasecmp(cmd, "GET_STA_STATISTICS ", 19) == 0) {
        ret = wpa_driver_get_sta_statistics(wpa_s, cmd + 19, buf, buf_len);
    }  else if (os_strncmp(cmd, "MACADDR", os_strlen("MACADDR")) == 0) {
        u8 macaddr[ETH_ALEN] = {};
        os_memcpy(&macaddr, wpa_s->own_addr, ETH_ALEN);
        ret = snprintf(buf, buf_len, "Macaddr = " MACSTR "\n", MAC2STR(macaddr));
        wpa_printf(MSG_DEBUG, "%s", buf);
    } else if(os_strncasecmp(cmd, "COUNTRY", os_strlen("COUNTRY")) == 0) {
        if (os_strlen(cmd) != os_strlen("COUNTRY") + 3) {
            wpa_printf(MSG_DEBUG, "Ignore COUNTRY cmd %s", cmd);
            ret = 0;
        } else {
            wpa_printf(MSG_INFO, "Set country: %s", cmd + 8);
            // ret = wpa_drv_set_country(wpa_s, cmd + 8);
            ret = wpa_driver_mediatek_set_country(priv, cmd + 8);
            if (ret == 0) {
                wpa_printf(MSG_DEBUG, "Update channel list after country code changed");
                wpa_driver_notify_country_change(wpa_s->global, cmd);
            }
        }
    } else if (os_strcasecmp(cmd, "start") == 0) {
        if ((ret = linux_set_iface_flags(drv->global->ioctl_sock,
            drv->first_bss->ifname, 1))) {
            wpa_printf(MSG_INFO, "nl80211: Could not set interface UP, ret=%d \n", ret);
        } else {
            wpa_msg(drv->ctx, MSG_INFO, "CTRL-EVENT-DRIVER-STATE STARTED");
        }
    } else if (os_strcasecmp(cmd, "stop") == 0) {
        if (drv->associated) {
            ret = wpa_drv_deauthenticate(wpa_s, drv->bssid, WLAN_REASON_DEAUTH_LEAVING);
            if (ret != 0)
                wpa_printf(MSG_DEBUG, "DRIVER-STOP error, ret=%d", ret);
        } else {
            wpa_printf(MSG_INFO, "nl80211: not associated, no need to deauthenticate \n");
        }

        if ((ret = linux_set_iface_flags(drv->global->ioctl_sock,
            drv->first_bss->ifname, 0))) {
            wpa_printf(MSG_INFO, "nl80211: Could not set interface Down, ret=%d \n", ret);
        } else {
            wpa_msg(drv->ctx, MSG_INFO, "CTRL-EVENT-DRIVER-STATE STOPPED");
        }
    } else if (os_strncasecmp(cmd, "getpower", 8) == 0) {
        u32 mode = 0;
        // ret = wpa_driver_wext_driver_get_power(drv, &mode);
        if (ret == 0) {
            ret = snprintf(buf, buf_len, "powermode = %u\n", mode);
            wpa_printf(MSG_DEBUG, "%s", buf);
            if (ret < (int)buf_len)
                return ret;
        }
    } else if (os_strncasecmp(cmd, "rxfilter-add", 12) == 0) {
        u32 sw_cmd = 0x9F000000;
        u32 idx = 0;
        char *cp = cmd + 12;
        char *endp;

        if (*cp != '\0') {
            idx = (u32)strtol(cp, &endp, 0);
            if (endp != cp) {
                idx += 0x00900200;
                wpa_driver_nl80211_driver_sw_cmd(priv, 1, &sw_cmd, &idx);
                ret = 0;
            }
        }
    } else if (os_strncasecmp(cmd, "rxfilter-remove", 15) == 0) {
        u32 sw_cmd = 0x9F000000;
        u32 idx = 0;
        char *cp = cmd + 15;
        char *endp;

        if (*cp != '\0') {
            idx = (u32)strtol(cp, &endp, 0);
            if (endp != cp) {
                idx += 0x00900300;
                wpa_driver_nl80211_driver_sw_cmd(priv, 1, &sw_cmd, &idx);
                ret = 0;
            }
        }
    } else if (os_strncasecmp(cmd, "rxfilter-stop", 13) == 0) {
        u32 sw_cmd = 0x9F000000;
        u32 idx = 0x00900000;
        wpa_driver_nl80211_driver_sw_cmd(priv, 1, &sw_cmd, &idx);
        ret = 0;
    } else if (os_strncasecmp(cmd, "rxfilter-start", 14) == 0) {
        u32 sw_cmd = 0x9F000000;
        u32 idx = 0x00900100;
        wpa_driver_nl80211_driver_sw_cmd(priv, 1, &sw_cmd, &idx);
        ret = 0;
    } else if (os_strcasecmp(cmd, "btcoexscan-start") == 0) {
        ret = 0; /* mt5921 linux driver not implement yet */
    } else if (os_strcasecmp(cmd, "btcoexscan-stop") == 0) {
        ret = 0; /* mt5921 linux driver not implement yet */
    } else if (os_strncasecmp(cmd, "btcoexmode", 10) == 0) {
        ret = 0; /* mt5921 linux driver not implement yet */
    } else if (os_strncmp(cmd, "P2P_SET_NOA", os_strlen("P2P_SET_NOA")) == 0) {
        ret = p2p_ctrl_iface_set_noa(wpa_s, cmd, buf, buf_len);
    } else if (os_strncmp(cmd, "P2P_SET_PS", os_strlen("P2P_SET_PS")) == 0) {
        ret = p2p_ctrl_iface_set_ps(wpa_s, cmd, buf, buf_len);
    } else if (os_strncasecmp(cmd, "SETSUSPENDMODE ", 15) == 0) {
        struct wpa_driver_suspendmode_params params;
        params.hdr.index = NL80211_TESTMODE_SUSPEND;
        params.hdr.index = params.hdr.index | (0x01 << 24);
        params.hdr.buflen = sizeof(params);
        params.suspend = *(cmd+15)-'0';
        wpa_driver_nl80211_testmode(priv, (u8* )&params, sizeof(params));
        handled = 0; /* 6630 driver handled this command in driver, so give a chance to 6630 driver */
    }else if(os_strncasecmp(cmd, "mtk_rx_packet_filter ", 21) == 0) {
        char buf[9] = {0}, *errChar = NULL;
        char *pos = NULL;
        /* mtk_rx_packet_filter 00000000000000FE 0000000000000000 0000000000000000 */
        struct wpa_driver_rx_filter_params params;
        params.hdr.index = NL80211_TESTMODE_RXFILTER;
        params.hdr.index = params.hdr.index | (0x01 << 24);
        params.hdr.buflen = sizeof(params);

        pos = cmd;
        pos = pos + 21;
        if (pos == NULL || strlen(cmd) != 71 ) {
            wpa_printf(MSG_DEBUG, "[mtk_rx_packet_filter] Error! \n");
            return -1;
        }

        os_memcpy(buf,pos,8);
        buf[8] = '\0';
        params.Ipv4FilterHigh = strtol(buf,&errChar,16);
        wpa_printf(MSG_DEBUG, "[mtk_rx_packet_filter]params.Ipv4FilterHigh (0x%08x),errChar [%p]\n", params.Ipv4FilterHigh,errChar);

        pos = pos + 8;
        os_memcpy(buf,pos,8);
        buf[8] = '\0';
        params.Ipv4FilterLow = strtol(buf,&errChar,16);
        wpa_printf(MSG_DEBUG, "[mtk_rx_packet_filter]params.Ipv4FilterLow (0x%08x),errChar [%p]\n", params.Ipv4FilterLow,errChar);

        pos = pos + 9;
        os_memcpy(buf,pos,8);
        buf[8] = '\0';
        params.Ipv6FilterHigh = strtol(buf,&errChar,16);
        wpa_printf(MSG_DEBUG, "[mtk_rx_packet_filter]params.Ipv6FilterHigh (0x%08x),errChar [%p]\n", params.Ipv6FilterHigh,errChar);

        pos = pos + 8;
        os_memcpy(buf,pos,8);
        buf[8] = '\0';
        params.Ipv6FilterLow = strtol(buf,&errChar,16);
        wpa_printf(MSG_DEBUG, "[mtk_rx_packet_filter]params.Ipv6FilterLow (0x%08x),errChar [%p]\n", params.Ipv6FilterLow,errChar);

        pos = pos + 9;
        os_memcpy(buf,pos,8);
        buf[8] = '\0';
        params.SnapFilterHigh = strtol(buf,&errChar,16);
        wpa_printf(MSG_DEBUG, "[mtk_rx_packet_filter]params.SnapFilterHigh (0x%08x),errChar [%p]\n", params.SnapFilterHigh,errChar);

        pos = pos + 8;
        os_memcpy(buf,pos,8);
        buf[8] = '\0';
        params.SnapFilterLow = strtol(buf,&errChar,16);
        wpa_printf(MSG_DEBUG, "[mtk_rx_packet_filter]params.SnapFilterLow (0x%08x),errChar [%p]\n", params.SnapFilterLow,errChar);

        ret = wpa_driver_nl80211_testmode(priv, (u8 *)&params, sizeof(params));
    } else {
        u8 buffer[100];
        struct wpa_driver_test_mode_info *params = (struct wpa_driver_test_mode_info *)buffer;
        params->index = NL80211_TESTMODE_STR_CMD | (0x01 << 24);
        params->buflen = sizeof(*params) + strlen(cmd);
        strncpy((char*)(params+1), cmd, sizeof(buffer)-sizeof(*params));
        ret = wpa_driver_nl80211_testmode(priv, buffer, params->buflen);
        handled = 0;
        wpa_printf(MSG_INFO, "Transparent command for driver nl80211, ret=%d", ret);
    }

    if (handled == 0) {
        cmd_len = strlen(cmd);

        memset(&ifr, 0, sizeof(ifr));
        memset(&priv_cmd, 0, sizeof(priv_cmd));
        memset(buf, 0, buf_len);
        strncpy(ifr.ifr_name, bss->ifname, IFNAMSIZ);
        ifr.ifr_name[IFNAMSIZ - 1] = '\0';

        if (cmd_len >= PRIV_CMD_SIZE) {
            wpa_printf(MSG_INFO, "%s: cmd: %s overflow",
                      __func__, cmd);
            cmd_len = PRIV_CMD_SIZE - 1;
        }

        memcpy(priv_cmd.buf, cmd, cmd_len + 1);
        priv_cmd.used_len = cmd_len + 1;
        priv_cmd.total_len = PRIV_CMD_SIZE;
        ifr.ifr_data = &priv_cmd;

        ret = ioctl(drv->global->ioctl_sock, SIOCDEVPRIVATE + 1, &ifr);
        if (ret < 0) {
            wpa_printf(MSG_ERROR, "%s: failed to issue private commands,"
                    " error msg: %s\n", __func__, strerror(errno));
            wpa_driver_send_hang_msg(drv);
            ret = snprintf(buf, buf_len, "%s\n", "FAIL");
        } else {

            wpa_printf(MSG_INFO, "%s: ret = %d used = %u total = %u",
                    __func__, ret , priv_cmd.used_len, priv_cmd.total_len);

            drv_errors = 0;
            ret = 0;
            if ((os_strncasecmp(cmd, "WLS_BATCHING", 12) == 0))
                ret = strlen(buf);
            /*
	     * There no need to call wpa_supplicant_event func
	     * on which the cmd is SETBAND
	     */
            if (os_strncasecmp(cmd, "SETBAND", 7) == 0) {
                /*
                 * wpa_supplicant_event(drv->ctx,
                 * 		EVENT_CHANNEL_LIST_CHANGED, NULL);
                 */
                wpa_printf(MSG_INFO, "%s: Unsupported command SETBAND\n", __func__);
            }
        }
    } /* handled == 0 */

    return ret;
}

int wpa_driver_set_p2p_noa(void *priv, u8 count, int start, int duration)
{
    char buf[MAX_DRV_CMD_SIZE];
    struct i802_bss *bss = priv;

    wpa_printf(MSG_DEBUG, "iface %s P2P_SET_NOA %d %d %d", bss->ifname, count, start, duration);
    snprintf(buf, sizeof(buf), "P2P_SET_NOA %d %d %d", count, start, duration);
    return wpa_driver_nl80211_driver_cmd(priv, buf, buf, strlen(buf)+1);
}

int wpa_driver_get_p2p_noa(void *priv, u8 *buf, size_t len)
{
    struct i802_bss *bss = priv;

    wpa_printf(MSG_DEBUG, "iface %s P2P_GET_NOA, ignored", bss->ifname);
    return -1;
}

int wpa_driver_set_p2p_ps(void *priv, int legacy_ps, int opp_ps, int ctwindow)
{
    char buf[MAX_DRV_CMD_SIZE];
    struct i802_bss *bss = priv;

    wpa_printf(MSG_DEBUG, "iface %s P2P_SET_PS %d %d %d", bss->ifname, legacy_ps, opp_ps, ctwindow);
    snprintf(buf, sizeof(buf), "P2P_SET_PS %d %d %d", legacy_ps, opp_ps, ctwindow);
    return wpa_driver_nl80211_driver_cmd(priv, buf, buf, strlen(buf)+1);
}

int wpa_driver_set_ap_wps_p2p_ie(void *priv, const struct wpabuf *beacon,
                 const struct wpabuf *proberesp,
                 const struct wpabuf *assocresp)
{
    struct i802_bss *bss = priv;

    wpa_printf(MSG_DEBUG, "iface %s set_ap_wps_p2p_ie, ignored", bss->ifname);
    return 0;
}
