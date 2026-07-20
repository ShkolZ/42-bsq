/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/07/20 12:41:40 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FOO_H
# define FT_FOO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_gc
{
	void			*ptr;
	struct s_gc		*next;
}	t_gc;

void	*gc_malloc(t_gc **gc, size_t size);
void	gc_free_all(t_gc **gc);

#endif
