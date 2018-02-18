/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:20:20 by gduval            #+#    #+#             */
/*   Updated: 2017/12/06 14:20:23 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	check_width(t_dna *dna)
{
	int		width;
	int		max;
	int		count;

	width = 0;
	count = -1;
	max = 0;
	while (dna->points)
	{
		count = (dna->points->x == 0) ? count + 1 : count;
		if (dna->points->x < width)
		{
			if (!max)
				max = width;
			if (max != width)
				return (-1);
			width = 1;
		}
		else
			++width;
		dna->points = dna->points->next;
	}
	if (width != max && count != 0)
		return (-1);
	return (count == 0) ? width : max;
}

int			check_map(t_dna *dna)
{
	int		width;

	width = 0;
	dna->points = dna->points_ref;
	if ((width = check_width(dna)) < 0)
	{
		error("Error - Bad map");
		return (0);
	}
	return (width);
}
