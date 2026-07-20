/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/07/21 01:26:26 by vbertych         ###   ########.fr       */
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

typedef struct s_map
{
	int		height;
	int		len;
	char	empty;
	char	obstacle;
}	t_map;

void	*gc_malloc(t_gc **gc, size_t size);
void	gc_free_all(t_gc **gc);
int		check_stdin(int argc, char **argv);


#endif
