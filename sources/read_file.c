/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:40:14 by marrow            #+#    #+#             */
/*   Updated: 2020/02/19 23:54:46 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_height_width(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int 	tmp;

	data->height = 0;
	data->width = 0;
	tmp = 0;
	fd = open(file_name, O_RDONLY);
	tmp = ft_count_words(line, ' ');
	while (get_next_line(fd, &line) > 0)
	{
        tmp = data->width;
		data->width = ft_count_words(line, ' ');
		data->height++;
        if (tmp != data->width && data->height > 1)
            return (0);
		free(line);
	}
	close(fd);
	return (1);
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


int			read_file(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	if (!(get_height_width(file_name, data)))
		return (0);
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
	while (get_next_line(fd, &line) > 0)
	{
		get_applicata(data->value[i], line);
		free(line);
		i++;
	}
	close(fd);
	return (1);
}
