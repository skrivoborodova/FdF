/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:41:39 by oearlene          #+#    #+#             */
/*   Updated: 2020/02/21 00:44:19 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		choose_colour(t_coord *p, float x1, float y1, t_fdf *data)
{
	int		z;
	int		z1;

	z = data->value[(int)p->y][(int)p->x];
	z1 = data->value[(int)y1][(int)x1];
	if (z > 0 || z1 > 0)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}

