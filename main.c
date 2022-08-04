#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>

int	main(void)
{
	int fd;
	char *lene = "42";
	// char *bonus = "43";
	int count;

	count = 1;
	fd = open("likeu.txt", O_RDONLY);
	while (lene)
	{
		lene = get_next_line(fd);
		printf("\033[1;36m\n\nLine %d: \033[0m%s\n", count++, lene);
		free(lene);
	}
	close(fd);
	system("leaks a.out | grep 'Process ' >> leaks.log");
	return (0);
}