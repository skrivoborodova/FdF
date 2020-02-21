/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:49:18 by marrow            #+#    #+#             */
/*   Updated: 2020/02/20 23:19:30 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	deal_key(int key, void *data)
{
	printf("%d", key);
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf		*data;
	t_coord		*ptr;

	if (ac != 2)
		ft_putstr("usage: ./fdf <file_name>");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	ptr = (t_coord *)malloc(sizeof(t_coord));
	if ((read_file(av[1], data) == 0))
	{
	    ft_putstr("error");
	    return (0);
	}
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr , 1000, 1000, "FDF");

	draw(ptr ,data);

	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);
    return (0);
}