/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:15:55 by reyam             #+#    #+#             */
/*   Updated: 2026/07/20 21:09:34 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_foo.h"

int	validate_args(int argc, char **argv)
{
	if (argc > 1) //how to read the STDIN, handle 
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if ()
	return (1);
}