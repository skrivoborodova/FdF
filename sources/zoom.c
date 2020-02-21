/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:45:57 by oearlene          #+#    #+#             */
/*   Updated: 2020/02/21 03:53:23 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
126 up
125 down
124 right
123 left
*/

void		shift(t_coord *p, float *x1, float *y1, t_fdf *data)
{
	data->shift_x = 150;
	data->shift_y = 150;
	p->x += data->shift_x;
	p->y += data->shift_y;
	*x1 += data->shift_x;
	*y1 += data->shift_y;
}


void		zoom(t_coord *ptr, float *x1, float *y1, t_fdf *data)
{
	data->zoom = 20;
	ptr->x *= data->zoom;
	ptr->y *= data->zoom;
	*x1 *= data->zoom;
	*y1 *= data->zoom;
}
