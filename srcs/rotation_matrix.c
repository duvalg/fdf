/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:25:33 by gduval            #+#    #+#             */
/*   Updated: 2017/12/19 14:25:35 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		rotation_axe_x(int x, int y, t_dna *dna)
{
	double		sinus;
	double		cosinus;
	double		tmp_y;
	double		tmp_z;

	sinus = sin(dna->bonus->angle_x);
	cosinus = cos(dna->bonus->angle_x);
	tmp_y = 0;
	tmp_z = 0;
	y = -1;
	while (++y < dna->height)
	{
		x = -1;
		while (++x < dna->width)
		{
			tmp_y = dna->coord[y][x].coord_y;
			tmp_z = dna->coord[y][x].coord_z;
			dna->coord[y][x].coord_y = (tmp_y * cosinus) + (tmp_z * -sinus);
			dna->coord[y][x].coord_z = (tmp_y * (sinus)) + (tmp_z * cosinus);
		}
	}
}

static void		rotation_axe_y(int x, int y, t_dna *dna)
{
	double		sinus;
	double		cosinus;
	double		tmp_x;
	double		tmp_z;

	sinus = sin(dna->bonus->angle_y);
	cosinus = cos(dna->bonus->angle_y);
	tmp_x = 0;
	tmp_z = 0;
	y = -1;
	while (++y < dna->height)
	{
		x = -1;
		while (++x < dna->width)
		{
			tmp_x = dna->coord[y][x].coord_x;
			tmp_z = dna->coord[y][x].coord_z;
			dna->coord[y][x].coord_x = (tmp_x * cosinus) + (tmp_z * sinus);
			dna->coord[y][x].coord_z = (tmp_x * (-sinus)) + (tmp_z * cosinus);
		}
	}
}

static void		rotation_axe_z(int x, int y, t_dna *dna)
{
	double		sinus;
	double		cosinus;
	double		tmp_x;
	double		tmp_y;

	sinus = sin(dna->bonus->angle_z);
	cosinus = cos(dna->bonus->angle_z);
	tmp_x = 0;
	tmp_y = 0;
	y = -1;
	while (++y < dna->height)
	{
		x = -1;
		while (++x < dna->width)
		{
			tmp_x = dna->coord[y][x].coord_x;
			tmp_y = dna->coord[y][x].coord_y;
			dna->coord[y][x].coord_x = (tmp_x * cosinus) + (tmp_y * -sinus);
			dna->coord[y][x].coord_y = (tmp_x * (sinus)) + (tmp_y * cosinus);
		}
	}
}

void			rotation_matrix(t_dna *dna)
{
	rotation_axe_x(-1, -1, dna);
	rotation_axe_y(-1, -1, dna);
	rotation_axe_z(-1, -1, dna);
}
