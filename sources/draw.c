/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:49:38 by oearlene          #+#    #+#             */
/*   Updated: 2020/02/21 01:54:18 by oearlene         ###   ########.fr       */
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

void		draw_line(t_coord *p, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	float	tmp_x;
	float	tmp_y;

	tmp_x = p->x;
	tmp_y = p->y;
	choose_colour(p, x1, y1, data);
	zoom(p, &x1, &y1, data);
	isometric(&(p->x), &(p->y), p->z);
	isometric(&x1, &y1, p->z1);
	x_step = x1 - p->x;
	y_step = y1 - p->y;
	max = maximum(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(p->x - x1) || (int)(p->y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, p->x, p->y, data->color);
		p->x += x_step;
		p->y += y_step;
	}
	p->x = tmp_x;
	p->y = tmp_y;
}

void		draw(t_coord *p, t_fdf *data)
{
	p->y = 0;
	while ((int)p->y < data->height)
	{
		p->x = 0;
		while ((int)p->x < data->width)
		{
			if ((int)p->x < data->width - 1)
				draw_line(p, p->x + 1, p->y, data);
			if ((int)p->y < data->height - 1)
				draw_line(p, p->x, p->y + 1, data);
			p->x++;
		}
		p->y++;
	}
}
