/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:10:02 by lwicket           #+#    #+#             */
/*   Updated: 2020/12/01 14:12:12 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 2020/12/01 14:04:20 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // TODO: Remove

static void append_lst(t_list **file_data, char *buffer)
{
	t_list	*node;

	if (!(node = malloc(sizeof(t_list))))
		return ;
	node->data = buffer;
	node->next = NULL;
	if (!*file_data)
		*file_data = node;
	else
	{
		while ((*file_data)->next)
			*file_data = (*file_data)->next;
		(*file_data)->next = node;
	}
	puts(node->data);
}

static unsigned char	fetch_eol(t_list *file_data)
{
	char c;
	
	while (file_data)
	{
		while ((c = (*file_data->data++)))
			if (c == '\n')
				return (1);
		file_data = file_data->next;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*files_data[FOPEN_MAX];
	char			*buffer;
	int				buff_len;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (-1);
	//while (!fetch_eol(files_data[fd]))
	//{
		if (!(buffer = malloc(BUFFER_SIZE + 1)))
			return (-1); // TODO: free all
		if ((buff_len = read(fd, buffer, BUFFER_SIZE) > 0))
		{
			buffer[buff_len] = '\0';
			append_lst(&(files_data[fd]), buffer);
		}
	//}
	return (1);
}
