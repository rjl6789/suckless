/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nogroup";

// theme, included from ${HOME}/src/suckless/themes in config.mk
#include <slock-theme.h>

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* time in seconds to cancel lock with mouse movement */
static const int timetocancel = 5;

/* time in seconds before the monitor shuts down */
static const int monitortime = 10;

/* allow control key to trigger fail on clear */
static const int controlkeyclear = 1;
