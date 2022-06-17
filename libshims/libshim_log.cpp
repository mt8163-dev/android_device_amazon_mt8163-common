#include <string.h>
#include <log/log.h>

#define LOG_BUF_SIZE 1024

#ifdef __cplusplus
extern "C"
{
#endif

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

#ifdef __cplusplus
}
#endif
