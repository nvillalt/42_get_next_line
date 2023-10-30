/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:06:05 by nvillalt          #+#    #+#             */
/*   Updated: 2023/10/30 16:46:48 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_free_saved(int fd, char **saved)
{
	char	*aux;
	int		len;

	len = 0;
	while (saved[fd][len] != '\0' && saved[fd][len] != '\n')
		len++;
	if (saved[fd][len] == '\n')
		len++;
	aux = ft_strdup(saved[fd] + len);
	//printf("SAVED CON PUNTERO MOVIDO: %s\n", saved[fd] + len);
	free(saved[fd]);
	if (!aux)
		return (NULL);
	return (aux);
}

char	*ft_get_returned_line(int fd, char **saved)
{
	char	*final;
	int		len;

	len = 0;
	if (!saved[fd] || saved[fd][len] == '\0')
		return (NULL);
	while (saved[fd][len] != '\0' && saved[fd][len] != '\n')
		len++;
	if (saved[fd][len] == '\n')
		len++;
	final = ft_calloc(sizeof(char), len + 1);
	if (!final)
		return (NULL);
	len = 0;
	while (saved[fd][len] != '\0' && saved[fd][len] != '\n')
	{
		final[len] = saved[fd][len];
		len++;
	}
	if (saved[fd][len] == '\n')
		final[len] = saved[fd][len];
	return (final);
}

char	*ft_read_fd(int fd, char **saved)
{
	char	*buffer;
	ssize_t	read_chars;

	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_chars = 1;
	while (read_chars > 0 && !ft_check_char(buffer, '\n'))
	{
		read_chars = read(fd, buffer, BUFFER_SIZE);
		if (read_chars == -1)
		{
			free(buffer);
			free(saved[fd]);
			saved[fd] = NULL;
			return (NULL);
		}
		buffer[read_chars] = '\0';
		saved[fd] = ft_strjoin(saved[fd], buffer);
	}
	free(buffer);
	return (saved[fd]);
}

char	*get_next_line(int fd)
{
	static char	*saved[FD_MAX];
	char		*final;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (free(saved[fd]), NULL);
	saved[fd] = ft_read_fd(fd, saved);
	if (!saved[fd])
		return (NULL);
	final = ft_get_returned_line(fd, saved);
	if (!final)
	{
 		if (saved[fd])
		{ 
			free(saved[fd]);
			saved[fd] = NULL;
			return (NULL);
		}
	}
	saved[fd] = ft_free_saved(fd, saved);
	return (final);
}