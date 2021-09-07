#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define LOG_TAG "kvolcb"

#include <log.h>

#include <tinyalsa/asoundlib.h>
#include <sound/asound.h>

#define SOUND_CARD 0
#define SWITCH_CONTROL "VOLKEY_SWITCH"

int main(int argc, char *argv[]) 
{
    struct mixer *snd_card;
    struct mixer_ctl *snd_ctrl;
    int ret;

    ALOGI("[%s] init, uid %d", __func__, getuid());

    if (argc < 2)
        return -1;

    snd_card = mixer_open(SOUND_CARD);
    if (snd_card == NULL)
    {
        ALOGE("[%s] couldn't open sound card!", __func__);
        return -1;
    }

    snd_ctrl = mixer_get_ctl_by_name(snd_card, SWITCH_CONTROL);
    if (snd_ctrl == NULL)
    {
        ALOGE("[%s] couldn't access control: %s", __func__, SWITCH_CONTROL);
        return -1;
    }

    ret = mixer_ctl_set_value(snd_ctrl, 0, atoi(argv[1]));
    if (ret < 0)
    {
        ALOGI("[%s] couldn't set value %s to %s!", __func__, argv[1], SWITCH_CONTROL);
        return -1;
    }

    ret = mixer_ctl_get_value(snd_ctrl, 0);
    ALOGI("[%s] %s -> %d", __func__, SWITCH_CONTROL, ret);

    ALOGI("[%s] exit, uid %d", __func__, getuid());
    return 0;
}
