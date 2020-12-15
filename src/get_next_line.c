/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // TODO: Remove

int		fetch_eol(t_gnl_vec *file)
{
	char	*content;

	if (!file) {
		return (0);
	}
	content = file->content;
	while (file->cursor < file->length)
	{
		if (content[file->cursor] == '\n')
		{
			content[file->cursor] = '\0';
			return (1);
		}
		file->cursor++;
	}
	return (0);
}

int	check_capacity(t_gnl_vec **ptr)
{
	t_gnl_vec *vec;

	vec = *ptr;
	if (!vec)
	{
		if (!(*ptr = gnl_vec_new())) {
			return (0);
		}
	}
	else
		if (vec->length + BUFFER_SIZE >= vec->capacity && !gnl_vec_grow(ptr))
			return (0);
	return (1);
}

ssize_t	read_file(int fd, t_gnl_vec **ptr)
{
	t_gnl_vec	*file;
	ssize_t		r_bytes;

	if (!check_capacity(ptr))
		return (-1);
	file = *ptr;
	if ((r_bytes = read(fd, file->content + file->length, BUFFER_SIZE)) == -1)
		return (-1); // TODO: properly free memory
	file->length += r_bytes;
	return (r_bytes);
}

int		format_output(t_gnl_vec **ptr, char **line)
{
	t_gnl_vec	*file;
	int			i;

	file = *ptr;
	if (!(*line = malloc(file->cursor)))
	{
		puts("\e[31mexplosion!!\e[0m");
		free(file->content);
		free(file);
		*ptr = NULL;
		return (-1);
	}
	i = 0;
	while (i < file->cursor)
	{
		(*line)[i] = file->content[i];
		i++;
	}
	(*line)[i] = '\0';
	ft_memmove(file->content, file->content + file->cursor + 1, file->length - file->cursor);
	file->length -= file->cursor + 1;
	file->cursor = 0;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl_vec	*files[FOPEN_MAX];

	if (fd < 0 || fd >= FOPEN_MAX || !line || BUFFER_SIZE < 1
		|| BUFFER_SIZE > SSIZE_MAX)
		return (-1);
	while (!fetch_eol(files[fd]))
	{
		read_file(fd, &(files[fd]));
	}
	return (format_output(&(files[fd]), line));
}
