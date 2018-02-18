/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:27:20 by gduval            #+#    #+#             */
/*   Updated: 2017/12/28 11:27:22 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		print_map_opti(int x, int y, t_dna *dna)
{
	double	coords[2];

	coords[0] = dna->coord[y][x].coord_x;
	coords[1] = dna->coord[y][x].coord_y;
	if (x + 1 < dna->width && dna->coord[y][x + 1].coord_x <= WIDTH + \
		dna->padding && dna->coord[y][x + 1].coord_x >= -dna->padding)
	{
		bresenham((double *)coords, &dna->coord[y][x + 1].coord_x, \
			&dna->coord[y][x + 1].coord_y, dna);
	}
	if (y + 1 < dna->height && dna->coord[y + 1][x].coord_y <= HEIGHT + \
		dna->padding && dna->coord[y][x].coord_y >= -dna->padding)
		bresenham((double *)coords, \
			&dna->coord[y + 1][x].coord_x, &dna->coord[y + 1][x].coord_y, dna);
}

void		print_map(int x, int y, t_dna *dna)
{
	double	coords[2];

	coords[0] = dna->coord[y][x].coord_x;
	coords[1] = dna->coord[y][x].coord_y;
	if (x + 1 < dna->width)
		bresenham((double *)coords, &dna->coord[y][x + 1].coord_x, \
			&dna->coord[y][x + 1].coord_y, dna);
	if (y + 1 < dna->height)
		bresenham((double *)coords, \
			&dna->coord[y + 1][x].coord_x, &dna->coord[y + 1][x].coord_y, dna);
}

void		put_image_to_window(t_dna *dna)
{
	if (dna->bonus->glitch)
		mlx_put_image_to_window(dna->mlx, dna->win, dna->image->image_ptr, \
			dna->pos_x, dna->pos_y);
	else
		mlx_put_image_to_window(dna->mlx, dna->win, dna->image->image_ptr, \
			0, 0);
}
