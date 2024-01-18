/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:41:10 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/18 15:20:35 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	map(argc, argv, vars);
	return (0);
}
	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1000, 1000, "Joguinho"); //cria a janela
	// vars.mlx = mlx;
	// vars.win = mlx_win;
	// img.img = mlx_new_image(mlx, 1000, 1000); //cria a imagem
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian); //pega o endereço da imagem
	// y = 0;
	// color = 0x00FF0000;
	// while (y < 1000)
	// {
	// 	x = 0;
	// 	while (x < 1000)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, color);
	// 		x++;
	// 	}
	// 	y++;
	// 	color++;
	// }
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_hook(mlx_win, 2, 1L<<0, close, &vars);
	// mlx_key_hook(vars.win, key_hook, &vars); //quantas vezes a tecla foi pressionada
	// mlx_loop(vars.mlx);
