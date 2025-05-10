/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:32:04 by leberton          #+#    #+#             */
/*   Updated: 2025/05/11 00:37:19 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*temp = NULL;

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
