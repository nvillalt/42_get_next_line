/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:23:47 by nvillalt          #+#    #+#             */
/*   Updated: 2023/10/15 17:36:00 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    int     fd;
    char    *final;
    int     i;

    i = 0;
    fd = open("ejemplo.txt", O_RDONLY);
    printf("File Descriptor: %d\n", fd);
    while (i++ < 20)
    {
        final = get_next_line(fd);
        printf("GNL, Vuelta %d: %s", i, final);
        free(final);    
    } 
    return (0);
}