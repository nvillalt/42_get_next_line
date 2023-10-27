/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:50:38 by nvillalt          #+#    #+#             */
/*   Updated: 2023/10/27 13:32:20 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef FD_MAX
# define FD_MAX 1024
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
size_t	ft_strlen(char *str);
int		ft_check_char(char *str, int c);

#endif