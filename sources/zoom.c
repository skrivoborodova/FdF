/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:45:57 by oearlene          #+#    #+#             */
/*   Updated: 2020/02/21 00:46:29 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom(t_coord *ptr, float *x1, float *y1, t_fdf *data)
{
	data->zoom = 20;
	ptr->x *= data->zoom;
	ptr->y *= data->zoom;
	*x1 *= data->zoom;
	*y1 *= data->zoom;
}
