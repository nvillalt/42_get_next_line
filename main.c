/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:10:08 by nvillalt          #+#    #+#             */
/*   Updated: 2023/10/27 13:39:23 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

/*void	ft_leaks(void)
{
	system("leaks -q a.out");
} */

int	main()
{
	char	*line;
	//char	*str;
	int		fd;
	//int		fd2;
	int		i;

	i = 0;
	//atexit(ft_leaks);	//leaks
	fd = open("ejemplo.txt", O_RDONLY);
	//fd = open("ejemplo2.txt", O_RDONLY);
	//fd2 = open("ejemplo3", O_RDONLY);
	//fd = open("ejemplo4.txt", O_RDONLY);
	//fd = open("el_quijote.txt", O_RDONLY);
	line = get_next_line(fd);
	//str = get_next_line(fd2);
	while (i < 4)
	{
		printf("GNL, Vuelta %i: %s", i, line);
		line = get_next_line(fd);
		if (line)
			free(line);
		//str = get_next_line(fd2);
		//printf("GNL, Vuelta %i: %s", i, line);
		i++;
	}
	close(fd);
	system("leaks -q a.out");
	return (0);
}
