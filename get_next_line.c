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

char	*read_fd(int fd, char * temp)
{
	ssize_t	read_chars;
	char	*buffer;

	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_chars = read(fd, buffer, BUFFER_SIZE);
	while (read_chars)
	{
		if (read_chars == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_chars] = '\0';
		temp = ft_strjoin(temp, buffer);
		if (check_char(buffer, '\n'))
			break ;
		read_chars = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (temp);
}
char	*get_next_line(int fd)
{
	static char	*saved; // Para guardar lo que todavía no se ha impreso
	char		*temp; // Guardar los caracteres leídos por read
	char		*final; // Devolver la línea

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (saved == 0)
	{
		saved = ft_calloc(sizeof(char), BUFFER_SIZE + 1); // Inicializar para poder usar el join luego
		if (!saved)
			return (NULL);
	}
	temp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	final = temp;
	temp = read_fd(fd, temp);
	//printf("Temp después de read_fd: %s\n", temp);
	//printf("Saved antes de join: %s\n", saved);
	saved = ft_strjoin(saved, temp);
	//printf("Saved después de join: %s\n", saved);
	//printf("Final antes de mod: %s\n", final);
	final = ft_substr_mod(saved, '\n');
	//printf("Final despues de mod: %s\n", final);
	//printf("Saved antes de strchr: %s\n", saved);
	saved = ft_strchr(saved, '\n');
	saved++;
	//printf("Saved después de avanzar la estática: %s\n", saved);
	return (final);
}

/*Static char va a guardarse la línea leída con la 
cantidad BUFFER_SIZE hasta que acabe el programa.
GNL lee la cantidad buffer_size de un archivo hasta
llegar a \n o \0. Si no hay ninguno de los dos dentro
de la línea, lee otra vez la cantidad de BUFFER_SIZE
hasta que una de las dos condiciones se cumpla. Imprime
la linea hasta \n o \0 */
