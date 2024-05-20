/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:15:52 by yaolivei          #+#    #+#             */
/*   Updated: 2024/02/26 17:02:46 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars)
{
	if (vars->map[vars->y - 1][vars->x] != '1')
	{
		if (vars->map[vars->y][vars->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->y - 1][vars->x] = '0';
		}
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->grass, vars->x
				* vars->pos_w, vars->y * vars->pos_h);
		vars->y --;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		if (vars->map[vars->y][vars->x] == 'E' && vars->collect == 0)
			exit_win(vars);
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->dino,
				vars->x * vars->pos_w, vars->y * vars->pos_h);
	}
}

void	move_down(t_vars *vars)
{
	if (vars->map[vars->y + 1][vars->x] != '1')
	{
		if (vars->map[vars->y][vars->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->y - 1][vars->x] = '0';
		}
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->grass, vars->x
				* vars->pos_w, vars->y * vars->pos_h);
		vars->y++;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		if (vars->map[vars->y][vars->x] == 'E' && vars->collect == 0)
			exit_win(vars);
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->dino,
				vars->x * vars->pos_w, vars->y * vars->pos_h);
	}
}

void	move_right(t_vars *vars)
{
	if (vars->map[vars->y][vars->x + 1] != '1')
	{
		if (vars->map[vars->y][vars->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->y][vars->x] = '0';
		}
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->grass, vars->x
				* vars->pos_w, vars->y * vars->pos_h);
		vars->x++;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		if (vars->map[vars->y][vars->x] == 'E' && vars->collect == 0)
			exit_win(vars);
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->dino,
				vars->x * vars->pos_w, vars->y * vars->pos_h);
	}
}

void	move_left(t_vars *vars)
{
	if (vars->map[vars->y][vars->x - 1] != '1')
	{
		if (vars->map[vars->y][vars->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->y][vars->x] = '0';
		}
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->grass, vars->x
				* vars->pos_w, vars->y * vars->pos_h);
		vars->x--;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		if (vars->map[vars->y][vars->x] == 'E' && vars->collect == 0)
			exit_win(vars);
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->dino_tras,
				vars->x * vars->pos_w, vars->y * vars->pos_h);
	}
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit_me(vars);
	else if (keycode == 126 || keycode == 13)
		move_up(vars);
	else if (keycode == 125 || keycode == 1)
		move_down(vars);
	else if (keycode == 124 || keycode == 2)
		move_right(vars);
	else if (keycode == 123 || keycode == 0)
		move_left(vars);
	return (0);
}
