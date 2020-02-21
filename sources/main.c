/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:49:18 by marrow            #+#    #+#             */
/*   Updated: 2020/02/21 23:06:39 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** This function just for Norm
*/

t_fdf	*new_struct(t_fdf *data)
{
	data->shift_x = 150;
	data->shift_y = 10;
	data->zoom = 20;
	data->projection = 0;
	return (data);
}

int		main(int ac, char **av)
{
	t_fdf		*data;

	if (ac != 2)
		ft_putstr("usage: ./fdf <file_name>");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->p = (t_coord *)malloc(sizeof(t_coord));
	read_file(av[1], data);
	new_struct(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	draw(data);
	setup_controls(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
