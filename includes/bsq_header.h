/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:32:55 by astripeb          #+#    #+#             */
/*   Updated: 2019/03/20 16:30:11 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_HEADER_H
# define BSQ_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_map
{
	int			height;
	int			length;
	char		empty;
	char		obstacle;
	char		full;
}				t_map;

typedef struct	s_sqr
{
	int			x;
	int			y;
	int			side;
}				t_sqr;

void			ft_putchar(char c);

void			ft_putstr(char *str);

char			**map_read(char *filename, t_map *map);

void			print_array(t_sqr *sqr_stc, char **map, t_map *map_str);

void			try_square(int x_s, int y_s, char **map, t_map *map_struct);

int				ft_atoi(char *str);

t_map			*map_options(char *str);

t_sqr			*square_structure(int x, int y, int side);

int				min(int a, int b);

t_map			*map_options(char *str);

char			*parse_file(char *filename);

void			int_to_str(char *str, int nbr);

void			ft_strncpy(char *dest, char *src, int n);

int				check_square(t_sqr *sqr, char obs, char **map);

void			free_all(char **map, t_map *map_opr);

int				val_map_s(t_map *map_opt, char **map);

int				val_map_c(t_map *map_opr, char **map);

t_map			*read_stdin(void);

int				tripple_loop(int x, int y, char **map, t_map *ms);

void			read_from_file(t_map *map_opt, char *filename);
#endif
