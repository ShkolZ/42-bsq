/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/07/22 00:50:59 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_foo.h"

int	main(int argc, char **argv)
{
	int			i;
	char		**map;
	int			is_stdin;
	t_gc		*gc;
	t_square	square;

	gc = NULL;
	i = 1;
	is_stdin = check_stdin(argc, argv);
	if (is_stdin)
	{
		map = make_map(argv[i], is_stdin);
		square = find_largest(map);
	}
	else
	{
		while (i < argc)
		{
			map = make_map(argv[i], is_stdin);
			find_largest(map);
		}
	}
}


// parse the map to char **map
// go through map making squares
// output the largest one