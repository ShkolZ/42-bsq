/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbertych <vbertych@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:42:41 by vbertych          #+#    #+#             */
/*   Updated: 2026/07/22 22:43:19 by vbertych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_closer(t_point a, t_point b)
{
	if (a.row < b.row)
		return (1);
	if (a.row == b.row && a.col < b.col)
		return (1);
	return (0);
}
