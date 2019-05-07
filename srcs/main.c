/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:25:28 by astripeb          #+#    #+#             */
/*   Updated: 2019/03/20 16:15:39 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int		main(int argc, char **argv)
{
	t_map	*map_opt;
	int		i;

	if (argc == 1)
	{
		map_opt = read_stdin();
		read_from_file(map_opt, "temp_map");
	}
	i = 1;
	while (i < argc)
	{
		map_opt = map_options(argv[i]);
		read_from_file(map_opt, argv[i]);
		++i;
	}
	return (0);
}
