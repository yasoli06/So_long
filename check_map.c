/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:15:43 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/25 19:15:19 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	raw_map_is_rectangular(char *raw_map, t_vars *vars)
{
	int	count_fila;
	int	pos;

	vars->map_width = 0;
	vars->map_height = 0;
	while (raw_map[vars->map_width] != '\n' && raw_map[vars->map_width] != '\0')
		vars->map_width++;
	pos = 0;
	while (raw_map[pos] != '\0')
	{
		vars->map_height++;
		count_fila = 0;
		while (raw_map[pos + count_fila] != '\n'
			&& raw_map[pos + count_fila] != '\0')
			count_fila++;
		if (count_fila != vars->map_width)
			return (0);
		pos = pos + count_fila;
		if (raw_map[pos] == '\n')
			pos++;
	}
	printf("%s", "mapa es rectangular");
	return (1);
}

int	is_closed_map(char **map, t_vars *vars)
{
	int		x;
	int		y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[0][x] != '1' || map[vars->map_height - 1][x] != '1')
				return (0);
			x++;
		}
		y++;
		while (y < vars->map_height)
		{
			if (map[y][0] != '1' || map[y][vars->map_width - 1] != '1')
				return (0);
			y++;
		}
	}
	printf("%s", "mapa es closed");
	return (1);
}

int	check_min_posible_map(t_vars *vars)
{
	if (vars->map_height < 3 || vars->map_width < 3)
		return (0);
	if (vars->map_height * vars->map_width < 15)
		return (0);
	printf("%s", "min posible es ok");
	return (1);
}

int	check_only_valid_character(char *raw_map, t_vars *vars)
{
	int	i;

	i = 0;
	while (raw_map[i] != '\0')
	{
		if (raw_map[i] != 'C' && raw_map[i] != 'P' && raw_map[i] != '1'
			&& raw_map[i] != '0' && raw_map[i] != 'E' && raw_map[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	if (count_char('E', raw_map) != 1 && count_char('P', raw_map) != 1)
		return (0);
	vars->collect = (count_char('C', raw_map));
	if (vars->collect < 1)
		return (0);
	printf("%s", "only_valid_character");
	return (1);
}

int	checks_in_raw_map_are_valids(char *raw_map, t_vars *vars)
{
	if (!raw_map_is_rectangular(raw_map, vars))
		return (0);
	printf("%s", "ok1");
	if (!is_closed_map(vars->map, vars))
		return (0);
	printf("%s", "ok2");
	if (!check_min_posible_map(vars))
		return (0);
	printf("%s", "ok3");
	if (!check_only_valid_character(raw_map, vars))
		return (0);
	printf("%s", "ok4");
	return (1);
}
