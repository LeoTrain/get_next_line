#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc != 2)
	{
		printf("Error: you need 1 parameter for the file name.");
		return (-1);
	}

	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
