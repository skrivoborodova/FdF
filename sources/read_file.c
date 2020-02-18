/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:40:14 by marrow            #+#    #+#             */
/*   Updated: 2020/02/18 23:44:48 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_height_width(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;

	data->height = 0;
	data->width = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (data->width == 0)
			data->width = ft_count_words(line, ' ');
		data->height++;
		free(line);
	}
	close(fd);
}

void		get_applicata(int *value_str, char *line)
{
	char	**split_str;
	int		i;

	i = 0;
	split_str = ft_strsplit(line, ' ');
	while (split_str[i])
	{
		value_str[i] = ft_atoi(split_str[i]);
		free((split_str[i]));
		i++;
	}
	ft_memdel((void **)&(split_str));
}

void		read_file(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	get_height_width(file_name, data);
	if (!(data->value = ft_memalloc(sizeof(int *) * (data->height))))
		exit(12);
	while (i < data->height)
	{
		if (!(data->value[i] = ft_memalloc(sizeof(int) * (data->width))))
			exit(12);
		i++;
	}
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		get_applicata(data->value[i], line);
		free(line);
		i++;
	}
	close(fd);
}
