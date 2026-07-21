#include "ft_foo.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	c;
	int		len;
	ssize_t	bytes;
	//malloc line for int_max, read chars one by one byte into char *line.
	line = malloc(sizeof(char) * INT_MAX);
	if (!line)
		return (NULL);
	len = 0;
	while (len < INT_MAX - 1)
	{
		bytes = read(fd, &c, 1);
		if (bytes < 0)
		{
			free(line);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		line[len] = c;
		len++;
		if (c == '\n')
			break ;
	}
	if (len == 0)
	{
		free(line);
		return (NULL);
	}
	line[len] = '\0';
	return (line);
}

int	row_len(char *line)
{
	int	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	return (len);
}

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
	if (map->height <= 0 
		|| map->empty == map->obstacle
		|| map->emtpy == map_fill
		|| map->obstacle == map->fill)
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

char	**build_map(int fd, t_map *map, t_gc **gc)
{
	char	**grid;
	char	*line;
	int		row;
	int		len;

	grid = gc_malloc(gc, sizeof(char *) * (map->height + 1));
	if (!grid)
		return (NULL);
	row = 0;
	while (row < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		len = row_len(line);
		if (row == 0)
			map->len = len;
		if (len == 0 || len != map->len
			|| !valid_row(line, len, map))
		{
			free(line);
			return (NULL);
		}
		grid[row] = copy_row(line, len, gc);
		free(line);
		if (!grid[row])
			return (NULL);
		row++;
	}
	grid[row] = '\0';
	return (grid);
}

char	**open_map(char *filename, t_map *map, t_gc **gc)
{
	char	**grid;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (!read_header(fd, map))
	{
		close(fd);
		return (NULL);
	}
	grid = build_map(fd, map, gc);
	close(fd);
	return (grid);
}