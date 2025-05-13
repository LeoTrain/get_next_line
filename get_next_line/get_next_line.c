/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:32:04 by leberton          #+#    #+#             */
/*   Updated: 2025/05/11 19:09:57 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*free_buffer(char *buffer, char *read_content)
{
	char	*temp;

	temp = ft_strjoin(buffer, read_content);
	free(buffer);
	return (temp);
}

char	*prepare_for_next(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)ft_calloc((strlen(buffer) - i + 1), sizeof(char));
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*get_line_from_buffer(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	i++;
	return (line);
}

char	*rdff(int fd, char *buffer)
{
	ssize_t		read_size;
	char	*read_content;

	if (!buffer)
		buffer = (char *)ft_calloc(1, 1);
	read_size = 1;
	read_content = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_content)
		return (NULL);
	while (read_size > 0)
	{
		read_size = read(fd, read_content, BUFFER_SIZE);
		if (read_size == 0)
		{
			free(read_content);
			return (NULL);
		}
		buffer = free_buffer(buffer, read_content);
		if (strchr(buffer, '\n'))
			break ;
	}
	free(read_content);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = rdff(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line_from_buffer(buffer);
	buffer = prepare_for_next(buffer);
	return (line);
}
