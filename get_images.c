/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:29:08 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/28 19:00:23 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_vars *vars, t_img *img, char *path)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, path, &img->img_width,
			&img->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		img->i * img->img_width, img->j * img->img_height);
}

void	change_image(t_vars *vars, t_img *img, char *path)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, path, &img->img_width,
			&img->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x * img->img_width, vars->y * img->img_height);
}

void	background(t_vars *vars, t_img	*img)
{
	img->j = 0;
	while (vars->map[img->j])
	{
		img->i = 0;
		while (vars->map[img->j][img->i])
		{
			put_image(vars, img, "texture/Grass1.xpm");
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
				put_image(vars, img, "texture/Tree.xpm");
			if (vars->map[img->j][img->i] == 'C')
				put_image(vars, img, "texture/Huevo.xpm");
			if (vars->map[img->j][img->i] == 'P')
				put_image(vars, img, "texture/Dino.xpm");
			if (vars->map[img->j][img->i] == 'E')
				put_image(vars, img, "texture/Cave.xpm");
			img->i++;
		}
		img->j++;
	}
}

void	init_game(t_vars *vars, t_img *img)
{
	img->img_width = 32;
	img->img_height = 32;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width * img->img_width,
			vars->height * img->img_height, "joguinho");
	background(vars, img);
	get_images(vars, img);
	mlx_hook(vars->win, 2, 1L << 0, keypress, vars);
	mlx_hook(vars->win, 17, 1L << 2, exit_me, vars);
	mlx_loop(vars->mlx);
}
