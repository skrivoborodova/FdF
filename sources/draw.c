/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:49:38 by oearlene          #+#    #+#             */
/*   Updated: 2020/02/21 00:08:21 by oearlene         ###   ########.fr       */
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

/*
void		zoom(t_coord *coord, t_fdf *data)
{
	data->zoom = 20;
	coord->x *= data->zoom;
	coord->y *= data->zoom;
	coord->x1 *= data->zoom;
	coord->y1 *= data->zoom;
}
*/

/*
void		choose_colour(t_coord *coord, t_fdf *data)
{
	int		z;
	int		z1;

	z = data->value[(int)coord->y][(int)coord->x];
	z1 = data->value[(int)coord->y1][(int)coord->x1];
	if (z > 0 || z1 > 0)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}*/

void	draw_line(t_coord *ptr,float x1,float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	float	tmp_x;
	float 	tmp_y;

	tmp_x = ptr->x;
	tmp_y = ptr->y;
	//choose_colour(ptr, data);
	data->zoom = 20;
	ptr->x *= data->zoom;
	ptr->y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	x_step = x1 - ptr->x;
	y_step = y1 - ptr->y;
	max = maximum(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(ptr->x - x1) || (int)(ptr->y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, ptr->x, ptr->y,0xffffff);
		ptr->x += x_step;
		ptr->y += y_step;
	}
	ptr->x = tmp_x;
	ptr->y = tmp_y;
}

void	draw(t_coord *ptr,t_fdf *data)
{

	ptr->y = 0;
	while((int)ptr->y < data->height)
	{
		ptr->x = 0;
		//ptr->y1 = ptr->y;
		while ((int)ptr->x < data->width)
		{
			//ptr->x1 = ptr->x;
			if ((int)ptr->x < data->width - 1)
			{
				draw_line(ptr,ptr->x + 1, ptr->y, data);
			}
			if ((int)ptr->y < data->height - 1)
			{
				draw_line(ptr, ptr->x, ptr->y +1, data);
			}
			ptr->x++;
		}
		ptr->y++;
	}
}
