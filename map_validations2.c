/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:55:02 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/10 17:21:46 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checks_in_final_map(char **map, t_vars *vars, char *raw_map)
{
	if (!is_closed_map(map, vars))
		return (0);
	// Encontrar las cordenadas x e y de P
	//if (!exit_finder(map, vars->player_x, vars->player_y))
	if (!exit_finder(map, 3, 3))
		return (0);
	// vars->map = free_map(map);
	vars->map = ft_split(raw_map, '\n');
	printf("He encontrado salida\n");
	return (1);
}

int	checks_in_raw_map_are_valids(char *raw_map, t_vars *vars)
{
	if (raw_map_is_rectangular(raw_map, vars) == 0)
		return (0);
	if (!check_min_posible_map(vars))
		return (0);
	if (!check_only_valid_character(raw_map))
		return (0);
	if (!min_quantity_of_some_chars(raw_map))
		return (0);
	return (1);
}

int	exit_finder(char **map, int x, int y)
{
	printf("(%d, %d),", x, y);
	if (map[x][y] == 'E')
		return (1);
	if (map[x][y] == '1')
		return (0);
	map[x][y] = '1';
	if (exit_finder(map, x, y + 1) == 1)
		return (1);
	if (exit_finder(map, x - 1, y) == 1)
		return (1);
	if (exit_finder(map, x, y - 1) == 1)
		return (1);
	if (exit_finder(map, x + 1, y) == 1)
		return (1);
	return (0);
}
