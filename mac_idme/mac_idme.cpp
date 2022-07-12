#define LOG_TAG "mac_idme"

#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>

#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>

#include <android-base/logging.h>
#include <android-base/properties.h>

#include <sys/types.h>
#include <unistd.h>

#include <sys/stat.h>

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
        LOG(ERROR) << "Could not open " << file << "!";
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
        LOG(ERROR) << "Could not open " << file << "!";
        exit(1);
    }

    mac_out << mac.substr(0, mac.size() - 1) << std::endl;
    mac_out.close();
}

int main() {
    std::string mac_bt   = read_mac(BT_MAC_PATH);
    std::string mac_wlan = read_mac(WLAN_MAC_PATH);

    LOG(INFO) << "Wireless  MAC  = " << mac_wlan.substr(0, 8).c_str() << ":xx:xx:xx";
    LOG(INFO) << "Bluetooth MAC  = " << mac_bt.substr(0, 8).c_str() << ":xx:xx:xx";

    LOG(INFO) << "Writing wireless MAC to " << WLAN_MAC_FILE;
    write_mac(WLAN_MAC_FILE, mac_wlan.c_str());
    chmod(WLAN_MAC_FILE, 0644);
    chown(WLAN_MAC_FILE, 1000, 1010);
    LOG(INFO) << "Success!";

    LOG(INFO) << "Writing bluetooth MAC to " << BT_MAC_FILE;
    write_mac(BT_MAC_FILE, mac_bt.c_str());
    chmod(BT_MAC_FILE, 0644);
    chown(BT_MAC_FILE, 1000, 1002);
    LOG(INFO) << "Success!";

    if (android::base::GetProperty("ro.bt.bdaddr_path", "") != BT_MAC_FILE)
        android::base::SetProperty("ro.bt.bdaddr_path", BT_MAC_FILE);

    return 0;
}
