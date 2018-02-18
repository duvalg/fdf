/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:45:13 by gduval            #+#    #+#             */
/*   Updated: 2017/09/29 15:45:14 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			main(int ac, const char **av)
{
	int		i;
	int		fd;

	i = 0;
	fd = 0;
	if (ac < 2)
	{
		ft_putendl_fd("Caution : No map specified\nReading on STDIN ...", 2);
		init_dna(fd);
	}
	else
	{
		while (++i < ac)
		{
			while ((fd = open(av[i], O_RDONLY)) <= 0 && i < ac)
			{
				ft_putendl_fd("Error : Bad file specified", 2);
				++i;
			}
			init_dna(fd);
			close(fd);
		}
	}
	return (0);
}
