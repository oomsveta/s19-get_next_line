/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:10:02 by lwicket           #+#    #+#             */
/*   Updated: 2020/12/02 09:54:37 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // TODO: Remove

static void append_lst(t_file *file_data, char *buffer)
{
	t_list	*node;

	if (!(node = malloc(sizeof(t_list))))
		return ; // TODO: handle error
	node->content = buffer;
	node->next = NULL;
	if (!file_data)
	{
		if (!(file_data = malloc(sizeof(t_file))))
			return ; // TODO: handle error
		file_data->lst_size = 1;
		file_data->head = node;
		file_data->last = node;
	}
	else
	{
		file_data->lst_size++;
		file_data->last->next = node;
		file_data->last = node;
	}
	printf("%s", node->content);
}

//static int	format_output(t_list *file_data, char **line)
//{
//	return (1);
//}

static int	includes_eol(t_file *file_data)
{
	char	*str;

	if (file_data)
	{
		puts("lol");
		str = file_data->last->content;
		while (*str++)
			if (*str == '\n')
				return (1);
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
	while (!includes_eol(files_data[fd]))
	{
		if (!(buffer = malloc(BUFFER_SIZE + 1)))
			return (-1); // TODO: free all
		if ((buff_len = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[buff_len] = '\0';
			append_lst(files_data[fd], buffer);
		}
		printf("%d\n", buff_len);
	}
	return (1);
}
