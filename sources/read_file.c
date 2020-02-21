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
	while (get_next_line(fd, &line))
	{
		tmp = data->width;
		data->width = ft_count_words(line, ' ');
		if (tmp != data->width)
			return (0);
		data->height++;
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

int			valid(char *split_str)
{
	int 	char_index_minus;
	int		char_index_plus;
	int		count_space;
	int		count_comma;

	char_index_minus = ft_strchri(split_str, '-');
	char_index_plus = ft_strchri(split_str, '+');
	count_space = ft_count_words(split_str, ' ');
	count_comma = ft_count_words(split_str, ',');
	if (count_space != 0 || count_comma != 2)
		return (0);
	if ((char_index_minus != -1 && char_index_minus != 0) || \
	(char_index_plus != -1 && char_index_plus != 0))
		return (0);
	return (1);
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
	while (get_next_line(fd, &line))
	{
	    if (valid(line) == 0)
	        return (0);
		get_applicata(data->value[i], line);
		free(line);
		i++;
	}
	close(fd);
	return (1);
}
