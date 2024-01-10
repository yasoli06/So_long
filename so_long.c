/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:41:10 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/10 16:21:38 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	(void) keycode;
	(void) vars;
	printf("Hello from key_hook!\n");
	return (0);
}

int	closed(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	render_next_frame(void *YourStruct);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	main(int argc, char **argv)
{
	/*void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;
	int		color;*/
	t_vars	vars;

	vars.map = get_map(argc, argv, &vars);
	if (!vars.map)
		return (0);
	//Printar el mapa por pantalla
}
	// mlx = mlx_init(); //inicializa a conexão
	// mlx_win = mlx_new_window(mlx, 1000, 1000, "Joguinho"); //cria a janela
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
