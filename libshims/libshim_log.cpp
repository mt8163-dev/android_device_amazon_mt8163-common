#define LOG_TAG "libshim_log"
#define LOG_BUF_SIZE 1024

#define XLOG_DEVICE "/proc/xlog/setfil"

#define XLOG_NAME_MAX_LEN 64

#define XLOG_SET_LEVEL       12
#define XLOG_GET_LEVEL       13
#define XLOG_SET_TAG_LEVEL   14

#define XLOG_FILTER_DEFAULT_LEVEL 0x00223222

#include <string.h>
#include <fcntl.h>

#include <log/log.h>
#include <cutils/log.h>

#include <android-base/properties.h>

#include <sys/stat.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct xlog_entry {
	char name[XLOG_NAME_MAX_LEN];
	uint32_t level;
};

struct xlog_record {
    const char *tag_str;
    const char *fmt_str;
    int prio;
};

int lab126_log_write(int bufID, int prio, const char *tag, const char *fmt, ...)
{
	va_list ap;
	char buf[LOG_BUF_SIZE];
	int _a = bufID;
	int _b = prio;

	if (!tag)
		tag = "";

	if( strncmp(tag, "Sensors", 7) == 0
		||  strncmp(tag, "qcom_se", 7) == 0 
			||   strncmp(tag, "rpmb", 7) == 0
	   			|| strncmp(tag, "AudioALSAStreamOut", 7) == 0)
	{
		return 0;
	}

	va_start(ap, fmt);
	vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
	va_end(ap);

	char new_tag[128];
	snprintf(new_tag, sizeof(new_tag), "AMZ-%s", tag);

	return __android_log_buf_write(LOG_ID_MAIN, ANDROID_LOG_DEBUG, new_tag, buf);
}

int __vitals_log_print(int bufID, int prio, const char *tag, const char *fmt, ...)
{
	va_list ap;
	char buf[LOG_BUF_SIZE];
	int _a = bufID;
	int _b = prio;

	va_start(ap, fmt);
	va_end(ap);

	return __android_log_write(ANDROID_LOG_DEBUG, tag, "__vitals_log_print not implemented");
}

int xlogf_set_level(uint32_t level)
{
    int ret = -1;
    int fd = open(XLOG_DEVICE, O_RDONLY);
    if (fd >= 0) {
        if (ioctl(fd, XLOG_SET_LEVEL, level) == 0) {
            ret = 0;
        }
        close(fd);
    }
    return ret;
}

uint32_t xlogf_get_level(void)
{
    uint32_t level = XLOG_FILTER_DEFAULT_LEVEL;
    int fd = open(XLOG_DEVICE, O_RDONLY);
    if (fd >= 0) {
        ioctl(fd,XLOG_GET_LEVEL, &level);
        close(fd);
    }

    return level;
}

int xlogf_tag_set_level(const char *name, uint32_t level)
{
    int ret = -1;
    int fd = open(XLOG_DEVICE, O_RDONLY);
    if (fd >= 0) {
        struct xlog_entry ent;

        memset(&ent, 0, sizeof(sizeof(struct xlog_entry)));
        strlcpy(ent.name, name, XLOG_NAME_MAX_LEN);
        ent.level = level;
        if (ioctl(fd, XLOG_SET_TAG_LEVEL, &ent) == 0) {
            ret = 0;
        }
        close(fd);
    }
    return ret;
}

void __xlog_buf_printf(int bufid __unused, const struct xlog_record * xlog_record, ...)
{
    va_list args;
    va_start(args, xlog_record);

    if (android::base::GetProperty("persist.debug.xlog.enable", "") != "0")
        __android_log_vprint(xlog_record->prio, xlog_record->tag_str, xlog_record->fmt_str, args);
}

#ifdef __cplusplus
}
#endif
