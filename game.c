/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:15:52 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/27 20:58:30 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	move_up(t_vars *vars)
// {
// 	vars->img->j -= 1;
// 	background(vars, img);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, img->i * img->img_width, img->j * img->img_height);
// 	return (0);
// }
// void move_down(t_vars *vars)

// 	{
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, img->i * img->img_width, img->j * img->img_height);
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, img->i * img->img_width, img->j * img->img_height);
// 	}
// void move_right(t_vars *vars)

// 	{
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, img->i * img->img_width, img->j * img->img_height);
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, img->i * img->img_width, img->j * img->img_height);
// 	}

// void move_left(t_vars *vars)

// 	{
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, img->i * img->img_width, img->j * img->img_height);
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, img->i * img->img_width, img->j * img->img_height);
// 	}
int	keypress(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(0);
// 	else if (keycode == 126 || keycode == 13)
// 		move_up(vars);
// 	else if (keycode == 125 || keycode == 1)
// 		move_down(vars);
// 	else if (keycode == 124 || keycode == 2)
// 		move_right(vars);
// 	else if (keycode == 123 || keycode == 0)
// 		move_left(vars);
// 	return (0);
 }
