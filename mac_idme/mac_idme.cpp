#define LOG_TAG "mac_idme"

#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>

#include <cutils/log.h>
#include <cutils/properties.h>

#define BT_MAC_PATH   "/proc/idme/bt_mac_addr"
#define WLAN_MAC_PATH "/proc/idme/mac_addr"

#define WLAN_MAC_FILE "/data/vendor/wifi/macwifi"
#define BT_MAC_FILE   "/data/vendor/bluedroid/macbt"

std::string hex_to_mac(std::string hex) {
    std::stringstream ss;

    ss << hex.substr(0, 2);

    for (size_t loc = 2; loc < hex.size(); loc += 2) {
        ss << ':' << hex.substr(loc, 2);
    }

    return ss.str();
}

std::string read_mac(std::string file) {
    std::ifstream idme(file);

    if (!idme.is_open()) {
        ALOGE("Could not open %s!", file.c_str());
        exit(1);
    }

    std::string mac;
    while (std::getline(idme, mac)) {
        if (!mac.empty())
            return hex_to_mac(mac);
    }

    return "00:00:00:00:00:00";
}

void write_mac(std::string file, std::string mac) {
    std::ofstream mac_out(file);

    if(!mac_out.is_open()) {
        ALOGE("Could not open %s", file.c_str());
        exit(1);
    }

    mac_out << mac << std::endl;
    mac_out.close();
}

int main() {
    std::string mac_bt   = read_mac(BT_MAC_PATH);
    std::string mac_wlan = read_mac(WLAN_MAC_PATH);

    ALOGI("Wireless MAC  = %s:xx:xx:xx", mac_wlan.substr(0, 8).c_str());
    ALOGI("Bluetooth MAC = %s:xx:xx:xx", mac_bt.substr(0, 8).c_str());

    ALOGI("Writing wireless MAC to %s", WLAN_MAC_FILE);
    write_mac(WLAN_MAC_FILE, mac_wlan.c_str());
    ALOGI("Success!");

    ALOGI("Writing bluetooth MAC to %s", BT_MAC_FILE);
    write_mac(BT_MAC_FILE, mac_bt.c_str());
    ALOGI("Success!");

    return 0;
}