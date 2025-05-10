/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:37:10 by leberton          #+#    #+#             */
/*   Updated: 2025/05/11 00:37:12 by leberton         ###   ########.fr       */
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

int	find_newline(const char *s)
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
