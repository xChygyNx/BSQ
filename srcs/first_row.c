/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:42:09 by astripeb          #+#    #+#             */
/*   Updated: 2019/03/20 16:18:39 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

t_map		*map_options(char *av)
{
	t_map	*map_opt;
	int		i;
	char	*str;

	str = parse_file(av);
	if (str == NULL)
		return (NULL);
	map_opt = (t_map*)malloc(sizeof(t_map));
	if (map_opt == NULL)
		return (NULL);
	map_opt->height = ft_atoi(str);
	i = 0;
	while (str[i] > 47 && str[i] < 58)
		++i;
	map_opt->empty = str[i++];
	map_opt->obstacle = str[i++];
	map_opt->full = str[i++];
	map_opt->length = ft_atoi(&str[i]);
	if (map_opt->height <= 0 || map_opt->length <= 0)
	{
		write(2, "map error\n", 10);
		free(map_opt);
		return (NULL);
	}
	return (map_opt);
}

char		*parse_file(char *filename)
{
	int		fd;
	int		m;
	char	*str;
	char	c;
	int		i;

	str = (char*)malloc(sizeof(char) * 30);
	if (str == NULL)
		return (NULL);
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		write(2, "map error\n", 10);
		return (NULL);
	}
	i = 0;
	while (((read(fd, &c, 1)) > 0) && c != '\n')
		str[i++] = c;
	m = 0;
	while (((read(fd, &c, 1)) > 0) && c != '\n')
		++m;
	int_to_str(&str[i], m);
	str[i + m] = '\0';
	close(fd);
	return (str);
}

void		int_to_str(char *str, int nbr)
{
	int		i;
	int		del;

	del = 1;
	while (nbr / del >= 10)
		del *= 10;
	i = 0;
	while (del > 0)
	{
		str[i] = 48 + (nbr / del % 10);
		++i;
		del /= 10;
	}
	str[i] = '\0';
}

void		ft_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
}
