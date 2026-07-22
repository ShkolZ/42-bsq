/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 03:17:04 by vbertych          #+#    #+#             */
/*   Updated: 2026/07/22 22:40:20 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_point	make_point(int row, int col)
{
	t_point	xy;

	xy.row = row;
	xy.col = col;
	return (xy);
}

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

void	increment_point(t_point *point, int amount)
{
	point->col += amount;
	point->row += amount;
}
