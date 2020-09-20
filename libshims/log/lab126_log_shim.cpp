/*
 * Copyright (C) 2016 The CyanogenMod Project
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

	// skip flooding logs
	if (!tag)
	{
		tag = "";
	}
	if( strncmp(tag, "Sensors", 7) == 0
		||  strncmp(tag, "qcom_se", 7) == 0 )
	{
		return 0;
	}
	// skip flooding logs

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
