/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:04:22 by astripeb          #+#    #+#             */
/*   Updated: 2019/03/20 16:16:40 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void		read_from_file(t_map *map_opt, char *filename)
{
	char **map;

	if (map_opt != NULL)
	{
		map = map_read(filename, map_opt);
		if (map != NULL && val_map_s(map_opt, map) == 0\
				&& val_map_c(map_opt, map) == 0)
		{
			try_square(0, 0, map, map_opt);
		}
	}
}
