/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 2020/12/02 14:27:52 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

# define GNL_VEC_CAPACITY 1024

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 512
#endif

typedef struct	s_gnl_vec
{
	char	*content;
	size_t	length;
	size_t	capacity;
	size_t	cursor;
}				t_gnl_vec;

void		*ft_memmove(void *dest, const void *src, size_t n);
int			get_next_line(int fd, char **line);
t_gnl_vec	*gnl_vec_new();
t_gnl_vec	*gnl_vec_grow(t_gnl_vec **ptr);

#endif
