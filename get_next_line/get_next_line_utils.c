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
#include <stdio.h>

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			index;

	ptr = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		ptr[index] = 0;
		index++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s && s[size])
		size++;
	return (size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dst_len)
		return (size + src_len);
	if (src_len != 0)
	{
		while (src[i] != 0 && dst_len + i + 1 < size)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = 0;
	return (dst_len + src_len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	total_size;

	total_size = 0;
	if (nmemb != 0 && size != 0)
	{
		total_size = nmemb * size;
		if (nmemb != total_size / size)
			return (NULL);
	}
	array = malloc(total_size);
	if (!array)
		return (NULL);
	ft_bzero(array, total_size);
	return (array);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	size;
	int		i;
	int		j;

	size = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	new = (char *)ft_calloc((size + 1), sizeof(char));
	if (!new || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	return (new);
}
