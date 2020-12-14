/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 2020/12/02 14:25:21 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (dest == src)
		return (dest);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n--)
		d[n] = s[n];
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == src)
		return (dest);
	d = dest;
	s = src;
	if (s < d)
		while (n--)
			d[n] = s[n];
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}

t_gnl_vec	*gnl_vec_new()
{
	t_gnl_vec *vec;

	if (!(vec = malloc(sizeof(t_gnl_vec))))
		return (NULL);
	if (GNL_VEC_CAPACITY <= BUFFER_SIZE)
		vec->capacity = BUFFER_SIZE + 1;
	else
		vec->capacity = GNL_VEC_CAPACITY;
	if (!(vec->content = malloc(vec->capacity)))
	{
		free(vec);
		return (NULL);
	}
	vec->length = 0;
	vec->cursor = 0;
	return (vec);
}

t_gnl_vec	*gnl_vec_grow(t_gnl_vec **ptr)
{
	t_gnl_vec	*old_vec;
	t_gnl_vec	*new_vec;

	if (!(new_vec = malloc(sizeof(t_gnl_vec))))
		return (NULL);
	old_vec = *ptr;
	new_vec->capacity = old_vec->capacity * 2;
	if (!(new_vec->content = malloc(new_vec->capacity)))
	{
		free(new_vec);
		return (NULL);
	}
	new_vec->length = old_vec->length;
	new_vec->cursor = old_vec->cursor;
	ft_memcpy(new_vec->content, old_vec->content, old_vec->length);
	free(old_vec);
	*ptr = new_vec;
	return (new_vec);
}
