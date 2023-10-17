/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:32:55 by nvillalt          #+#    #+#             */
/*   Updated: 2023/10/17 13:16:17 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_fd(int fd, char *buffer, char *saved)
{
	ssize_t	read_chars;
	int		i;
	
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1); // +1 por la terminacion nula
	if (!buffer)
		return (NULL);
	read_chars = read(fd, buffer, BUFFER_SIZE);  // Control de errores para read, por si da menor que 0 o 0 directamente
	while (read_chars) // Mientras exista la linea... haz esto.
	{
		i = 0;
		buffer[read_chars] = '\0';
		if (!ft_strchr(buffer, '\n'))
			saved = ft_strjoin(saved, buffer);
		if (ft_strchr(buffer, '\n') != 0)
			
		if (!ft_strchr(buffer, '\0')) // ????
			read_chars = read(fd, buffer, BUFFER_SIZE);
	}
	printf("Read Chars: %ld\n", read_chars); // Lee siempre un nulo al final?
	// Checar si hay \n dentro del buffer
		// Si hay > Retornar hasta \n
		// Si no hay > Unir dentro de saved
	/*if (check_string(buffer, '\n') == 0)
	{
		saved = ft_strjoin(saved, buffer);
	}*/
}
char	*get_next_line(int fd)
{
	static char	*saved; // Para guardar lo que todavía no se ha impreso
	char		*buffer; // Guardar los caracteres leídos por read
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = read_fd(fd, buffer, saved);
	
	return ("Hola");
}

/*Static char va a guardarse la línea leída con la 
cantidad BUFFER_SIZE hasta que acabe el programa.
GNL lee la cantidad buffer_size de un archivo hasta
llegar a \n o \0. Si no hay ninguno de los dos dentro
de la línea, lee otra vez la cantidad de BUFFER_SIZE
hasta que una de las dos condiciones se cumpla. Imprime
la linea hasta \n o \0 */