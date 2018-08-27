#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

uid_t getuid() {
  static const char* uid = NULL;
  if(uid == NULL) {
    uid = getenv("FAKEUID");
    if(uid == NULL || atoi(uid) < 10000) {
      uid = "9999";
    }
  }
  return atoi(uid);
}

uid_t geteuid() {
  return getuid();
}

int setuid(uid_t uid) {
  return 0;
}
