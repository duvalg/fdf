/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:16:55 by gduval            #+#    #+#             */
/*   Updated: 2017/12/04 14:16:59 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		count_points(int *count, t_dna *dna)
{
	dna->points = dna->points_ref;
	while (dna->points)
	{
		dna->points = dna->points->next;
		count[0] = count[0] + 1;
	}
	dna->points = dna->points_ref;
}

static int		create_list(char **str, int y, t_dna *dna)
{
	char		**coords;
	char		**tmp;
	int			i;

	i = -1;
	coords = ft_strsplit(*str, ' ');
	tmp = coords;
	while (coords[++i])
	{
		if (!dna->points)
		{
			dna->points = init_point(i, y, ft_atoi(coords[i]));
			dna->points_ref = dna->points;
		}
		else
		{
			dna->points->next = init_point(i, y, ft_atoi(coords[i]));
			dna->points = dna->points->next;
		}
		ft_strdel(&coords[i]);
	}
	ft_memdel((void **)&coords);
	return (1);
}

static int		get_map(char **line, t_dna *dna)
{
	char		*tmp;
	int			ret;
	int			y;
	int			i;

	tmp = NULL;
	ret = 0;
	y = 0;
	while ((ret = get_next_line(dna->fd, line)) > 0)
	{
		i = -1;
		while ((*line)[++i])
			if ((*line)[i] != ' ' && (*line)[i] != '\t')
				if (((*line)[i] < '0' || (*line)[i] > '9') && (*line)[i] != '-')
					error("Invalid map - Only [0 - 9] accepted");
		if (!create_list(line, y, dna))
			return (0);
		ft_strdel(line);
		y++;
	}
	if (line)
		ft_strdel(line);
	dna->points = dna->points_ref;
	return (ret != -1);
}

static int		create_array_from_list(int *size, int *width, t_dna *dna)
{
	t_point		**points;
	int			i;
	int			y;

	if (!(points = (t_point **)ft_memalloc(sizeof(t_point *) * \
	(*size / *width))))
		return (0);
	i = -1;
	while (++i < (*size / *width))
		if (!(points[i] = (t_point *)ft_memalloc(sizeof(t_point) * (*width))))
			return (0);
	dna->points = dna->points_ref;
	dna->width = *width;
	dna->height = *size / *width;
	y = -1;
	dna->points = dna->points_ref;
	while (dna->points)
	{
		points[(int)dna->points->y][(int)dna->points->x] = *dna->points;
		dna->points = dna->points->next;
	}
	dna->coord = points;
	init_mlx(dna);
	return (0);
}

int				parse(t_dna *dna)
{
	char		*line;
	int			count;
	int			width;

	line = NULL;
	count = 0;
	width = 0;
	if (!get_map(&line, dna))
		return (0);
	if ((width = check_map(dna)) == 0)
		return (0);
	count_points(&count, dna);
	dna->nb_points = count;
	create_array_from_list(&count, &width, dna);
	return (1);
}
