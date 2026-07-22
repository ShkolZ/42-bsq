/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/07/22 22:37:40 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"


int	main(int argc, char **argv)
{
	int			i;
	t_map		map;
	t_gc		*gc;
	t_square	square;
	int			fd;

	gc = NULL;
	i = 1;
	if (is_stdin(argc))
	{
		if (!open_map(0, &map, &gc))
		{
			write(1, "map error\n", 10);
			gc_free_all(&gc);
			return (0);
		}
		square = find_largest(&map);
		print_out(&map, &square);
		gc_free_all(&gc);
	}
	else
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			open_map(fd, &map, &gc);
			square = find_largest(&map);
			print_out(&map, &square);
			gc_free_all(&gc);
			i++;
		}
	}
}

// parse the map to char **map
// go through map making squares
// output the largest one