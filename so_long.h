/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:55:53 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/10 17:17:21 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
}				t_vars;

char	**get_map(int argc, char **argv, t_vars *vars);
int		strnendcmp(char *s1, const char *s2, size_t n);
int		checks_in_raw_map_are_valids(char *raw_map, t_vars *vars);
int		checks_in_final_map(char **map, t_vars *vars, char*raw_map);
int		is_closed_map(char **map, t_vars *vars);
int		raw_map_is_rectangular(char *raw_map, t_vars *vars);
int		check_min_posible_map(t_vars *vars);
int		check_only_valid_character(char *raw_map);
int		min_quantity_of_some_chars(char *raw_map);
int		exit_finder(char **map, int x, int y);
char	*free_map(char **map);

#endif