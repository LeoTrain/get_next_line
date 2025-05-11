/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:37:10 by leberton          #+#    #+#             */
/*   Updated: 2025/05/11 16:01:38 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	str_len(const char *s)
{
	size_t i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*joinfree(char *temp, const char *buff)
{
	size_t			temp_len;
	size_t			buff_len;
	char	*str;

	temp_len = str_len(temp);
	buff_len = str_len(buff);
	str  = (char *)malloc((temp_len + str_len(buff) + 1) * sizeof(char)); 
	if (!str)
		return NULL;
	if (temp)
		memcpy(str, temp, temp_len);
	if (buff)
		memcpy(str + temp_len, buff, buff_len);
	str[temp_len + buff_len] = '\0';
	free(temp);
	return (str);
}

ssize_t	find_newline(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}
