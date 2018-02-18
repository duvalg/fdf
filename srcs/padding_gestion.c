/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_gestion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:23:29 by gduval            #+#    #+#             */
/*   Updated: 2017/12/16 17:26:18 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	padding_gestion(t_dna *dna)
{
	if (dna->width >= dna->height)
		dna->padding = (dna->width > (WIDTH * 0.75)) ? 3 : \
		(WIDTH) / dna->width / 2;
	else
		dna->padding = (dna->height > (HEIGHT * 0.75)) ? 3 : \
		(HEIGHT) / dna->height / 2;
}
