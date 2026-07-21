/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 02:01:05 by vbertych          #+#    #+#             */
/*   Updated: 2026/07/22 00:45:56 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_foo.h"

t_square	*try_fill(t_point top_left, t_point bot_right, t_map *map)
{
	t_point		tmp_top_left;
	t_square	*sq;

	tmp_top_left = top_left;
	while (tmp_top_left.row < bot_right.row)
	{
		while (tmp_top_left.col < bot_right.col)
		{
			if (is_obstacle(tmp_top_left, map))
				return (NULL);
			tmp_top_left.col++;
		}
		tmp_top_left.row++;
	}
	sq = malloc(sizeof(t_square));
	if (sq == NULL)
		return (NULL);
	sq->top_left = top_left;
	sq->bot_right = bot_right;
	sq->top_right = make_point(top_left.row, bot_right.col);
	sq->bot_left = make_point(bot_right.row, top_left.col);
	sq->side = bot_right.row - top_left.row;
	return (sq);
}

void	check_diagonal(t_point start, t_square *max_square, t_map *map)
{
	t_point		end;
	t_square	*prev_square;

	end = start;
	while (in_boundaries(end, map) && !is_obstacle(end, map))
	{
		if (ft_abs(start.row - end.row) > max_square->side)
		{
			prev_square = max_square;
			max_square = try_fill(start, end, map);
			if (max_square == NULL)
				max_square = prev_square;
			else
			{
				if (prev_square != NULL)
					free(prev_square);
			}
		}
		end.col++;
		end.row++;
	}
}

t_square	find_largest(t_map *map)
{
	t_point		point;
	t_square	max_square;

	point = make_point(0, 0);

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
}

