/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:56:22 by pcredibl          #+#    #+#             */
/*   Updated: 2019/03/20 18:50:26 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void	print_array(t_sqr *s_stc, char **map, t_map *map_struct)
{
	int		i;
	int		j;

	i = 0;
	while (i < map_struct->height)
	{
		j = 0;
		while (j < map_struct->length)
		{
			if ((i >= s_stc->x) && (i < s_stc->x + s_stc->side)\
					&& (j >= s_stc->y) && (j < s_stc->y + s_stc->side))
				ft_putchar(map_struct->full);
			else
				ft_putchar(map[i][j]);
			++j;
		}
		++i;
		ft_putchar('\n');
	}
}

void	free_all(char **map, t_map *map_opt)
{
	int i;

	i = 0;
	if (map != NULL)
	{
		while (map[i] != NULL || map[i] != 0)
		{
			free(map[i]);
			++i;
		}
	}
	free(map);
	if (map_opt != NULL)
		free(map_opt);
}
