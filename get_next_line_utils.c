/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:25:19 by msaadaou          #+#    #+#             */
/*   Updated: 2024/11/13 12:47:22 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *stored)
{
	stored = read_buffer(fd, stored);
	if (!stored || !*stored)
	{
		free(stored);
		return (NULL);
	}
	return (stored);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s1);
	ptr = malloc(size + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, size + 1);
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr_2;

	if (!n || (dst == src))
		return (dst);
	i = 0;
	ptr = (unsigned char *)dst;
	ptr_2 = (unsigned char *)src;
	while (i < n)
	{
		ptr[i] = ptr_2[i];
		i++;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}
