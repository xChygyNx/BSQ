/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:50:13 by pcredibl          #+#    #+#             */
/*   Updated: 2019/03/20 16:07:04 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int		check_square(t_sqr *s_stc, char obs, char **map)
{
	int		y;
	int		x;

	x = s_stc->x;
	while (x < s_stc->x + s_stc->side)
	{
		y = s_stc->y;
		while (y < s_stc->y + s_stc->side)
		{
			if (map[x][y] == obs)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	try_square(int x, int y, char **map, t_map *ms)
{
	int complete;

	complete = tripple_loop(x, y, map, ms);
	if (complete == 0)
	{
		x = 0;
		while (map[x] != 0)
		{
			y = 0;
			while (map[x][y] != '\0')
			{
				ft_putchar(map[x][y]);
				y++;
			}
			ft_putchar('\n');
			x++;
		}
	}
	free(ms);
}

t_sqr	*square_structure(int x, int y, int side)
{
	t_sqr	*square_strc;

	square_strc = (t_sqr*)malloc(sizeof(t_sqr));
	square_strc->x = x;
	square_strc->y = y;
	square_strc->side = side;
	return (square_strc);
}
