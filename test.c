/* test.c */

#include "setproctitle.h"

#define VERSION_MAJOR 1
#define VERSION_MINOR 0

int main(int argc, char *argv[]) {
#if defined(INIT_SETPROCTITLE_REPLACEMENT)
  spt_init(argc, argv);
#endif
  setproctitle("Setup Your Process Name. v%d.%d", VERSION_MAJOR, VERSION_MINOR);

  return 0;
}
