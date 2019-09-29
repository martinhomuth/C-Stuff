#include "utils.h"

#include <stdio.h>
#include <sys/utsname.h>
#include <errno.h>
#include <string.h>

void check_system_version()
{
	struct utsname utsname;
	if (uname(&utsname) == -1) {
		fprintf(stderr, "uname failed: %s\n", strerror(errno));
		return;
	}

	fprintf(stdout, "OS\t\t: %s\n", utsname.sysname);
	fprintf(stdout, "Node\t\t: %s\n", utsname.nodename);
	fprintf(stdout, "Release\t\t: %s\n", utsname.release);
	fprintf(stdout, "Version\t\t: %s\n", utsname.version);
	fprintf(stdout, "Machine\t\t: %s\n", utsname.machine);
}


#ifdef TEST
int main()
{
	check_system_version();
}
#endif
