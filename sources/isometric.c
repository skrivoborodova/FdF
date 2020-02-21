/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:44:25 by oearlene          #+#    #+#             */
/*   Updated: 2020/02/21 22:57:37 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	choose_projection(int key, t_fdf *data)
{
	if (key == 7)
		data->projection = 1;
	else if (key == 6)
		data->projection = 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
}

void	isometric(float *x, float *y, int z)
{
	double	angle;

	angle = 0.8;
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}
