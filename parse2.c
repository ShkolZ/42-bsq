/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:07:22 by vbertych          #+#    #+#             */
/*   Updated: 2026/07/22 22:07:22 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	valid_row(char *line, int len, t_map *map)
{
	int	i;

	if (line[len] != '\n')
		return (0);
	i = 0;
	while (i < len)
	{
		if (line[i] != map->empty && line[i] != map->obstacle)
			return (0);
		i++;
	}
	return (1);
}

char	*copy_row(char *line, int len, t_gc **gc)
{
	char	*row;
	int		i;

	row = gc_malloc(gc, sizeof(char) * (len + 1));
	if (!row)
		return (NULL);
	i = 0;
	while (i < len)
	{
		row[i] = line[i];
		i++;
	}
	row[i] = '\0';
	return (row);
}

int	valid_header(t_map *map)
{
	if (map->height <= 0
		|| map->empty == map->obstacle
		|| map->empty == map->fill
		|| map->obstacle == map->fill)
		return (0);
	return (1);
}

int	read_header(int fd, t_map *map)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (!line)
		return (0);
	len = ft_strlen(line);
	if (len < 5 || line[len - 1] != '\n')
	{
		free(line);
		return (0);
	}
	map->height = ft_atoi(line);
	map->empty = line[len - 4];
	map->obstacle = line[len - 3];
	map->fill = line[len - 2];
	if (!valid_header(map))
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}
