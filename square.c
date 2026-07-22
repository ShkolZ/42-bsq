/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 02:01:05 by vbertych          #+#    #+#             */
/*   Updated: 2026/07/22 22:19:08 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_foo.h"

void	print_square(t_square square)
{
	printf("side: %d\n", square.side);
	printf("top_left: [%d, %d]\n", square.top_left.row, square.top_left.col);
	printf("top_right: [%d, %d]\n", square.top_right.row, square.top_right.col);
	printf("bot_right: [%d, %d]\n", square.bot_right.row, square.bot_right.col);
	printf("bot_left: [%d, %d]\n", square.bot_left.row, square.bot_left.col);
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
	square->top_left = top_left;
	square->bot_right = bot_right;
	square->top_right = make_point(top_left.row, bot_right.col);
	square->bot_left = make_point(bot_right.row, top_left.col);
	square->side = bot_right.row - top_left.row;
	print_square(*square);
	return (1);
}

void	check_diagonal(t_point start, t_square *max_square, t_map *map)
{
	t_point		end;
	t_square	*prev_square;

	end = start;
	while (in_boundaries(end, map))
	{
		printf("start.row: %d, start.col: %d\n", start.row, start.col);
		printf("end.row: %d, end.col: %d\n", end.row, end.col);
		if (is_obstacle(end, map))
		{
			increment_point(&end, 1);
			start = end;
		}
		else if (end.row - start.row >= max_square->side)
		{
			printf("pidaras ebaniy\n");
			if (!try_fill(start, end, map, max_square))
				start = end;
		}
		increment_point(&end, 1);
	}
	print_square(*max_square);
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
		printf("point.col %d\n", point.col);
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

