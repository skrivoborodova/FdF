/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 06:20:56 by marrow            #+#    #+#             */
/*   Updated: 2020/02/22 02:44:28 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_coord
{
	float		x;
	float		y;
	int			z;
	int			z1;
	float		x_step;
	float		y_step;
}				t_coord;

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**value;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	int			projection;
	void		*mlx_ptr;
	void		*win_ptr;
	t_coord		*p;
}				t_fdf;

int				read_file(char *file_name, t_fdf *data);
void			draw_line(t_coord *p, float x1, float y1, t_fdf *data);
void			draw(t_fdf *data);
void			choose_colour(t_coord *p, float x1, float y1, t_fdf *data);
void			zoom(t_coord *p, float *x1, float *y1, t_fdf *data);
void			isometric(float *x, float *y, int z);
void			shift(t_coord *p, float *x1, float *y1, t_fdf *data);
void			key_shift(int key, t_fdf *data);
void			key_zoom(int key, t_fdf *data);
void			setup_controls(t_fdf *data);
void			choose_projection(int key, t_fdf *data);
void			print_menu(t_fdf *data);

#endif
