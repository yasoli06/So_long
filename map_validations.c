/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:38:52 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/09 19:53:13 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (1);
}

int	check_min_posible_map(t_vars *vars)
{
	if (vars->map_height < 3 || vars->map_width < 3)
		return (0);
	if (vars->map_height * vars->map_width < 15)
		return (0);
	return (1);
}

int	check_only_valid_character(char *raw_map)
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
	return (1);
}

int	min_quantity_of_some_chars(char *raw_map)
{
	int	i;
	int	num_e;
	int	num_p;
	int	num_c;

	i = 0;
	num_e = 0;
	num_p = 0;
	num_c = 0;
	while (raw_map[i] != '\0')
	{
		if (raw_map[i] == 'P')
			num_p++;
		if (raw_map[i] == 'E')
			num_e++;
		if (raw_map[i] == 'C')
			num_c++;
		i++;
	}
	if (num_e != 1 || num_p != 1 || num_c < 1)
		return (0);
	return (1);
}
