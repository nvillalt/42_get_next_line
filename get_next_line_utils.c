/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:27:51 by nvillalt          #+#    #+#             */
/*   Updated: 2023/10/14 11:42:12 by nvillalt         ###   ########.fr       */
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
	
	if (count >= __SIZE_MAX__ || size >= __SIZE_MAX__)
		return (0); // Checar esta condicion con mi otra función
	tmp = malloc(count * size);
	if (!tmp)
		return (0);
	while (i < (count * size))
	{
		tmp[i] = 0;
		i++;
	}
	return ((void *)tmp); // Si da error esto, convertir a char *
}

char	*ft_substr_mod(char *str, char c)
{
	char	*substr;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i] != '\0' || str[i] != c)
		len++;
	substr = ft_calloc(sizeof(char), len + 1);
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = str[i];
		i++;
	}
	return (substr);
}