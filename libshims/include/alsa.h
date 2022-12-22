#include <sound/asound.h>
#include <tinyalsa/asoundlib.h>

typedef int (*mixer_ctl_set_enum_by_string_t)(struct mixer_ctl *ctl,
                                              const char *string);

struct mixer_ctl {
    struct mixer *mixer;
    struct snd_ctl_elem_info *info;
    char **ename;
};
