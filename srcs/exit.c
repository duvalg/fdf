/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:52:53 by gduval            #+#    #+#             */
/*   Updated: 2017/09/29 15:52:56 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_chained_list(t_dna *dna)
{
	t_point	*tmp;

	dna->points = dna->points_ref;
	tmp = NULL;
	while (dna->points)
	{
		tmp = dna->points->next;
		free(dna->points);
		dna->points = NULL;
		dna->points = tmp;
	}
}

static void	free_coords(t_dna *dna)
{
	int		y;

	y = -1;
	while (++y < dna->height)
	{
		free(dna->coord[y]);
		dna->coord[y] = NULL;
	}
	free(dna->coord);
	dna->coord = NULL;
}

int			exit_program(int keycode, t_dna *dna)
{
	if (keycode == 53)
	{
		free_chained_list(dna);
		free_coords(dna);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void		error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}
