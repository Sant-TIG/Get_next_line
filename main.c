#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	char	*line;
	int		i;
	//int		fd1;
	//int		fd2;
	int		fd3;
	//fd1 = open("textos/emptylines.txt", O_RDONLY);
	//fd2 = open("textos/hugealphabet.txt", O_RDONLY);
	fd3 = open("textos/empty.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		//line = get_next_line(fd1);
		//printf("line [%02d]: |%s|\n", i, line);
		//free(line);
		//line = get_next_line(fd2);
		//printf("line [%02d]: |%s|\n", i, line);
		//free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	//close(fd1);
	//close(fd2);
	close(fd3);
	return (0);
}
