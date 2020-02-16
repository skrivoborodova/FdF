/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:48:34 by marrow            #+#    #+#             */
/*   Updated: 2020/02/16 16:49:52 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *str, char c)
{
	size_t	word;
	size_t	i;
	size_t	test;

	i = 0;
	word = 0;
	test = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (test == 1 && str[i] == c)
			test = 0;
		if (test == 0 && str[i] != c)
		{
			test = 1;
			word++;
		}
		i++;
	}
	return (word);
}
