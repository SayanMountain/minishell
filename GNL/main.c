#include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

int main()
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd, &line))
		printf("%s\n", line);
	printf("%s\n", line);

	return (0);
}
