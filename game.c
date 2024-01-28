/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:15:52 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/28 21:23:53 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_vars *vars, t_img *img)
{
	if (vars->map[vars->y - 1][vars->x] == 'E' && vars->collect == 0)
	{
		write(1, "YOU WIN", 8);
		free(vars->map);
		exit(0);
	}
	if (vars->map[vars->y - 1][vars->x] != '1' \
		&& vars->map[vars->y - 1][vars->x] != 'E')
	{
		if(vars->map[vars->y - 1][vars->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->y - 1][vars->x] = '0';
		}
		change_image(vars, img, "texture/Grass1.xpm");
		vars->y -= 1;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		change_image(vars, img, "texture/Dino.xpm");
	}
	return (0);
}

int	move_down(t_vars *vars, t_img *img)
{
	if (vars->map[vars->y + 1][vars->x] == 'E' && vars->collect == 0)
	{
		write(1, "YOU WIN", 8);
		free(vars->map);
		exit(0);
	}
	if (vars->map[vars->y + 1][vars->x] != '1' \
		&& vars->map[vars->y + 1][vars->x] != 'E')
	{
		if(vars->map[vars->y + 1][vars->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->y + 1][vars->x] = '0';
		}
		change_image(vars, img, "texture/Grass1.xpm");
		vars->y += 1;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		change_image(vars, img, "texture/Dino.xpm");
	}
	return (0);
}

int	move_right(t_vars *vars, t_img *img)
{
	if (vars->map[vars->y][vars->x + 1] == 'E' && vars->collect == 0)
	{
		write(1, "YOU WIN", 8);
		free(vars->map);
		exit(0);
	}
	if (vars->map[vars->y][vars->x + 1] != '1' \
		&& vars->map[vars->y][vars->x + 1] != 'E')
	{
		if(vars->map[vars->y][vars->x + 1] == 'C')
		{
			vars->collect--;
			vars->map[vars->y][vars->x + 1] = '0';
		}
		change_image(vars, img, "texture/Grass1.xpm");
		vars->x += 1;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		change_image(vars, img, "texture/Dino.xpm");
	}
	return (0);
}
int	move_left(t_vars *vars, t_img *img)
{
	if (vars->map[vars->y][vars->x - 1] == 'E' && vars->collect == 0)
	{
		write(1, "YOU WIN", 8);
		free(vars->map);
		exit(0);
	}
	if (vars->map[vars->y][vars->x - 1] != '1' \
		&& vars->map[vars->y][vars->x - 1] != 'E')
	{
		if(vars->map[vars->y][vars->x - 1] == 'C')
		{
			vars->collect--;
			vars->map[vars->y][vars->x - 1] = '0';
		}
		change_image(vars, img, "texture/Grass1.xpm");
		vars->x -= 1;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		change_image(vars, img, "texture/Dino.xpm");
	}
	return (0);
}

int	keypress(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 126 || keycode == 13)
		move_up(vars, vars->img);
	else if (keycode == 125 || keycode == 1)
		move_down(vars, vars->img);
	else if (keycode == 124 || keycode == 2)
		move_right(vars, vars->img);
	else if (keycode == 123 || keycode == 0)
		move_left(vars, vars->img);
	return (0);
}
