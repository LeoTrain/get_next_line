#include "get_next_line/get_next_line.h"
#include <fcntl.h>

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		printf("Error: ARGC != 2 -> no more than one argument allowed.");
// 		return (1);
// 	}
// 	if (argc == 2 && strncmp(argv[1], "files/file", 10) != 0)
// 	{
// 		printf("Error: PATH is not correct.");
// 		return (1);
// 	}
// 	char *line;
// 	int fd;
// 	fd = open(argv[1], O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }


char *test(int fd, ssize_t size)
{
	static char *buffer;
	if (!buffer)
		buffer = (char *)calloc(size + 1, sizeof(char));
	read(fd, buffer, size);
	return (buffer);
}

int main(void)
{
	int fd = open("files/file1.txt", O_RDONLY);
	char *buffer = test(fd, 1);
	buffer = test(fd, 1);
	printf("%s\n", buffer);
	close(fd);
	return (0);
}
