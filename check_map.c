/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:15:43 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/28 16:08:13 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_is_rectangular(char **map, t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	while (map[0][i])
		i++;
	vars->width = i;
	j = 1;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i])
			i++;
		if (i != vars->width)
			return (0);
		j++;
	}
	vars->height = j;
	return (1);
}

int	check_is_closed(char **map, t_vars *vars)
{
	int		i;
	int		j;

	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i])
		{
			if (map[0][i] != '1' || map[vars->height - 1][i] != '1')
				return (0);
			i++;
		}
		j++;
		while (j < vars->height)
		{
			if (map[j][0] != '1' || map[j][vars->width - 1] != '1')
				return (0);
			j++;
		}
	}
	return (1);
}

int	check_min_size(t_vars *vars)
{
	if (vars->height < 3 || vars->width < 3)
		return (0);
	if (vars->height * vars->width < 15)
		return (0);
	return (1);
}

int	check_min_type_char(char *raw_map, t_vars *vars)
{
	int	i;

	i = 0;
	while (raw_map[i])
	{
		if (raw_map[i] != 'P' && raw_map[i] != 'E' && raw_map[i] != 'C'
			&& raw_map[i] != '1' && raw_map[i] != '0' && raw_map[i] != '\n')
			return (0);
		i++;
	}
	if (count_char('E', raw_map) != 1 && count_char('P', raw_map) != 1)
		return (0);
	vars->collect = (count_char('C', raw_map));
	if (vars->collect < 1)
		return (0);
	return (1);
}

int	check_final_map(char **map, t_vars *vars, char *raw_map)
{
	if (!check_is_rectangular(map, vars))
		return (0);
	if (!check_is_closed(map, vars))
		return (0);
	if (!check_min_size(vars))
		return (0);
	if (!check_min_type_char(raw_map, vars))
		return (0);
	return (1);
}
