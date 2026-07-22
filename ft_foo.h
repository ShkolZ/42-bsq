/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/07/22 22:06:59 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FOO_H
# define FT_FOO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

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
	t_point	top_left;
	t_point	top_right;
	t_point	bot_left;
	t_point	bot_right;
	int		side;
}	t_square;

void		*gc_malloc(t_gc **gc, size_t size);
void		gc_free_all(t_gc **gc);
int			is_stdin(int argc);
int			ft_abs(int n);
t_point		make_point(int row, int col);
int			in_boundaries(t_point point, t_map *map);
int			is_obstacle(t_point point, t_map *map);
t_square	find_largest(t_map *map);
void		increment_point(t_point *point, int amount);
int			is_closer(t_point a, t_point b);
void		print_out(t_map *map, t_square *square);
int			open_map(int fd, t_map *map, t_gc **gc);


#endif
