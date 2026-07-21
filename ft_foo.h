/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/07/21 03:18:15 by vbertych         ###   ########.fr       */
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
	char	fill;
	char	**arr;
}	t_map;

typedef struct s_point
{
	int	row;
	int	col;
}	t_point;

typedef struct s_square
{
	t_point	start;
	int		side;
	char	**arr;
}	t_square;

void	*gc_malloc(t_gc **gc, size_t size);
void	gc_free_all(t_gc **gc);
int		check_stdin(int argc, char **argv);
void	free_square(t_square *sq);
int		ft_abs(int n);



#endif
