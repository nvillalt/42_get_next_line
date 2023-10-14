/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:32:55 by nvillalt          #+#    #+#             */
/*   Updated: 2023/10/14 11:49:11 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Función check string lo que hace es ver si 
dentro de lo leído por el buffer hay algun \n o 
\0. Si lo hay, devuelve 1, si no, devuelve 0 */

int	check_string(char	*saved, char c)
{
	size_t	i;

	while (saved != '\0')
	{
		if (saved[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*saved; // Static variable para ir guardando lo que lee
	char		*final; // Lo que saldrá por output
	ssize_t		read_bytes;
	
	if (fd < 0 || read(fd, saved, BUFFER_SIZE) == -1)
		return (NULL);
	read_bytes = read(fd, saved, BUFFER_SIZE);	
	saved = ft_calloc(sizeof(char), read_bytes + 1);
	if (!saved)
		return (NULL);
	if (check_string(saved, '\n'))
		final = ft_substr_mod(saved, '\n');
	
}

/*Static char va a guardarse la línea leída con la 
cantidad BUFFER_SIZE hasta que acabe el programa.
GNL lee la cantidad buffer_size de un archivo hasta
llegar a \n o \0. Si no hay ninguno de los dos dentro
de la línea, lee otra vez la cantidad de BUFFER_SIZE
hasta que una de las dos condiciones se cumpla. Imprime
la linea hasta \n o \0 */