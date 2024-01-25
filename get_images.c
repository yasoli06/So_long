/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:30:46 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/25 18:57:39 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closes(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	get_images(t_vars *vars, t_img	*img)
{
	int		y;
	int		x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '1')
				img->img_path = "mandatory/textures/Tree.xpm";
			if (vars->map[y][x] == 'C')
				img->img_path = "mandatory/textures/Huevo.xpm";
			if (vars->map[y][x] == 'P')
				img->img_path = "mandatory/textures/Dino.xpm";
			if (vars->map[y][x] == 'E')
				img->img_path = "mandatory/textures/House.xpm";
			vars->img = mlx_xpm_file_to_image(vars->mlx, img->img_path,
					&img->img_width, &img->img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x
				* img->img_width, y * img->img_height);
			x++;
		}
		y++;
	}
}

void	background(t_vars *vars, t_img	*img)
{
	int		y;
	int		x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			img->img_path = "mandatory/textures/Grass1.xpm";
			vars->img = mlx_xpm_file_to_image(vars->mlx, img->img_path,
					&img->img_width, &img->img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x
				* img->img_width, y * img->img_height);
			x++;
		}
		y++;
	}
}

void	init_game(t_vars *vars, t_img	*img)
{
	img->img_width = 32;
	img->img_height = 32;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map_width * img->img_width,
			vars->map_height * img->img_height, "joguinho");
	background(vars, img);
	get_images(vars, img);
	mlx_hook(vars->win, 2, 1L << 0, closes, &vars);
	mlx_loop(vars->mlx);
}
