/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:32:55 by nvillalt          #+#    #+#             */
/*   Updated: 2023/10/17 15:33:22 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	check_char(char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*read_fd(int fd, char *buffer, char *saved)
{
	ssize_t	read_chars;
	
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1); // +1 por la terminacion nula
	if (!buffer)
		return (NULL);
	read_chars = read(fd, buffer, BUFFER_SIZE);
	//printf("Buffer: %s\nChars: %ld\n", buffer, read_chars);
	/* Control de errores para read, por si da menor que 0 o 0 directamente 
	(puedo retornar -1 en una funcion que espera char *)*/
	while (read_chars) // Mientras exista la linea... haz esto.
	{
		// DA SEGFAULT PORQUE EL SAVED NO ESTÁ INICIALIZADO
		buffer[read_chars] = '\0';
		if (check_char(buffer, '\n'))
		{	saved = ft_strjoin(saved, buffer); // Encuentra el caracter en medio, lo mete en saved y se sale antes de llegar a guardarlo
			break ;
		}
		saved = ft_strjoin(saved, buffer);
		read_chars = read(fd, buffer, BUFFER_SIZE);
	}
	return (saved);
	// Checar si hay \n dentro del buffer
		// Si hay > Parar de leer
		// Si no hay > Seguir leyendo
}
char	*get_next_line(int fd)
{
	static char	*saved; // Para guardar lo que todavía no se ha impreso
	char		*buffer; // Guardar los caracteres leídos por read
	char		*final; // Devolver la línea

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = ft_calloc(sizeof(char), BUFFER_SIZE + 1); // Inicializar para poder usar el join luego
	saved = read_fd(fd, buffer, saved);
	//printf("Saved justo despues de read_fd: %s\n", saved);
	final = ft_substr_mod(saved, '\n'); // Avanzar saved
	//printf("Final: %s\n", final);
	//printf("Saved antes de strchr: %s", saved);
	saved = ft_strchr(saved, '\n');
	//printf("Saved al final: %s\n", saved);
	return (final);
}

/*Static char va a guardarse la línea leída con la 
cantidad BUFFER_SIZE hasta que acabe el programa.
GNL lee la cantidad buffer_size de un archivo hasta
llegar a \n o \0. Si no hay ninguno de los dos dentro
de la línea, lee otra vez la cantidad de BUFFER_SIZE
hasta que una de las dos condiciones se cumpla. Imprime
la linea hasta \n o \0 */
