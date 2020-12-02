/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 2020/12/02 09:44:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_file
{
	t_list	*head;
	t_list	*last;
	size_t	lst_size;
}				t_file;

int	get_next_line(int fd, char **line);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif
