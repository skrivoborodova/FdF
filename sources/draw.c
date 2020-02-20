/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:49:38 by oearlene          #+#    #+#             */
/*   Updated: 2020/02/20 17:36:23 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		module(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

float		maximum(float a, float b)
{
	a = module(a);
	b = module(b);
	if (a > b)
		return (a);
	else
		return (b);
}

void		isometric(float *x, float *y, int z)
{
	double	angle;

	angle = 0.8;
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void		zoom(t_coord coord, t_fdf *data)
{
	data->zoom = 50;
	coord.x *= data->zoom;
	coord.y *= data->zoom;
	coord.x1 *= data->zoom;
	coord.y1 *= data->zoom;
}

void		choose_colour(t_coord coord, t_fdf *data)
{
	int		z;
	int		z1;

	z = data->value[(int)coord.y][(int)coord.x];
	z1 = data->value[(int)coord.y1][(int)coord.x1];
	if (z > 0 || z1 > 0)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}

void		draw_line(t_coord coord, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	choose_colour(coord, data);
	zoom(coord, data);
	//isometric(&x, &y, z);
	//isometric(&x1, &y1, z1);
	x_step = coord.x1 - coord.x;
	y_step = coord.y1 - coord.y;
	max = maximum(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(coord.x - coord.x1) || (int)(coord.y - coord.y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)coord.x,
				(int)coord.y, data->color);
		coord.x += x_step;
		coord.y += y_step;
	}
}

void		draw(t_fdf *data)
{
	t_coord coord;

	coord.x1 = 0;
	coord.y1 = 0;
	coord.y = 0;
	while ((int)(coord.y) < data->height)
	{
		coord.x = 0;
		while ((int)(coord.x) < data->width)
		{
			if ((int)(coord.x) < data->width - 1)
			{
				coord.x1 = coord.x + 1;
				draw_line(coord, data);
			}
			if ((int)(coord.y) < data->height - 1)
			{
				coord.y1 = coord.y + 1;
				draw_line(coord, data);
			}
			coord.x++;
		}
		coord.y++;
	}
}
