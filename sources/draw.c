/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:49:38 by oearlene          #+#    #+#             */
/*   Updated: 2020/02/19 00:16:07 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float module(float i)
{
	return (i < 0) ? -i : i;
}

float maximum(float a, float b)
{
	a = module(a);
	b = module(b);
	return (a > b) ? a : b;
}

void	draw_line(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = x1 - x;
	y_step = y1 - y;

	max = maximum(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}

}