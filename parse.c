/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/07/22 23:39:24 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
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

int	fill_line(int fd, char *line)
{
	char	c;
	int		len;
	ssize_t	bytes;

	len = 0;
	while (len < INT_MAX - 1)
	{
		bytes = read(fd, &c, 1);
		if (bytes < 0)
			return (-1);
		if (bytes == 0)
			break ;
		line[len] = c;
		len++;
		if (c == '\n')
			break ;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		len;

	line = malloc(sizeof(char) * INT_MAX);
	if (!line)
		return (NULL);
	len = fill_line(fd, line);
	if (len <= 0)
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
