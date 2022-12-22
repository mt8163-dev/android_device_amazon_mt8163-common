#include <fcntl.h>
#include <dlfcn.h>
#include <string>
#include <iostream>

#define LOG_TAG "AlsaWrapper"
#include <android-base/logging.h>
#include <android-base/file.h>

#include <alsa.h>
#include <sound/asound.h>
#include <tinyalsa/asoundlib.h>

#define EXT_SPEAKER_SWITCH_CTRL_ID 	6
#define EXT_HP_SWITCH_CTRL_ID 		7

#define H2W_PATH "/sys/class/switch/h2w/state"

int get_headset_state() {
    std::string state;
    if (!android::base::ReadFileToString(H2W_PATH, &state)) {
        LOG(ERROR) << "Failed to read headset state!";
        abort();
    }
    return std::stoi(state);
}

extern "C" int mixer_ctl_set_enum_by_string(struct mixer_ctl *ctl, const char *string) {
    static auto mixer_ctl_set_enum_by_string_real =
            reinterpret_cast<mixer_ctl_set_enum_by_string_t>(dlsym(RTLD_NEXT, "mixer_ctl_set_enum_by_string"));

    if (!mixer_ctl_set_enum_by_string_real) {
        LOG(ERROR) << "Failed to find original mixer_ctl_set_enum_by_string!";
        abort();
    }

    LOG(INFO) << "mixer_ctl_set_enum_by_string: " << string;
    if (ctl->info->id.numid == EXT_SPEAKER_SWITCH_CTRL_ID) {
        if (strcmp(string, "On") == 0) {
            if (get_headset_state() > 0) {
                LOG(INFO) << "Turning off speaker because headset is plugged in";
                return mixer_ctl_set_enum_by_string_real(ctl, "Off");
            }
        }
    } else if (ctl->info->id.numid == EXT_HP_SWITCH_CTRL_ID) {
        if (strcmp(string, "On") == 0) {
            if (get_headset_state() > 0) {
                LOG(INFO) << "Turning on headset because headset is plugged in";
                return mixer_ctl_set_enum_by_string_real(ctl, "On");
            } else {
                LOG(INFO) << "Turning on speaker because headset is not plugged in";
                return mixer_ctl_set_enum_by_string_real(ctl, "Off");
            }
        }
    }

    return mixer_ctl_set_enum_by_string_real(ctl, string);
}
