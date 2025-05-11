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

ssize_t	is_newline_in_str(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*concat(char *src2,const char *src)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!src2)
		src2 = (char *)calloc(1, sizeof(char));
	str = (char *)calloc(strlen(src) + strlen(src2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	while (src2[j])
	{
		str[i + j] = src2[j];
		j++;
	}
	free(src2);
	return (str);
}

char	*get_line_from_temp(char *temp)
{
	char	*str;

	str = (char *)calloc(strlen(temp) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (*temp && *temp != '\n')
		*str++ = *temp++;
	return (str);
}

void	store_temp_in_buffer(char *temp, char *buffer)
{
	buffer = (char *)calloc(strlen(temp) + 1, sizeof(char));
	if (!buffer)
		return ;
	while (*temp)
		*buffer++ = *temp++;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	char		*line;
	ssize_t		read_size;

	if (!buffer)
	{
		read_size = 0;
		while (is_newline_in_str(buffer) == -1)
		{
			buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
			read_size += read(fd, buffer, BUFFER_SIZE);
			if (read_size < 0)
				return (NULL);
			temp = concat(temp, buffer);
			free(buffer);
		}
		line = get_line_from_temp(temp);
		store_temp_in_buffer(temp, buffer);
		return (line);
	}
	return (NULL);
}
