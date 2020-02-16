/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:40:14 by marrow            #+#    #+#             */
/*   Updated: 2020/02/16 16:52:37 by marrow           ###   ########.fr       */
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
void	read_file(char *file_name, t_fdf *data)
{
	data->height = get_height(file_name);
}
