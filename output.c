/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/07/22 19:27:04 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	map_fill(t_map *map, t_square *square)
{
	int	row;
	int	col;

	row = square->top_left.row;
	while (row <= square->bot_right.row)
	{
		col = square->top_left.col;
		while (col <= square->bot_right.col)
		{
			map->arr[row][col] = map->fill;
			col++;
		}
		row++;
	}
}

void	print_map(t_map *map)
{
	int	row;

	row = 0;
	while (row < map->height)
	{
		write(1, map->arr[row], map->len);
		write(1, "\n", 1);
		row++;
	}
}

void	print_out(t_map *map, t_square *square)
{
	map_fill(map, square);
	print_map(map);
}
