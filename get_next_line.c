/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:32:04 by leberton          #+#    #+#             */
/*   Updated: 2025/05/09 19:46:10 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char	*temp = NULL;

static size_t	str_len(const char *s)
{
	size_t i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static char	*joinfree(char *temp, const char *buff)
{
	size_t	temp_len;
	char	*str;

	temp_len = str_len(temp);
	str  = (char *)malloc(temp_len + str_len(buff) + 1 * sizeof(char)); 
	if (!str)
		return NULL;
	if (temp)
		strcpy(str, temp);
	if (buff)
		strcpy(str + temp_len, buff);
	free(temp);
	return (str);
}

static int	find_newline(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*line;
	char	*rest;
	int		newline;
	int		read_len;

	while ((newline = find_newline(temp)) == -1)
	{
		read_len = read(fd, buff, BUFFER_SIZE);
		if (read_len <= 0)
			break;
		buff[read_len] = '\0';
		temp = joinfree(temp, buff);
	}
	if (!temp || !*temp)
		return (free(temp), temp = NULL, NULL);
	if (find_newline(temp) == -1)
		newline = str_len(temp);
	else
		newline = find_newline(temp);
	line = strndup(temp, newline);
	rest = strdup(temp + newline);
	free(temp);
	temp = rest;
	return (line);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error: ARGC != 2 -> no more than one argument allowed.");
		return (1);
	}
	if (argc == 2 && strncmp(argv[1], "files/file", 10) != 0)
	{
		printf("Error: PATH is not correct.");
		return (1);
	}
	char *line;
	int fd;
	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
