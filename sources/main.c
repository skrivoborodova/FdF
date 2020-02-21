/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:49:18 by marrow            #+#    #+#             */
/*   Updated: 2020/02/21 03:52:22 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	deal_key(int key, void *data)
{
	printf("%d\n", key);
/*
	if (key == 126) //up
		data->shift_y -= 10;
	if (key == 125) //down
		data->shift_y += 10;
	if (key == 124) //right
		data->shift_x -= 10;
	if (key == 123) //left
		data->shift_x += 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
 */
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf		*data;

	if (ac != 2)
		ft_putstr("usage: ./fdf <file_name>");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->p = (t_coord *)malloc(sizeof(t_coord));
	read_file(av[1], data);

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr , 1000, 1000, "FDF");

	draw(data);

	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);


}