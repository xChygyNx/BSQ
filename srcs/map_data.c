/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:42:50 by astripeb          #+#    #+#             */
/*   Updated: 2019/03/20 16:16:19 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

char		**map_read(char *filename, t_map *map_opt)
{
	char	**map;
	int		i;
	int		fd;
	char	*buf;
	int		n;

	map = (char**)malloc(sizeof(char*) * (map_opt->height + 1));
	buf = (char*)malloc(sizeof(char) * (map_opt->length + 1));
	if (map == NULL || buf == NULL)
		return (NULL);
	i = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	while (((read(fd, &buf[0], 1)) > 0) && buf[0] != '\n')
		;
	while ((n = (read(fd, buf, map_opt->length + 1))) > 0)
	{
		map[i] = (char*)malloc(sizeof(char) * (map_opt->length + 1));
		ft_strncpy(map[i++], buf, map_opt->length);
	}
	map[i] = 0;
	close(fd);
	free(buf);
	return (map);
}

int			val_map_s(t_map *map_opt, char **map)
{
	int i;
	int j;

	i = 0;
	while (i < map_opt->height)
	{
		if ((i < (map_opt->height - 1)) && map[i] == 0)
		{
			write(2, "map error\n", 10);
			return (1);
		}
		j = 0;
		while (j < map_opt->length)
		{
			if ((j < (map_opt->length - 1)) && map[i][j] == '\0')
			{
				write(2, "map error\n", 11);
				return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

int			val_map_c(t_map *map_opt, char **map)
{
	int i;
	int j;

	i = 0;
	while (i < map_opt->height)
	{
		j = 0;
		while (j < map_opt->length)
		{
			if (map[i][j] != map_opt->empty && map[i][j] != map_opt->obstacle)
			{
				write(2, "map error\n", 10);
				return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}
