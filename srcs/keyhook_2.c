/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:21:19 by gduval            #+#    #+#             */
/*   Updated: 2017/12/26 13:21:20 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		color_gestion(int keycode, t_dna *dna)
{
	if (keycode != 83 && keycode != 84 && keycode != 85)
		return (0);
	else
	{
		if (keycode == 83)
			dna->bonus->color -= 0x000008;
		else if (keycode == 84)
			dna->bonus->color -= 0x000800;
		else
			dna->bonus->color -= 0x080000;
	}
	return (1);
}

int		relief_gestion(int keycode, t_dna *dna)
{
	if (keycode == 116 || keycode == 121)
	{
		dna->relief = (keycode == 121) ? dna->relief - 0.33 : \
		dna->relief + 0.33;
		return (1);
	}
	return (0);
}

int		bonus_gestion(int keycode, t_dna *dna)
{
	if (keycode == 12)
		dna->bonus->opti = (dna->bonus->opti == 0) ? 1 : 0;
	else if (keycode == 5)
		dna->bonus->glitch = (dna->bonus->glitch == 0) ? 1 : 0;
	else
		return (0);
	return (1);
}

void	display_shortcuts()
{
	ft_putendl("\n*****************************************\n\n\
Deplacer la map : Fleches directionnelles\n\
Reset : [0]\n\
Zoomer : [+] et [-]\n\
Modifier reliefs : [Page up] et [Page down]\n\
Reset reliefs : [delete]\n\
Rotation : [<] et [>]\n\
Changer l'axe de rotation : [control]\n\
Variation couleurs : [1] a [3] (numpad)\n\
Optimisation : [q]\n\
Glitch : [g]\n\
Quitter : [esc]\n\
	\n\n*****************************************");
}
