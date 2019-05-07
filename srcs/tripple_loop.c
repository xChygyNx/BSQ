/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tripple_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:26:20 by pcredibl          #+#    #+#             */
/*   Updated: 2019/03/20 16:08:05 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int		tripple_loop(int x, int y, char **map, t_map *ms)
{
	t_sqr	*sqr_strc;
	int		cmp;
	int		side;

	side = min(ms->height, ms->length) + 1;
	cmp = 0;
	while (--side > 0 && cmp == 0)
	{
		x = -1;
		while ((++x <= ms->height - side) && cmp == 0)
		{
			y = -1;
			while (++y <= ms->length - side)
			{
				sqr_strc = square_structure(x, y, side);
				if ((cmp = check_square(sqr_strc, ms->obstacle, map)) == 1)
				{
					print_array(sqr_strc, map, ms);
					break ;
				}
				free(sqr_strc);
			}
		}
	}
	return (cmp);
}
