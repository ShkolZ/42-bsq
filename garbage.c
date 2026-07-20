/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimayer <rimayer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/07/19 13:51:36 by rimayer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_foo.h"

void	*gc_malloc(t_gc **gc, size_t size)
{
	t_gc	*node;
	void	*ptr;

	if (!gc || size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	node = malloc(sizeof(t_gc));
	if (!node)
	{
		free(ptr);
		return (NULL);
	}
	node->ptr = ptr;
	node->next = *gc;
	*gc = node;
	return (ptr);
}

void	gc_free_all(t_gc **gc)
{
	t_gc	*node;
	t_gc	*next;

	if (!gc)
		return ;
	node = *gc;
	while (node)
	{
		next = node->next;
		free(node->ptr);
		free(node);
		node = next;
	}
	*gc = NULL;
}
