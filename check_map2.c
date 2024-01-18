/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:55:02 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/18 17:13:21 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_finder(char **map, int x, int y)
{
	if (map[x][y] == 'E')
	{
		while (vars->count == 0)
			return (1);
	}
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

int	is_closed_map(char **map, t_vars *vars)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
		if (map[0][i++] != '1')
			return (0);
	i = 0;
	while (map[vars->map_height - 1][i] != '\0')
	{
		if (map[vars->map_height - 1][i++] != '1')
			return (0);
	}
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i++][0] != '1')
			return (0);
	}
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i++][vars->map_width - 1] != '1')
			return (0);
	}
	return (1);
}

int	checks_in_final_map(char **map, t_vars *vars)
{
	if (!is_closed_map(map, vars))
		return (0);
	if (!exit_finder(map, vars->x, vars->y))
		return (0);
	free_map(map);
	return (1);
}
