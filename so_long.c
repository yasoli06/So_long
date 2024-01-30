/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:41:10 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/30 21:10:39 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (1);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (free(img), 1);
	final_map(argc, argv, vars);
	init_game(vars, img);
	return (0);
}
