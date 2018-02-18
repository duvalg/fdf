/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:09:57 by gduval            #+#    #+#             */
/*   Updated: 2017/12/04 15:11:24 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		mlx_pixel_put_to_image(t_dna *dna, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	float		img_size;

	img_size = WIDTH * HEIGHT * dna->image->bpp / 8;
	if (x < 0 || y < 0 || y * dna->image->line_length + x * \
		dna->image->bpp / 8 > img_size || x >= dna->image->line_length /\
		(dna->image->bpp / 8) || y >= img_size / dna->image->line_length)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = dna->image->bpp / 8;
	dna->image->image[y * dna->image->line_length + x * bit_pix] = color1;
	dna->image->image[y * dna->image->line_length + x * bit_pix + 1] = color2;
	dna->image->image[y * dna->image->line_length + x * bit_pix + 2] = color3;
}

static void		trace_horizontal(double *inc, double *coords, \
	double *distances, t_dna *dna)
{
	double	i;
	double	cumul;

	i = -1;
	cumul = distances[0] / 2;
	while (++i < distances[0])
	{
		coords[0] += inc[0];
		cumul += distances[1];
		if (cumul >= distances[0])
		{
			cumul -= distances[0];
			coords[1] += inc[1];
		}
		if (coords[0] >= 0 && coords[0] <= WIDTH && coords[1] >= 0 \
			&& coords[1] <= HEIGHT)
			mlx_pixel_put_to_image(dna, coords[0], coords[1], \
				dna->bonus->color);
	}
}

static void		trace_vertical(double *inc, double *coords, double *distances, \
	t_dna *dna)
{
	double	i;
	double	cumul;

	i = -1;
	cumul = distances[1] / 2;
	while (++i < distances[1])
	{
		coords[1] += inc[1];
		cumul += distances[0];
		if (cumul >= distances[1])
		{
			cumul -= distances[1];
			coords[0] += inc[0];
		}
		if (coords[0] >= 0 && coords[0] <= WIDTH && coords[1] >= 0 \
			&& coords[1] <= HEIGHT)
			mlx_pixel_put_to_image(dna, coords[0], coords[1], \
				dna->bonus->color);
	}
}

void			bresenham(double *xy, double *xf, double *yf, t_dna *dna)
{
	double		distances[2];
	double		inc[2];
	double		coords[2];
	double		xi;
	double		yi;

	xi = xy[0];
	yi = xy[1];
	coords[0] = xi;
	coords[1] = yi;
	distances[0] = *xf - xi;
	distances[1] = *yf - yi;
	inc[0] = (distances[0] > 0) ? 1 : -1;
	inc[1] = (distances[1] > 0) ? 1 : -1;
	distances[0] = (distances[0] < 0) ? distances[0] * -1 : distances[0];
	distances[1] = (distances[1] < 0) ? distances[1] * -1 : distances[1];
	mlx_pixel_put_to_image(dna, coords[0], coords[1], dna->bonus->color);
	if (distances[0] > distances[1])
		trace_horizontal((double *)inc, (double *)coords, (double *)distances, \
		dna);
	else
		trace_vertical((double *)inc, (double *)coords, (double *)distances, \
		dna);
}
