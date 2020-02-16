/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 06:20:56 by marrow            #+#    #+#             */
/*   Updated: 2020/02/16 06:22:22 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

typedef struct		s_fdf
{
	int				width;
	int				height;
	int				**z_matrix;

	void			**mlx_ptr;
	void			**win_ptr;
}					t_fdf;

#endif
