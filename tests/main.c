#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <criterion/criterion.h>

Test(gnl, gnl_t1)
{
	int		fd;
	char	*line;
	fd = open("tests/test1.txt", O_RDONLY);
	line = get_next_line(fd);
	cr_assert_str_eq(line, "Hello World\n");
	free(line);
	line = get_next_line(fd);
	cr_assert_str_eq(line, "This is a test\n");
	free(line);
	line = get_next_line(fd);
	cr_assert_str_eq(line, "This is a test\n");
	free(line);
	line = get_next_line(fd);
	cr_assert_str_eq(line, "This is a test\n");
	free(line);
	line = get_next_line(fd);
	cr_assert_str_eq(line, NULL);
	free(line);
	close(fd);
}

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
