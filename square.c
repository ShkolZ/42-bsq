/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 02:01:05 by vbertych          #+#    #+#             */
/*   Updated: 2026/07/21 03:18:59 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_foo.h"

int	in_boundaries(t_point point, t_map *map)
{
	if ((point.row >= 0 && point.row < map->height)
		&& (point.col >= 0 && point.col < map->len))
		return (1);
	return (0);
}

int	is_obstacle(t_point point, t_map *map)
{
	if (map->arr[point.row][point.col] == map->obstacle)
		return (1);
	return (0);
}

void	check_diagonals(t_point start, t_square *max_square, t_map *map)
{
	t_point		end;
	t_square	*prev_square;

	end = start;
	while (in_boundaries(end, map) && !is_obstacle(end, map))
	{
		if (ft_abs(start.row - end.row) > max_square->side && start.)
		{
			prev_square = max_square;
			max_square = try_fill(start, end, *map);
			if (max_square == NULL)
				max_square = prev_square;
			else
				free_square(prev_square);
		}
		end.col++;
		end.row++;
	}
}

find_largest(t_map map, t_gc **gc)
{
	t_point		point;
	t_square	max_square;
	max_square.side = 0;

	point.row = 0;
	point.col = 0;
	while (point.row < map.height)
	{
		while(point.col < map.len)
		{
			check_diagonals(point, &max_square);
			point.col++;
		}
		point.row++;
	}
}

