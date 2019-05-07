/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:20:12 by astripeb          #+#    #+#             */
/*   Updated: 2019/03/20 19:07:14 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

t_map	*read_stdin(void)
{
	t_map	*map_opt;
	int		n;
	int		fd;
	char	c;
	char	temp_map[9];

	ft_strncpy(temp_map, "temp_map", 8);
	if ((fd = open(temp_map, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU)) > 0)
	{
		while ((n = read(0, &c, 1)) > 0)
		{
			write(fd, &c, 1);
		}
	}
	close(fd);
	map_opt = map_options(temp_map);
	if (map_opt == NULL)
		return (NULL);
	return (map_opt);
}
