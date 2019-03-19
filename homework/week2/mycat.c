#include "apue.h"
#include <assert.h>
#include <math.h>
#include <stdlib.h>

// #define	BUFFSIZE	4096

int
main(int argc, char *argv[])
{
	int		n;
	int 	BUFFSIZE = atoi(argv[1]);	// 将字符串转成整数在stdlib中
	// assert( fabs(BUFFSIZE - (int)BUFFSIZE) <= 1e-8 );
	// char	buf[BUFFSIZE];
	char *buf = (char *)malloc(BUFFSIZE);
	
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");

	if (n < 0)
		err_sys("read error");

	exit(0);
}
