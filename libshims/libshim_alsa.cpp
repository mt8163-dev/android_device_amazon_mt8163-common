/*
 * Copyright (C) 2019-2022 Raffaele D'Apuzzo (t0x1cSH)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "libshim_alsa"

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

extern "C" {

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
    if (h2wStatefd == -1) {
        ALOGE("Could not open %s!\n", H2W_STATE_FD);
        return -1;
    }

    lseek(h2wStatefd, 0L, SEEK_SET);
    s = read(h2wStatefd, state, 3);

    return atoi(state);
}

int mixer_ctl_set_enum_by_string(struct mixer_ctl *ctl, const char *string) {
	typedef int (*MIXER_CTL_SET_ENUM_BY_STRING)(struct mixer_ctl *ctl, const char *string);
	static MIXER_CTL_SET_ENUM_BY_STRING orig_mixer_ctl_set_enum_by_string = (MIXER_CTL_SET_ENUM_BY_STRING) dlsym(RTLD_NEXT, "mixer_ctl_set_enum_by_string");
		
	if( ctl->info->id.numid == EXT_SPEAKER_SWITCH_CTRL_ID) {
		if(strcmp(string, "On") == 0) {
			if(readH2wState() > 0) {
				return orig_mixer_ctl_set_enum_by_string(ctl, "Off");
			}
		}
	}
	else if(ctl->info->id.numid == EXT_HP_SWITCH_CTRL_ID) {
	    if(strcmp(string, "On") == 0) {
                if(readH2wState() > 0) {
		    return orig_mixer_ctl_set_enum_by_string(ctl, "On");
		}
		else {
		    return orig_mixer_ctl_set_enum_by_string(ctl, "Off");
		}
	    }
	}
	
	return orig_mixer_ctl_set_enum_by_string(ctl, string);
}

} // extern "C"
