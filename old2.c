#include "shell.h"

void cd_old(char *dir) {
	char *old = getenv("OLDPWD");

	if (old != NULL) {
		_print(old);
		_print("\n");
		chdir(old);
		setenv("OLDPWD", dir, 1); 
		setenv("PWD", old, 1);
	}

}
