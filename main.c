/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/07/22 21:57:40 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_foo.h"

int	main(int argc, char **argv)
{
	int			i;
	t_map		map;
	int			is_stdin;
	t_gc		*gc;
	t_square	square;

	gc = NULL;
	i = 1;
	// is_stdin = check_stdin(argc, argv);
	if (is_stdin)
	{
		open_map(0, &map, &gc);
		square = find_largest(&map);
		print_out(&map, &square);
		gc_free_all(&gc);
	}
	else
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY)
			open_map(fd, &map, &gc);
			printf("zalupa\n");
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