/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:53:36 by gduval            #+#    #+#             */
/*   Updated: 2017/09/29 15:53:38 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		init_keyhook(t_dna *dna)
{
	dna->f[0] = &relief_gestion;
	dna->f[1] = &bonus_gestion;
	dna->f[2] = &color_gestion;
	dna->f[3] = &rotation_gestion;
	dna->f[4] = &zoom_gestion;
	dna->f[5] = &pos_gestion;
	dna->f[6] = &reset_relief;
	dna->f[7] = &reset;
	dna->f[8] = &exit_program;
	parse(dna);
}

static void		init_image(t_dna *dna)
{
	t_image		image;

	image.image_ptr = NULL;
	image.image = NULL;
	image.bpp = 32;
	image.line_length = 4000;
	image.endian = 0;
	dna->image = &image;
	init_keyhook(dna);
}

static void		init_bonus(t_dna *dna)
{
	t_bonus			bonus;

	bonus.opti = 0;
	bonus.rotation = 0;
	bonus.angle_x = 0.658504;
	bonus.angle_y = -0.059626;
	bonus.angle_z = -6.402048;
	bonus.color = 0xFFFFFF;
	bonus.glitch = 0;
	dna->bonus = &bonus;
	init_image(dna);
}

void			init_dna(int fd)
{
	t_dna	dna;

	dna.fd = fd;
	dna.height = 0;
	dna.width = 0;
	dna.nb_points = 0;
	dna.padding = 25;
	dna.pos_x = WIDTH / 4;
	dna.pos_y = HEIGHT / 4;
	dna.relief = 1;
	dna.points = NULL;
	dna.points_ref = NULL;
	dna.bonus = NULL;
	dna.image = NULL;
	dna.coord = NULL;
	dna.mlx = NULL;
	dna.win = NULL;
	init_bonus(&dna);
}

t_point			*init_point(int x, int y, int value)
{
	t_point	*point;

	if (!(point = (t_point *)ft_memalloc(sizeof(t_point))))
		error("init_stuct.c(84) : Error on allocating memory.");
	point->value = value;
	point->x = x;
	point->y = y;
	point->coord_x = 0;
	point->coord_y = 0;
	point->coord_z = 0;
	point->next = NULL;
	return (point);
}
