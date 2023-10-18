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

char	*read_fd(int fd)
{
	ssize_t	read_chars;
	char	*buffer;
	char	*temp;
	
	temp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1); // +1 por la terminacion nula
	if (!buffer)
		return (NULL);
	read_chars = read(fd, buffer, BUFFER_SIZE);
	/* Control de errores para read, por si da menor que 0 o 0 directamente 
	(puedo retornar -1 en una funcion que espera char *)*/
	while (read_chars) // Mientras exista la linea... haz esto.
	{
		buffer[read_chars] = '\0';
		if (read_chars <= 0 || read_chars == -1)
			return (0);
		temp = ft_strjoin(temp, buffer); // strjoin arriba, así une en la variable estática todo antes de salirse si encuentra un
		if (check_char(buffer, '\n'))
			break ;
		read_chars = read(fd, buffer, BUFFER_SIZE);
	}
	return (temp);
}
char	*get_next_line(int fd)
{
	static char	*saved; // Para guardar lo que todavía no se ha impreso
	char		*temp; // Guardar los caracteres leídos por read
	char		*final; // Devolver la línea

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (saved == 0) // Que se haga solo la primera vez.
	{
		saved = ft_calloc(sizeof(char), BUFFER_SIZE + 1); // Inicializar para poder usar el join luego
		if (!saved)
			return (NULL);
	}
	temp = NULL;
	final = saved;
	//printf("Temp antes de read_fd: %s\n", temp);
	temp = read_fd(fd);
	//printf("Temp después de read_fd: %s\n", temp);
	//printf("Saved antes de strjoin: %s\n", saved);
	saved = ft_strjoin(saved, temp);
	//printf("Saved después strjoin: %s\n", saved);
	//printf("Final antes de substr: %s\n", final);
	final = ft_substr_mod(saved, '\n'); // Sacar lo que vamos a devolver
	//printf("Final después de substr: %s\n", final);
	saved = ft_strchr(saved, '\n'); // Avanzar la estática
	saved++;
	//printf("Saved al final del todo: %s\n\n\n", saved);
	return (final);
}

/*Static char va a guardarse la línea leída con la 
cantidad BUFFER_SIZE hasta que acabe el programa.
GNL lee la cantidad buffer_size de un archivo hasta
llegar a \n o \0. Si no hay ninguno de los dos dentro
de la línea, lee otra vez la cantidad de BUFFER_SIZE
hasta que una de las dos condiciones se cumpla. Imprime
la linea hasta \n o \0 */
