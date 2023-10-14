/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:23:47 by nvillalt          #+#    #+#             */
/*   Updated: 2023/10/14 13:35:06 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    int     fd;
    char    *final;

    fd = open("ejemplo.txt", O_RDONLY);
    printf("%d\n", fd);
    final = get_next_line(fd);
    
    printf("%s\n", final);
    return (0);
}