/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:50:25 by nvillalt          #+#    #+#             */
/*   Updated: 2023/10/26 18:31:13 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	while (i < (count * size))
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}

size_t	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (str == 0)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_check_char(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	char	*s;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	s = ft_calloc(sizeof(char), len + 1);
	if (!s)
		return (0);
	while (src[i] != '\0')
	{
		s[i] = (char)src[i];
		i++;
	}
	return (s);
}

char	*ft_strjoin(char *saved, char *buffer)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = ft_calloc(sizeof(char), ft_strlen(saved) + ft_strlen(buffer) + 1);
	if (!join)
		return (free(saved), NULL);
	while (saved && saved[i] != '\0')
	{
		join[i] = saved[i];
		i++;
	}
	while (buffer[j] != '\0')
	{
		join[i] = buffer[j];
		i++;
		j++;
	}
	free(saved);
	saved = 0;
	return (join);
}