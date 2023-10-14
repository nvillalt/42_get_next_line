/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:21:40 by nvillalt          #+#    #+#             */
/*   Updated: 2023/10/14 15:01:44 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H
// #	define BUFFER_SIZE 10

#	include <unistd.h>
#	include <stdlib.h>
#	include <stddef.h>
#	include <limits.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr_mod(char *str, char c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *str);

#endif