/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:49:38 by oearlene          #+#    #+#             */
/*   Updated: 2020/02/20 01:27:58 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	module(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

float	maximum(float a, float b)
{
	a = module(a);
	b = module(b);
	if (a > b)
		return (a);
	else
		return (b);
}

void	isometric(float *x, float *y, int z)
{
	double	angle;

	angle = 0.8;
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	draw_line(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int 	z1;

	z = data->value[(int)y][(int)x];
	z1 = data->value[(int)y1][(int)x1];
	if (z > 0 || z1 > 0)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	//isometric(&x, &y, z);
	//isometric(&x1, &y1, z1);
	x_step = x1 - x;
	y_step = y1 - y;
	max = maximum(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	while(y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				draw_line(x, y, x + 1, y, data);
			if (y < data->height - 1)
				draw_line(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}