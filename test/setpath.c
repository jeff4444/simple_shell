#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	char *real = realpath(argv[1], NULL);

	printf("%s %s", argv[1], real);
}
