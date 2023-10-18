/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:27:51 by nvillalt          #+#    #+#             */
/*   Updated: 2023/10/17 13:02:08 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	count;
	
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = ft_calloc(sizeof(char), len);
	if (!join)
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		join[i] = s2[j];
		j++;
		i++;
	}
	return (join);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t	i;
	
	i = 0;
	if (count >= __SIZE_MAX__ || size >= __SIZE_MAX__)
		return (0);
	tmp = malloc(count * size);
	if (!tmp)
		return (0);
	while (i < (count * size))
	{
		tmp[i] = 0;
		i++;
	}
	return ((void *)tmp);
}
char	*ft_strchr(char *str, int c)
{
	int				i;
	unsigned char	*copy;

	i = 0;
	copy = (unsigned char *)str;
	while (copy[i] != '\0')
	{
		if (copy[i] == (unsigned char)c)
			return ((char *)copy + i);
		i++;
	}
	if (copy[i] == (unsigned char)c) // Condicion que a lo mejor hay que quitar luego
		return ((char *)copy + i);
	else
		return (0);
}

char	*ft_substr_mod(char *s, int c)
{
	char	*substr;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len] != 0 && s[len] != c)
		len++;
	substr = ft_calloc(sizeof(char), len + 1);
	if (!substr)
		return (NULL);
	while (i <= len)
	{
		substr[i] = s[i];
		i++;
	}
	return (substr);
}
