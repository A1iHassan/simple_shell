#include "shell.h"

char *get_oldpwd() { char *oldpwd = getenv("OLDPWD"); if (oldpwd == NULL) { return strdup(""); } return strdup(oldpwd); }
