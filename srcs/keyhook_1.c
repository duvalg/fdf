/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:47:45 by gduval            #+#    #+#             */
/*   Updated: 2017/12/26 11:47:46 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		reset_relief(int keycode, t_dna *dna)
{
	if (keycode != 117)
		return (0);
	dna->relief = 1;
	return (1);
}

int		pos_gestion(int keycode, t_dna *dna)
{
	if (keycode != 123 && keycode != 124 && keycode != 125 && keycode != 126)
		return (0);
	else
	{
		if (keycode == 123 || keycode == 124)
		{
			dna->pos_x = (keycode == 123) ? dna->pos_x - dna->padding : \
			dna->pos_x + dna->padding;
		}
		else if (keycode == 125 || keycode == 126)
		{
			dna->pos_y = (keycode == 126) ? dna->pos_y - dna->padding : \
			dna->pos_y + dna->padding;
		}
		return (1);
	}
	return (0);
}

int		rotation_gestion(int keycode, t_dna *dna)
{
	if (keycode == 43 || keycode == 47)
	{
		if (dna->bonus->rotation == 0)
			dna->bonus->angle_z = (keycode == 43) ? dna->bonus->angle_z - \
			0.139626 : dna->bonus->angle_z + 0.139626;
		else if (dna->bonus->rotation == 1)
			dna->bonus->angle_y = (keycode == 43) ? dna->bonus->angle_y - \
			0.139626 : dna->bonus->angle_y + 0.139626;
		else if (dna->bonus->rotation == 2)
			dna->bonus->angle_x = (keycode == 43) ? dna->bonus->angle_x - \
			0.139626 : dna->bonus->angle_x + 0.139626;
		return (1);
	}
	else if (keycode == 256)
	{
		dna->bonus->rotation = (dna->bonus->rotation < 2) ? \
		dna->bonus->rotation + 1 : 0;
		return (1);
	}
	return (0);
}

int		zoom_gestion(int keycode, t_dna *dna)
{
	float	tmp;

	if (keycode != 69 && keycode != 78)
		return (0);
	tmp = dna->padding;
	dna->padding = (keycode == 69) ? dna->padding * 1.15 : dna->padding * 0.85;
	if (keycode == 69)
	{
		dna->pos_x = dna->pos_x - (((dna->padding * dna->width) - \
		(tmp * dna->width)) / 2);
		dna->pos_y = dna->pos_y - (((dna->padding * dna->height) - \
		(tmp * dna->height)) / 2);
	}
	else
	{
		dna->pos_x = dna->pos_x + (((tmp * dna->width) - \
		(dna->padding * dna->width)) / 2);
		dna->pos_y = dna->pos_y + (((tmp * dna->height) - \
		(dna->padding * dna->height)) / 2);
	}
	return (1);
}

int		reset(int keycode, t_dna *dna)
{
	if (keycode != 82)
		return (0);
	padding_gestion(dna);
	dna->pos_x = WIDTH / 4;
	dna->pos_y = HEIGHT / 4;
	dna->bonus->angle_x = 0.658504;
	dna->bonus->angle_y = -0.059626;
	dna->bonus->angle_z = -6.402048;
	dna->bonus->color = 0x00FFFFFF;
	return (1);
}
