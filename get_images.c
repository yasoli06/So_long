/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:29:08 by yaolivei          #+#    #+#             */
/*   Updated: 2024/02/26 17:33:51 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_vars *vars, t_img *img)
{
	img->img_width = 32;
	img->img_height = 32;
	vars->dino = mlx_xpm_file_to_image(vars->mlx, "texture/Dino.xpm",
			&img->img_width, &img->img_height);
	if (vars->dino == NULL)
		error_exit(vars);
	vars->huevo = mlx_xpm_file_to_image(vars->mlx, "texture/Huevo.xpm",
			&img->img_width, &img->img_height);
	if (vars->huevo == NULL)
		error_exit(vars);
	vars->cave = mlx_xpm_file_to_image(vars->mlx, "texture/Cave.xpm",
			&img->img_width, &img->img_height);
	if (vars->cave == NULL)
		error_exit(vars);
	vars->tree = mlx_xpm_file_to_image(vars->mlx, "texture/Tree.xpm",
			&img->img_width, &img->img_height);
	if (vars->tree == NULL)
		error_exit(vars);
	vars->grass = mlx_xpm_file_to_image(vars->mlx, "texture/Grass.xpm",
			&img->img_width, &img->img_height);
	vars->dino_tras = mlx_xpm_file_to_image(vars->mlx, "texture/Dino_tras.xpm",
			&img->img_width, &img->img_height);
	if (vars->grass == NULL || vars->dino == NULL)
		error_exit(vars);
}

void	background(t_vars *vars, t_img	*img)
{
	img->j = 0;
	while (vars->map[img->j])
	{
		img->i = 0;
		while (vars->map[img->j][img->i])
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->grass, img->i
				* img->img_width, img->j * img->img_height);
			img->i++;
		}
		img->j++;
	}
}

void	get_images(t_vars *vars, t_img	*img)
{
	img->j = 0;
	while (vars->map[img->j])
	{
		img->i = 0;
		while (vars->map[img->j][img->i])
		{
			if (vars->map[img->j][img->i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->tree,
					img->i * img->img_width, img->j * img->img_height);
			if (vars->map[img->j][img->i] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->huevo,
					img->i * img->img_width, img->j * img->img_height);
			if (vars->map[img->j][img->i] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->dino,
					img->i * img->img_width, img->j * img->img_height);
			if (vars->map[img->j][img->i] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->cave,
					img->i * img->img_width, img->j * img->img_height);
			img->i++;
		}
		img->j++;
	}
}

void	init_game(t_vars *vars, t_img *img)
{
	img->img_width = 32;
	img->img_height = 32;
	vars->x = 0;
	vars->y = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width * img->img_width,
			vars->height * img->img_height, "joguinho");
	put_image(vars, img);
	background(vars, img);
	get_images(vars, img);
	p_position(vars);
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 17, 1L << 2, exit_me, vars);
	mlx_loop(vars->mlx);
}
