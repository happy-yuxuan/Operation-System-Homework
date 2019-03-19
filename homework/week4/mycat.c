#include "apue.h"
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#include <fcntl.h>	// open函数

// #define	BUFFSIZE	4096

int
main(int argc, char *argv[])
{
	int		n;
	int 	BUFFSIZE = atoi(argv[1]);	// 将字符串转成整数在stdlib中
	// assert( fabs(BUFFSIZE - (int)BUFFSIZE) <= 1e-8 );
	// char	buf[BUFFSIZE];
	char *buf = (char *)malloc(BUFFSIZE);

	int input = open(argv[2], O_RDONLY);
	int output = open(argv[3], O_CREAT | O_WRONLY | O_TRUNC, 0644);

	if(argc < 3) {
	   printf("error\n");
	   exit(1);	
	}
	
	while ((n = read(input, buf, BUFFSIZE)) > 0)
		if (write(output, buf, n) != n)
			err_sys("write error");

	if (n < 0)
		err_sys("read error");

	close(input);
	close(output);

	exit(0);
}
