#include "ft_foo.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

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
	int		len;
	int		bytes;
	//malloc line
	//grab line from fd as char *

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
	//finish function.
	i = 0;
	while (i < len)
	{

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
	if (map->height <= 0 || map->empty == map->obstacle)
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
	grid[row] = NULL; //needed?
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