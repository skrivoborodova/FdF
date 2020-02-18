/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:49:18 by marrow            #+#    #+#             */
/*   Updated: 2020/02/18 03:58:06 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d ", data->value[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free(data);
	return (0);
}