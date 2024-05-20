/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:51:48 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/09 20:58:11 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

int	exit_win(t_vars *vars)
{
	write(1, "YOU WIN!\n", 9);
	free_map(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

int	exit_me(t_vars *vars)
{
	free_map(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	error_exit(t_vars *vars)
{
	write(1, "Error\n", 7);
	free_map(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}
