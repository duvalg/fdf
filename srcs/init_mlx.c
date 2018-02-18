/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:23:54 by gduval            #+#    #+#             */
/*   Updated: 2017/12/04 15:23:57 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h> //daw

static int		keyhook(int keycode, void *param)
{
	t_dna	*dna;
	int		i;

	i = -1;
	dna = (t_dna *)param;
	while (++i < 9 && !dna->f[i](keycode, dna))
		;
	
	mlx_destroy_image(dna->mlx, dna->image->image_ptr);
	dna->image->image_ptr = mlx_new_image(dna->mlx, WIDTH, HEIGHT);
	dna->image->image = mlx_get_data_addr(dna->image->image_ptr, \
		&dna->image->bpp, &dna->image->line_length, &dna->image->endian);
	display_map(dna);
	return (0);
}

static void		parallel_projection(t_dna *dna)
{
	int			y;
	int			x;

	y = -1;
	while (++y < dna->height)
	{
		x = -1;
		while (++x < dna->width)
		{
			dna->coord[y][x].coord_x = dna->coord[y][x].x * dna->padding;
			dna->coord[y][x].coord_y = dna->coord[y][x].y * dna->padding;
			dna->coord[y][x].coord_z = dna->coord[y][x].value * dna->padding \
			* (dna->relief * 0.5);
		}
	}
}

static void		apply_pos(t_dna *dna)
{
	int			y;
	int			x;

	y = -1;
	while (++y < dna->height)
	{
		x = -1;
		while (++x < dna->width)
		{
			dna->coord[y][x].coord_x += dna->pos_x;
			dna->coord[y][x].coord_y += dna->pos_y;
			dna->coord[y][x].coord_z = dna->coord[y][x].value;
		}
	}
}

void			display_map(t_dna *dna)
{
	int			x;
	int			y;

	y = -1;
	parallel_projection(dna);
	rotation_matrix(dna);
	if (!dna->bonus->glitch)
		apply_pos(dna);
	while (++y < dna->height)
	{
		x = -1;
		while (++x < dna->width)
		{
			if (dna->bonus->opti)
				print_map_opti(x, y, dna);
			else
				print_map(x, y, dna);
		}
	}
	put_image_to_window(dna);
}

int				init_mlx(t_dna *dna)
{
	display_shortcuts();
	dna->mlx = mlx_init();
	dna->win = mlx_new_window(dna->mlx, WIDTH, HEIGHT, "display window");
	dna->image->image_ptr = mlx_new_image(dna->mlx, WIDTH, HEIGHT);
	dna->image->image = mlx_get_data_addr(dna->image->image_ptr, \
		&dna->image->bpp, &dna->image->line_length, &dna->image->endian);
	padding_gestion(dna);
	display_map(dna);
	mlx_hook(dna->win, 2, (1 << 0), keyhook, dna);
	mlx_loop(dna->mlx);
	return (0);
}
