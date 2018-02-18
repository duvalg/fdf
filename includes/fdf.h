/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:40:54 by gduval            #+#    #+#             */
/*   Updated: 2017/12/28 15:40:57 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1400
# define HEIGHT 1400

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

typedef struct		s_image
{
	void			*image_ptr;
	char			*image;
	int				bpp;
	int				line_length;
	int				endian;
}					t_image;

typedef struct		s_bonus
{
	int				opti;
	double			rotation;
	double			angle_x;
	double			angle_y;
	double			angle_z;
	int				color;
	int				glitch;
}					t_bonus;

typedef struct		s_point
{
	double			value;
	double			x;
	double			y;
	double			coord_y;
	double			coord_x;
	double			coord_z;
	struct s_point	*next;
}					t_point;

typedef struct		s_dna
{
	int				fd;
	int				height;
	int				width;
	int				nb_points;
	double			padding;
	double			pos_x;
	double			pos_y;
	double			relief;
	void			*mlx;
	void			*win;
	int				(*f[9]) (int, struct s_dna *);
	t_point			*points;
	t_point			*points_ref;
	t_point			**coord;
	t_bonus			*bonus;
	t_image			*image;
}					t_dna;

int					main(int ac, const char **av);
void				init_dna(int fd);
t_point				*init_point(int x, int y, int value);
int					parse(t_dna *dna);
int					check_map(t_dna *dna);
int					init_mlx(t_dna *dna);
void				display_shortcuts();
void				padding_gestion(t_dna *dna);
void				rotation_matrix(t_dna *dna);
void				bresenham(double *xy, double *xf, double *yf, t_dna *dna);
void				display_map(t_dna *dna);
void				print_map(int x, int y, t_dna *dna);
void				print_map_opti(int x, int y, t_dna *dna);
void				put_image_to_window(t_dna *dna);
int					reset(int keycode, t_dna *dna);
int					zoom_gestion(int keycode, t_dna *dna);
int					rotation_gestion(int keycode, t_dna *dna);
int					pos_gestion(int keycode, t_dna *dna);
int					reset_relief(int keycode, t_dna *dna);
int					color_gestion(int keycode, t_dna *dna);
int					relief_gestion(int keycode, t_dna *dna);
int					bonus_gestion(int keycode, t_dna *dna);
void				error(char *message);
int					exit_program(int keycode, t_dna *dna);

#endif
