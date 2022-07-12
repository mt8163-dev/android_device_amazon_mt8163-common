#define LOG_TAG "libshim_zygote"

#include <stdlib.h>
#include <dlfcn.h>

#include <log/log.h>

#include "fd_utils.h"

static const char* kPathWhitelistExtra[] = {
    "/proc/ged",
};

bool FileDescriptorWhitelist::IsAllowed(const std::string& path) const {
  bool (*IsAllowed_real)(const FileDescriptorWhitelist*, const std::string&);

  // Check the static whitelist path.
  for (const auto& whitelist_path : kPathWhitelistExtra) {
    if (path == whitelist_path)
      return true;
  }

  if (!IsAllowed_real)
    IsAllowed_real = (typeof(IsAllowed_real))dlsym(RTLD_NEXT, "_ZNK23FileDescriptorWhitelist9IsAllowedERKNSt3__112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE");

  if (IsAllowed_real)
    return IsAllowed_real(this, path);

  ALOGE("Could not find IsAllowed, aborting");
  abort();

  return false;
}
