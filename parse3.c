/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:07:22 by vbertych          #+#    #+#             */
/*   Updated: 2026/07/22 22:07:22 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	add_row(int fd, t_map *map, t_gc **gc, int row)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (!line)
		return (0);
	len = row_len(line);
	if (row == 0)
		map->len = len;
	if (len == 0 || len != map->len
		|| !valid_row(line, len, map))
	{
		free(line);
		return (0);
	}
	map->arr[row] = copy_row(line, len, gc);
	free(line);
	if (!map->arr[row])
		return (0);
	return (1);
}

int	build_map(int fd, t_map *map, t_gc **gc)
{
	int	row;

	map->arr = gc_malloc(gc, sizeof(char *) * (map->height + 1));
	if (!map->arr)
		return (0);
	row = 0;
	while (row < map->height)
	{
		if (!add_row(fd, map, gc, row))
			return (0);
		row++;
	}
	map->arr[row] = '\0';
	return (1);
}

int	open_map(int fd, t_map *map, t_gc **gc)
{
	map->arr = NULL;
	if (fd < 0)
		return (0);
	if (!read_header(fd, map))
	{
		close(fd);
		return (0);
	}
	if (!build_map(fd, map, gc))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
