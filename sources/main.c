/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:49:18 by marrow            #+#    #+#             */
/*   Updated: 2020/02/21 23:25:04 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** This function just for Norm
*/

t_fdf	*new_struct(t_fdf *data)
{
	data->shift_x = 450;
	data->shift_y = 200;
	data->zoom = 20;
	data->projection = 0;
	return (data);
}

void	print_menu(t_fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 65, y += 20, 0xffffff, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, 0xffffff, "Zoom: Q for +, E for -");
	mlx_string_put(mlx, win, 15, y += 30, 0xffffff, "Move: W,S,A,D");
	mlx_string_put(mlx, win, 15, y += 30, 0xffffff, "Projection");
	mlx_string_put(mlx, win, 15, y += 30, 0xffffff, "ISO: Z Key");
	mlx_string_put(mlx, win, 15, y += 30, 0xffffff, "Parallel: X Key");
	mlx_string_put(mlx, win, 15, y += 30, 0xffffff, "Close: ESC");
}

int		main(int ac, char **av)
{
	t_fdf		*data;

	if (ac != 2)
		ft_putstr("usage: ./fdf <file_name>");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->p = (t_coord *)malloc(sizeof(t_coord));
	if ((read_file(av[1], data) == 0))
	{
		ft_putstr("error");
		return (0);
	}
	new_struct(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	draw(data);
	setup_controls(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
