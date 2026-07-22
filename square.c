/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 02:01:05 by vbertych          #+#    #+#             */
/*   Updated: 2026/07/22 22:40:00 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	set_square(t_point top_left, t_point bot_right, t_square *square)
{
	square->top_left = top_left;
	square->bot_right = bot_right;
	square->top_right = make_point(top_left.row, bot_right.col);
	square->bot_left = make_point(bot_right.row, top_left.col);
	square->side = bot_right.row - top_left.row;
}

int	try_fill(t_point top_left, t_point bot_right, t_map *map, t_square *square)
{
	t_point		tmp_top_left;

	tmp_top_left = top_left;
	while (tmp_top_left.row <= bot_right.row)
	{
		while (tmp_top_left.col <= bot_right.col)
		{
			if (is_obstacle(tmp_top_left, map))
			{
				return (0);
			}
			tmp_top_left.col++;
		}
		tmp_top_left.col = top_left.col;
		tmp_top_left.row++;
	}
	if (bot_right.row - top_left.row == square->side
		&& !is_closer(top_left, square->top_left))
		return (1);
	set_square(top_left, bot_right, square);
	return (1);
}

void	check_diagonal(t_point start, t_square *max_square, t_map *map)
{
	t_point		end;

	end = start;
	while (in_boundaries(end, map))
	{
		if (is_obstacle(end, map))
		{
			increment_point(&end, 1);
			start = end;
		}
		else if (end.row - start.row >= max_square->side)
		{
			if (!try_fill(start, end, map, max_square))
				start = end;
		}
		increment_point(&end, 1);
	}
}

t_square	find_largest(t_map *map)
{
	t_point		point;
	t_square	max_square;

	point = make_point(0, 0);
	max_square.side = 0;
	max_square.top_left = make_point(map->height, map->len);
	while (point.col < map->len)
	{
		check_diagonal(point, &max_square, map);
		point.col++;
	}
	point.col = 0;
	while (point.row < map->height)
	{
		check_diagonal(point, &max_square, map);
		point.row++;
	}
	return (max_square);
}

