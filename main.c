/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/07/22 23:28:37 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	solve_map(t_map *map, t_gc **gc)
{
	t_square	square;

	square = find_largest(map);
	print_out(map, &square);
	gc_free_all(gc);
}

void	run_stdin(void)
{
	t_map	map;
	t_gc	*gc;

	gc = NULL;
	if (!open_map(0, &map, &gc))
	{
		write(1, "map error\n", 10);
		gc_free_all(&gc);
		return ;
	}
	solve_map(&map, &gc);
}

void	run_args(int argc, char **argv)
{
	int		i;
	int		fd;
	t_map	map;
	t_gc	*gc;

	i = 1;
	gc = NULL;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (!open_map(fd, &map, &gc))
		{
			write(1, "map error\n", 10);
			gc_free_all(&gc);
		}
		else
			solve_map(&map, &gc);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (is_stdin(argc))
		run_stdin();
	else
		run_args(argc, argv);
	return (0);
}
