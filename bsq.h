/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/07/22 23:13:37 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

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

/* ------------------------------ arguments ------------------------------- */
int			is_stdin(int argc);

/* ------------------------------- parsing -------------------------------- */
int			open_map(int fd, t_map *map, t_gc **gc);
int			read_header(int fd, t_map *map);
int			valid_header(t_map *map);
int			build_map(int fd, t_map *map, t_gc **gc);
int			add_row(int fd, t_map *map, t_gc **gc, int row);
char		*get_next_line(int fd);
int			fill_line(int fd, char *line);
int			row_len(char *line);
int			valid_row(char *line, int len, t_map *map);
char		*copy_row(char *line, int len, t_gc **gc);
int			ft_strlen(char *str);
int			ft_atoi(char *str);

/* ------------------------------- helpers -------------------------------- */
int			ft_abs(int n);
t_point		make_point(int row, int col);
int			in_boundaries(t_point point, t_map *map);
int			is_obstacle(t_point point, t_map *map);
void		increment_point(t_point *point, int amount);
int			is_closer(t_point a, t_point b);

/* ---------------------------- square finding ---------------------------- */
t_square	find_largest(t_map *map);
void		check_diagonal(t_point start, t_square *max_square, t_map *map);
int			try_fill(t_point top_left, t_point bot_right, t_map *map,
				t_square *square);
void		set_square(t_point top_left, t_point bot_right, t_square *square);

/* -------------------------------- output -------------------------------- */
void		print_out(t_map *map, t_square *square);
void		print_map(t_map *map);
void		map_fill(t_map *map, t_square *square);

/* ---------------------------- garbage collect --------------------------- */
void		*gc_malloc(t_gc **gc, size_t size);
void		gc_free_all(t_gc **gc);

#endif
