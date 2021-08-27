
#include <stdint.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netlink/genl/genl.h>
#include <netlink/genl/family.h>
#include <netlink/genl/ctrl.h>
#include <linux/rtnetlink.h>
#include <netpacket/packet.h>
#include <linux/filter.h>
#include <linux/errqueue.h>

#include <linux/pkt_sched.h>
#include <netlink/object-api.h>
#include <netlink/netlink.h>
#include <netlink/socket.h>
#include <netlink/handlers.h>

#include "sync.h"

#define LOG_TAG  "WifiHAL"

#include <utils/Log.h>

#include "wifi_hal.h"
#include "common.h"
#include "cpp_bindings.h"


typedef enum {
    LSTATS_SUBCMD_GET_INFO = ANDROID_NL80211_SUBCMD_LSTATS_RANGE_START,
} LSTATS_SUB_COMMAND;

typedef enum {
    LSTATS_ATTRIBUTE_STATS = 2,
} LSTATS_ATTRIBUTE;

///////////////////////////////////////////////////////////////////////////////////
class GetLinkStatsCommand : public WifiCommand
{
    wifi_stats_result_handler mHandler;
public:
    GetLinkStatsCommand(wifi_interface_handle iface, wifi_stats_result_handler handler)
        : WifiCommand(iface, 0), mHandler(handler)
    { }

    virtual int create() {
        ALOGD("[WIFI HAL]Creating message to get link statistics; iface = %d", mIfaceInfo->id);

        int ret = mMsg.create(GOOGLE_OUI, LSTATS_SUBCMD_GET_INFO);
        if (ret < 0) {
            ALOGE("Failed to create %x - %d", LSTATS_SUBCMD_GET_INFO, ret);
            return ret;
        }

        return ret;
    }

protected:
    virtual int handleResponse(WifiEvent& reply) {
        ALOGD("[WIFI HAL]In GetLinkStatsCommand::handleResponse");

        if (reply.get_cmd() != NL80211_CMD_VENDOR) {
            ALOGE("Ignoring reply with cmd = %d", reply.get_cmd());
            return NL_SKIP;
        }

        int id = reply.get_vendor_id();
        int subcmd = reply.get_vendor_subcmd();

        // ALOGI("Id = %0x, subcmd = %d", id, subcmd);

        struct nlattr *vendor_data = (struct nlattr *)reply.get_vendor_data();
        int len = reply.get_vendor_data_len();
        wifi_radio_stat *data;

        if(vendor_data->nla_type == LSTATS_ATTRIBUTE_STATS)
            data = (wifi_radio_stat *)nla_data(vendor_data);
        else
            return NL_SKIP;
        int num_chan = data->num_channels;
        if (num_chan > 32) {
           ALOGE("Incorrect number of channels = %d", num_chan);
           return NL_SKIP;
        }

/*
        (*mHandler.on_link_stats_results)(id,
            (wifi_iface_stat *)((char *)&(data)->channels
            + num_chan*sizeof(wifi_channel_stat)),
            1, data);
*/

        return NL_OK;
    }
};

wifi_error wifi_get_link_stats(wifi_request_id id,
        wifi_interface_handle iface, wifi_stats_result_handler handler)
{
#if 0
    GetLinkStatsCommand command(iface, handler);
    return (wifi_error) command.requestResponse();
#else
    ALOGD("[WIFI HAL]don't support wifi_get_link_stats");
    return WIFI_ERROR_NOT_SUPPORTED;
#endif
}

