#define LOG_TAG "audio-shim"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dlfcn.h>
#include <log.h>
#include <sound/asound.h>
#include <tinyalsa/asoundlib.h>

#define H2W_STATE_FD "/sys/class/switch/h2w/state"

#define EXT_SPEAKER_SWITCH_CTRL_ID 	6
#define EXT_HP_SWITCH_CTRL_ID 		7

struct mixer_ctl {
    struct mixer *mixer;
    struct snd_ctl_elem_info *info;
    char **ename;
};

int readH2wState() {
	int h2wStatefd;
	ssize_t s;
	char state[3];
	
	h2wStatefd = open(H2W_STATE_FD, O_RDONLY);
    if (h2wStatefd == -1)
    {
        ALOGE("Failed to open h2w state, Exiting");
        return -1;
    }

    lseek(h2wStatefd, 0L, SEEK_SET);
    s = read(h2wStatefd, state, 3);

    return atoi(state);
}

int mixer_ctl_set_enum_by_string(struct mixer_ctl *ctl, const char *string) {
	int (*orig_mixer_ctl_set_enum_by_string)(struct mixer_ctl *ctl, const char *string);
	
	orig_mixer_ctl_set_enum_by_string = dlsym(RTLD_NEXT, "mixer_ctl_set_enum_by_string");
	
	ALOGD("mixer_ctl_set_enum_by_string, id:%d, name:%s, val:%s",ctl->info->id.numid, ctl->info->id.name, string);
	
	if(ctl->info->id.numid == EXT_SPEAKER_SWITCH_CTRL_ID) {
		ALOGD("Detected Spk switch commands: %s", string);
		if(strcmp(string, "On") == 0) {
			if(readH2wState() > 0) {
				ALOGD("HP detected, disabling Spk");
				return orig_mixer_ctl_set_enum_by_string(ctl, "Off");
			}
		}
	}
	else if(ctl->info->id.numid == EXT_HP_SWITCH_CTRL_ID) {
		ALOGD("Detected HP switch commands: %s", string);
		if(strcmp(string, "On") == 0) {
			if(readH2wState() > 0) {
				ALOGD("HP detected, enabling");
				return orig_mixer_ctl_set_enum_by_string(ctl, "On");
			}
			else {
				return orig_mixer_ctl_set_enum_by_string(ctl, "Off");
			}
		}
	}
	
	return orig_mixer_ctl_set_enum_by_string(ctl, string);
}

