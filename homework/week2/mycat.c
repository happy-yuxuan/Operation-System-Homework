#include "apue.h"
#include <assert.h>
#include <math.h>

// #define	BUFFSIZE	4096

int
main(int argc, char *argv[])
{
	int		n;
	int 	BUFFSIZE = argc;
	// assert( fabs(BUFFSIZE - (int)BUFFSIZE) <= 1e-8 );
	char	buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");

	if (n < 0)
		err_sys("read error");

	exit(0);
}
