#include <cutils/log.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct xlog_record {
    const char *tag_str;
    const char *fmt_str;
    int prio;
};

void __attribute__((weak)) __xlog_buf_printf(__unused int bufid, const struct xlog_record *xlog_record, ...) {
    va_list args;
    va_start(args, xlog_record);
    __android_log_vprint(xlog_record->prio, xlog_record->tag_str, xlog_record->fmt_str, args);
}

#ifdef __cplusplus
}
#endif
