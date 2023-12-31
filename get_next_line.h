/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:11:45 by nvillalt          #+#    #+#             */
/*   Updated: 2023/10/26 17:07:30 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

/* MAIN FILE FUNCTIONS */
char	*get_next_line(int fd);

/* AUXILIARY FUNCTIONS */
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
//char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
int	ft_check_char(char *str, int c);

#endif