/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:40:14 by marrow            #+#    #+#             */
/*   Updated: 2020/02/18 02:24:24 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name,O_RDONLY);
	get_next_line(fd, &line);
	width = ft_count_words(line,' ');
	free(line);
	close(fd);
	return(width);
}
void 	get_applicata(int *value_str, char *line)
{
	char	**split_str;
	int		i;

	i = 0;
	split_str = ft_strsplit(line,' ');
	while (split_str[i])
	{
		value_str[i] = ft_atoi(split_str[i]);
		ft_memdel((void**)&(split_str[i]));
		i++;
	}
	ft_memdel((void **)split_str);
}
void	read_file(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	if (!(data->value = ft_memalloc(sizeof(int *) * (data->height))))
		exit(12);
	while (i <= data->height)
	{
		if (!(data->value[i] = ft_memalloc(sizeof(int *) * (data->width))))
			exit(12);
		i++;
	}
	fd = open(file_name,O_RDONLY);
	i = 0;
	while(get_next_line(fd, &line))
	{
		get_applicata(data->value[i], line);
		free(line);
		i++;
	}
	close(fd);
}
