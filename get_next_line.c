/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:32:55 by nvillalt          #+#    #+#             */
/*   Updated: 2023/10/15 17:41:53 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/* Función check string lo que hace es ver si 
dentro de lo leído por el buffer hay algun \n o 
\0. Si lo hay, devuelve 1, si no, devuelve 0 */

int	check_string(char *buffer, char c)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer; // Static variable para ir guardando lo que lee
	char		*final; // Lo que saldrá por output
	static char	*temp; // Unir strings si no hay \n 
	ssize_t		read_bytes;
	size_t		BUFFER_SIZE = 50;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1); // Memoria asignada porque read necesita un buffer con una dirección de memoria válida
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes) 
	{
		buffer[read_bytes] = '\0'; // Sirve para finalizar lo leído en nulo y que pare 

		// PARTIR ESTO EN OTRA FUNCIÓN
		
		if (!check_string(buffer, '\n'))
		{
			if (temp == 0) // Si temp está vacio, creala, si no, une.
				temp = ft_strdup(buffer);
			else
				temp = ft_strjoin(temp, buffer); // Si no hay salto de linea, en la variable estática guardaremos lo leído hasta ese punto
		}
		if (check_string(buffer, '\n'))
		{
			temp = ft_strjoin(temp, buffer); // Dará error con el buffer grande porque no crea la str final
			//printf("temp: %s\n", temp);
			final = ft_substr_mod(temp, '\n');
			return (final);
		}
		read_bytes = read(fd, buffer, BUFFER_SIZE); // Avanzar leyendo el fd
	}
	return (final);
}

/*Static char va a guardarse la línea leída con la 
cantidad BUFFER_SIZE hasta que acabe el programa.
GNL lee la cantidad buffer_size de un archivo hasta
llegar a \n o \0. Si no hay ninguno de los dos dentro
de la línea, lee otra vez la cantidad de BUFFER_SIZE
hasta que una de las dos condiciones se cumpla. Imprime
la linea hasta \n o \0 */