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

#include "mediatek_driver_nl80211.h"
#include "wpa_supplicant_i.h"
#include "config.h"
#include "driver_i.h"

#ifdef ANDROID
#include "android_drv.h"
#endif

/*int send_and_recv_msgs(struct wpa_driver_nl80211_data *drv, struct nl_msg *msg,
		       int (*valid_handler)(struct nl_msg *, void *),
		       void *valid_data);*/

static int testmode_sta_statistics_handler(struct nl_msg *msg, void *arg)
{
    struct nlattr *tb[NL80211_ATTR_MAX + 1];
    struct genlmsghdr *gnlh = nlmsg_data(nlmsg_hdr(msg));
    struct nlattr *sinfo[NL80211_TESTMODE_STA_STATISTICS_NUM];
    struct wpa_driver_sta_statistics_s *sta_statistics = (struct wpa_driver_sta_statistics_s *)arg;
    unsigned char i = 0;
    static struct nla_policy policy[NL80211_TESTMODE_STA_STATISTICS_NUM] = {
    	[NL80211_TESTMODE_STA_STATISTICS_VERSION] 			    = { .type = NLA_U8 },
    	[NL80211_TESTMODE_STA_STATISTICS_MAC] 		            = { .type = NLA_UNSPEC },
    	[NL80211_TESTMODE_STA_STATISTICS_LINK_SCORE] 		    = { .type = NLA_U8 },
    	[NL80211_TESTMODE_STA_STATISTICS_FLAG] 	                = { .type = NLA_U32 },    	
    	[NL80211_TESTMODE_STA_STATISTICS_PER] 				    = { .type = NLA_U8 },
    	[NL80211_TESTMODE_STA_STATISTICS_RSSI] 			        = { .type = NLA_U8 },
    	[NL80211_TESTMODE_STA_STATISTICS_PHY_MODE] 		        = { .type = NLA_U32 },
    	[NL80211_TESTMODE_STA_STATISTICS_TX_RATE] 		        = { .type = NLA_U16 },
    	[NL80211_TESTMODE_STA_STATISTICS_FAIL_CNT] 	            = { .type = NLA_U32 },
    	[NL80211_TESTMODE_STA_STATISTICS_TIMEOUT_CNT] 	        = { .type = NLA_U32 },
    	[NL80211_TESTMODE_STA_STATISTICS_AVG_AIR_TIME] 		    = { .type = NLA_U32 },
    	[NL80211_TESTMODE_STA_STATISTICS_TOTAL_CNT] 	        = { .type = NLA_U32 },
    	[NL80211_TESTMODE_STA_STATISTICS_THRESHOLD_CNT] 	    = { .type = NLA_U32 },
    	[NL80211_TESTMODE_STA_STATISTICS_AVG_PROCESS_TIME] 	    = { .type = NLA_U32 },
    	[NL80211_TESTMODE_STA_STATISTICS_TC_EMPTY_CNT_ARRAY]    = { .type = NLA_UNSPEC },
    	[NL80211_TESTMODE_STA_STATISTICS_TC_QUE_LEN_ARRAY]      = { .type = NLA_UNSPEC },   	
    	[NL80211_TESTMODE_STA_STATISTICS_TC_AVG_QUE_LEN_ARRAY]  = { .type = NLA_UNSPEC },   
    	[NL80211_TESTMODE_STA_STATISTICS_TC_CUR_QUE_LEN_ARRAY] 	= { .type = NLA_UNSPEC },
    	[NL80211_TESTMODE_STA_STATISTICS_RESERVED_ARRAY]        = { .type = NLA_UNSPEC }
    };

    nla_parse(tb, NL80211_ATTR_MAX, genlmsg_attrdata(gnlh, 0),
    	  genlmsg_attrlen(gnlh, 0), NULL);
    
    if (!tb[NL80211_ATTR_TESTDATA] || 
            nla_parse_nested(sinfo, NL80211_TESTMODE_STA_STATISTICS_MAX, tb[NL80211_ATTR_TESTDATA], policy))
    	return NL_SKIP;

    for(i=1; i < NL80211_TESTMODE_STA_STATISTICS_NUM; i++) {
        if(sinfo[i]) { 		
            switch(i) {
            	case NL80211_TESTMODE_STA_STATISTICS_VERSION:
                    sta_statistics->version = nla_get_u8(sinfo[i]);
                    break;
            	case NL80211_TESTMODE_STA_STATISTICS_MAC:
                    nla_memcpy(sta_statistics->addr, sinfo[i], ETH_ALEN);
                    break;
            	case NL80211_TESTMODE_STA_STATISTICS_LINK_SCORE:
                    sta_statistics->link_score = nla_get_u8(sinfo[i]);
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
            	case NL80211_TESTMODE_STA_STATISTICS_RESERVED_ARRAY:
                    nla_memcpy(sta_statistics->reserved, sinfo[i], sizeof(sta_statistics->reserved));
                    break;              
                default:
                    break;
            }
        }
    }
    
    return NL_SKIP;
}

static void * nl80211_cmd(struct wpa_driver_nl80211_data *drv,
			  struct nl_msg *msg, int flags, uint8_t cmd)
{
	return genlmsg_put(msg, 0, 0, drv->global->nl80211_id,
			   0, flags, cmd, 0);
}

static int wpa_driver_nl80211_testmode(void *priv, const u8 *data,
	                               size_t data_len)
{
	struct i802_bss *bss = priv;
	struct wpa_driver_nl80211_data *drv = bss->drv;
	struct nl_msg *msg, *cqm = NULL;
    struct wpa_driver_testmode_params *params;
    int index;

	msg = nlmsg_alloc();
	if (!msg)
		return -1;

	wpa_printf(MSG_DEBUG, "nl80211: Test Mode buflen = %d", data_len);

    nl80211_cmd(drv, msg, 0, NL80211_CMD_TESTMODE);

	NLA_PUT_U32(msg, NL80211_ATTR_IFINDEX, drv->ifindex);
	NLA_PUT(msg, NL80211_ATTR_TESTDATA, data_len, data);

    params = (struct wpa_driver_testmode_params *)data;

    /* Mask version field */
    index = params->hdr.index & BITS(0, 23);

    switch(index) {
        case 0x10:
            {
                struct wpa_driver_get_sta_statistics_params *sta_params = data;
            
    		    return 0;// send_and_recv_msgs(drv, msg, testmode_sta_statistics_handler, sta_params->buf);            
            }
        default:
            return 0;// send_and_recv_msgs(drv, msg, NULL, NULL);
    }
    
 nla_put_failure:
	return -ENOBUFS;

}

static int wpa_driver_nl80211_driver_sw_cmd(void *priv,
    int set, unsigned long *adr, unsigned long *dat)
{
    struct i802_bss *bss = priv;
    struct wpa_driver_nl80211_data *drv = bss->drv;
    struct wpa_driver_sw_cmd_params params;
    struct nl_msg *msg, *cqm = NULL;
    int ret = 0;
    
    os_memset(&params, 0, sizeof(params));
    
    params.hdr.index = 1;
    params.hdr.index = params.hdr.index | (0x01 << 24);
    params.hdr.buflen = sizeof(struct wpa_driver_sw_cmd_params);
    
    params.adr = *adr;
    params.data = *dat;

    if(set)
        params.set = 1;
    else
        params.set = 0;
	
    wpa_driver_nl80211_testmode(priv, (u8 *)&params, sizeof(struct wpa_driver_sw_cmd_params));
    return 0;
}

/*************************************************************
OVERLAPPED functins, previous defination is in driver_nl80211.c,
it will be modified
**************************************************************/

/**************************************************************************/
extern int wpa_config_write(const char *name, struct wpa_config *config);

static int wpa_driver_mediatek_set_country(void *priv, const char *alpha2_arg)
{
	struct i802_bss *bss = priv;
	struct wpa_driver_nl80211_data *drv = bss->drv;
	int ioctl_sock=-1;
	struct iwreq iwr;
	int ret=-1;
	char buf[11];

	wpa_printf(MSG_DEBUG, "wpa_driver_nl80211_set_country");
	ioctl_sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (ioctl_sock < 0) {
		wpa_printf(MSG_ERROR, "%s: socket(PF_INET,SOCK_DGRAM)", __func__);
		return -1;
	}
	os_memset(&iwr, 0, sizeof(iwr));
	os_strncpy(iwr.ifr_name, drv->first_bss.ifname, IFNAMSIZ);
	sprintf(buf,"COUNTRY %s",alpha2_arg);
	iwr.u.data.pointer = buf;
	iwr.u.data.length = strlen(buf);
	if ((ret = ioctl(ioctl_sock, 0x8B0C, &iwr)) < 0) {//SIOCSIWPRIV
		wpa_printf(MSG_DEBUG, "ioctl[SIOCSIWPRIV]: %s",buf);
		close(ioctl_sock);
		return ret;
	}
	else {
		close(ioctl_sock);
		return 0;
	}

}

extern const struct wpa_driver_ops wpa_driver_nl80211_ops;
int wpa_driver_nl80211_driver_cmd(void *priv, char *cmd, char *buf,
				  size_t buf_len )
{
	struct i802_bss *bss = priv;
	struct wpa_driver_nl80211_data *drv = bss->drv;
	struct wpa_supplicant *wpa_s;
	int ret = -1;

	if (drv == NULL) {
		wpa_printf(MSG_ERROR, "%s: drv is NULL. Exiting", __func__);
		return -1;
	}
	if (drv->ctx == NULL) {
		wpa_printf(MSG_ERROR, "%s: drv->ctx is NULL. Exiting", __func__);
		return -1;
	}
	wpa_s = (struct wpa_supplicant *)(drv->ctx);
	if (wpa_s->conf == NULL) {
		wpa_printf(MSG_ERROR, "%s: wpa_s->conf is NULL. Exiting", __func__);
		return -1;
	}

	wpa_printf(MSG_DEBUG, "iface %s recv  cmd %s ignored", bss->ifname, cmd);

	if (os_strncasecmp(cmd, "POWERMODE ", 10) == 0) {
		int state;
		state = atoi(cmd + 10);
		wpa_printf(MSG_DEBUG, "POWERMODE=%d", state);
	}  else if (os_strncmp(cmd, "MACADDR", os_strlen("MACADDR"))==0) {
		u8 macaddr[ETH_ALEN] = {};
        os_memcpy(&macaddr, wpa_s->own_addr, ETH_ALEN);
        ret = snprintf(buf, buf_len, "Macaddr = " MACSTR "\n", MAC2STR(macaddr));
        wpa_printf(MSG_DEBUG, "%s", buf);
    } else if(os_strncasecmp(cmd, "COUNTRY", os_strlen("COUNTRY"))==0) {
        wpa_printf(MSG_DEBUG, "set country: %s", cmd+8);
        //ret = wpa_drv_set_country(wpa_s, cmd+8);
        if(ret == 0) {
            //os_memcpy(wpa_s->conf->country,cmd+8,2);
            //ret = wpa_config_write(wpa_s->confname, wpa_s->conf);
        }
		wpa_printf(MSG_DEBUG, "skip cmd %s", cmd);
    } else if (os_strcasecmp(cmd, "start") == 0) {
        wpa_printf(MSG_DEBUG,"skip cmd %s", cmd);
    } else if (os_strcasecmp(cmd, "stop") == 0) {
// [Android4.3] remove disassociate function 
//       ret = wpa_driver_nl80211_ops.disassociate(bss, drv->bssid, WLAN_REASON_DEAUTH_LEAVING);
        //ret = wpa_driver_wext_driver_start(drv, 1);
        if (ret == 0)
            wpa_msg(drv->ctx, MSG_INFO, "CTRL-EVENT-DRIVER-STATE STOPPED");
        wpa_printf(MSG_DEBUG,"DRIVER-STOP: %d", ret);
		if (linux_set_iface_flags(drv->global->ioctl_sock, 
                                       drv->first_bss.ifname, 0)) {
			wpa_printf(MSG_INFO, "nl80211: Could not set interface Down \n");
		}
    } else if (os_strncasecmp(cmd, "getpower", 8) == 0) {
        u32 mode;
//        ret = wpa_driver_wext_driver_get_power(drv, &mode);
        if (ret == 0) {
            ret = snprintf(buf, buf_len, "powermode = %u\n", mode);
            wpa_printf(MSG_DEBUG, "%s", buf);
            if (ret < (int)buf_len) {
                return( ret );
            }
        }
    } else if (os_strncasecmp(cmd, "get-rts-threshold", 17) == 0) {
        u32 thd;
//        ret = wpa_driver_wext_driver_get_rts(drv, &thd);
        if (ret == 0) {
            ret = snprintf(buf, buf_len, "rts-threshold = %u\n", thd);
            wpa_printf(MSG_DEBUG, "%s", buf);
            if (ret < (int)buf_len)
                return ret;
        }
    } else if (os_strncasecmp(cmd, "set-rts-threshold", 17) == 0) {
        u32 thd = 0;
        char *cp = cmd + 17;
        char *endp;
        if (*cp != '\0') {
            thd = (u32)strtol(cp, &endp, 0);
//            if (endp != cp)
//                ret = wpa_driver_wext_driver_set_rts(drv, thd);
        }
	} else if (os_strncasecmp(cmd, "rxfilter-add", 12) == 0 ) {
		unsigned long sw_cmd = 0x9F000000;
		unsigned long idx = 0;
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
	} else if (os_strncasecmp(cmd, "rxfilter-remove", 15) == 0 ) {
		unsigned long sw_cmd = 0x9F000000;
		unsigned long idx = 0;
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
	} else if (os_strncasecmp(cmd, "rxfilter-stop", 13) == 0 ) {
		unsigned long sw_cmd = 0x9F000000;
		unsigned long idx = 0x00900000;
		wpa_driver_nl80211_driver_sw_cmd(priv, 1, &sw_cmd, &idx);
		ret = 0;
	} else if (os_strncasecmp(cmd, "rxfilter-start", 14) == 0 ) {
		unsigned long sw_cmd = 0x9F000000;
		unsigned long idx = 0x00900100;
		wpa_driver_nl80211_driver_sw_cmd(priv, 1, &sw_cmd, &idx);
		ret = 0;
    } else if (os_strcasecmp(cmd, "btcoexscan-start") == 0) {
        ret = 0; /* mt5921 linux driver not implement yet */
    } else if (os_strcasecmp(cmd, "btcoexscan-stop") == 0) {
        ret = 0; /* mt5921 linux driver not implement yet */
    } else if( os_strncasecmp(cmd, "btcoexmode", 10) == 0 ) {
        ret = 0; /* mt5921 linux driver not implement yet */
    } else if (os_strncasecmp(cmd, "smt-rate", 8) == 0 ) {
        unsigned long sw_cmd = 0xFFFF0123;
        unsigned long idx = 0;
        char *cp = cmd + 8;
        char *endp;

        if (*cp != '\0') {
            idx = (u32)strtol(cp, &endp, 0);
            if (endp != cp) {
                wpa_driver_nl80211_driver_sw_cmd(priv, 1, &sw_cmd, &idx);
                ret = 0;
            }
        }
    } else if (os_strncasecmp(cmd, "smt-test-on", 11) == 0 ) {
        unsigned long sw_cmd = 0xFFFF1234;
        unsigned long idx = 0;
        wpa_driver_nl80211_driver_sw_cmd(priv, 1, &sw_cmd, &idx);
        ret = 0;
    } else if (os_strncasecmp(cmd, "smt-test-off", 12) == 0 ) {
        unsigned long sw_cmd = 0xFFFF1235;
        unsigned long idx = 0;
        wpa_driver_nl80211_driver_sw_cmd(priv, 1, &sw_cmd, &idx);
        ret = 0;
    } else {
        wpa_printf(MSG_DEBUG,"Unsupported command");
    }

    return ret;
}

int wpa_driver_set_p2p_noa(void *priv, u8 count, int start, int duration)
{
	struct i802_bss *bss = priv;
	struct wpa_driver_nl80211_data *drv = bss->drv;

	wpa_printf(MSG_DEBUG, "iface %s P2P_SET_NOA %d %d %d, ignored", bss->ifname, count, start, duration); 
	return -1;
}

int wpa_driver_get_p2p_noa(void *priv, u8 *buf, size_t len)
{
	struct i802_bss *bss = priv;
	struct wpa_driver_nl80211_data *drv = bss->drv;

	wpa_printf(MSG_DEBUG, "iface %s P2P_GET_NOA, ignored"); 
	return -1;
}

int wpa_driver_set_p2p_ps(void *priv, int legacy_ps, int opp_ps, int ctwindow)
{
	struct i802_bss *bss = priv;
	struct wpa_driver_nl80211_data *drv = bss->drv;

	wpa_printf(MSG_DEBUG, "iface %s P2P_SET_PS, ignored"); 
	return -1;
}

int wpa_driver_set_ap_wps_p2p_ie(void *priv, const struct wpabuf *beacon,
				 const struct wpabuf *proberesp,
				 const struct wpabuf *assocresp)
{
	struct i802_bss *bss = priv;
	struct wpa_driver_nl80211_data *drv = bss->drv;

	wpa_printf(MSG_DEBUG, "iface %s set_ap_wps_p2p_ie, ignored"); 
	return -1;
}
