/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:49:18 by marrow            #+#    #+#             */
/*   Updated: 2020/02/19 00:22:53 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int 	deal_key(int key, void *data)
{
	printf("%d", key);
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf		*data;
	int			i;
	int 		j;

	i = 0;
	j = 0;
	if (ac != 2)
		ft_putstr("usage: ./fdf <file_name>");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(av[1], data);

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr , 1000, 1000, "FDF");

	draw_line(10, 10, 600, 300, data);

	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);

	return (0);
}