/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:58:37 by msaadaou          #+#    #+#             */
/*   Updated: 2024/11/13 12:44:43 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*return_line(char *stored, size_t *pos)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!stored || !stored[0])
		return (NULL);
	while (stored[i] && stored[i] != '\n')
		i++;
	if (stored[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stored, i);
	line[i] = '\0';
	*pos = i;
	return (line);
}

char	*my_substr(char *stored, size_t pos)
{
	char	*new;
	size_t	len;

	len = ft_strlen(stored + pos);
	new = malloc(len + 1);
	if (!new)
	{
		free(stored);
		return (NULL);
	}
	ft_memcpy(new, stored + pos, len);
	new[len] = '\0';
	free(stored);
	return (new);
}

char	*my_strjoin(char *stored, char *buffer)
{
	char	*new_stored;
	size_t	size;

	if (!stored)
		return (ft_strdup(buffer));
	size = ft_strlen(stored) + ft_strlen(buffer) + 1;
	new_stored = malloc(size);
	if (!new_stored)
	{
		free(stored);
		return (NULL);
	}
	ft_memcpy(new_stored, stored, ft_strlen(stored));
	ft_memcpy(new_stored + ft_strlen(stored), buffer, ft_strlen(buffer) + 1);
	free(stored);
	return (new_stored);
}

char	*read_buffer(int fd, char *stored)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		stored = my_strjoin(stored, buffer);
		if (!stored)
			break ;
		if (ft_strchr(stored, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes < 0 || !stored || !*stored)
	{
		free(stored);
		return (NULL);
	}
	return (stored);
}

char	*get_next_line(int fd)
{
	static char	*stored[10024];
	char		*line;
	size_t		pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stored[fd] = read_line(fd, stored[fd]);
	if (!stored[fd])
		return (NULL);
	line = return_line(stored[fd], &pos);
	if (!line)
	{
		free(stored[fd]);
		stored[fd] = NULL;
		return (NULL);
	}
	stored[fd] = my_substr(stored[fd], pos);
	return (line);
}
