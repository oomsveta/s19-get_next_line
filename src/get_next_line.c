/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:10:02 by lwicket           #+#    #+#             */
/*   Updated: 2020/12/02 14:24:29 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // TODO: Remove

static void append_lst(t_file **ptr, char *buffer)
{
	t_list	*node;
	t_file	*file_data;

	if (!(node = ft_lstnew(buffer)))
		return ; // TODO: handle error
	file_data = *ptr;
	if (!file_data)
	{
		if (!(*ptr = malloc(sizeof(t_file))))
			return ; // TODO: handle error
		file_data = *ptr;
		file_data->length = 0;
		file_data->head = node;
	}
	else
		file_data->last->next = node;
	file_data->last = node;
}

static void lst_to_str(t_file *data, char *str)
{
	char *content;
	t_list	*node;

	while (data->head != data->last)
	{
		node = data->head;
		content = node->content;
		while (*content)
			*str++ = *content++;
		data->head = data->head->next;
		ft_lstdelone(node, &free);
	}
	content = data->head->content;
	node = data->head;
	while (*content)
		*str++ = *content++;
	if (!(data->head = malloc(sizeof(t_list))))
		return ; // TODO: handle error
	data->head->content = ft_strdup(content);// TODO: handle error
	data->head->next = NULL;
	data->length = 0;
	ft_lstdelone(node, &free);
}

static int	format_output(t_file *data, char **line)
{
	size_t	size;

	size = data->length + 1;
	if (!(*line = malloc(size)))
		return (-1);
	lst_to_str(data, *line);
	return (1);
}

static int	fetch_eol(t_file *file_data)
{
	char	*str;

	if (file_data)
	{
		str = file_data->last->content;
		while (*str)
		{
			if (*str == '\n')
			{
				*str = '\0';
				return (1);
			}
			file_data->length++;
			str++;
		}

	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_file	*files_data[FOPEN_MAX];
	char			*buffer;
	int				buff_len;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (-1);
	while (!fetch_eol(files_data[fd]))
	{
		if (!(buffer = malloc(BUFFER_SIZE + 1)))
			return (-1); // TODO: free all
		// TODO: handle error and EOF
		if ((buff_len = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[buff_len] = '\0';
			append_lst(&(files_data[fd]), buffer);
		}
	}
	return (format_output(files_data[fd], line));
}
