/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:35:54 by yaolivei          #+#    #+#             */
/*   Updated: 2024/02/26 16:05:51 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_name_is_correct(char *map_path)
{
	if (ft_strlen(map_path) < 5)
		return (0);
	if (strnendcmp(map_path, ".ber", 4) != 0)
		return (0);
	return (1);
}

char	*get_raw_map(char *map_path)
{
	int		fd;
	char	*line;
	char	*raw_map;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	raw_map = malloc(sizeof(char *) * 1);
	raw_map[0] = '\0';
	while (line)
	{
		raw_map = gnl_strjoin(raw_map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (raw_map);
}

char	**get_map(int argc, char **argv, t_vars *vars)
{
	char	*raw_map;
	char	**map;

	if (argc != 2 || !map_name_is_correct(argv[1]))
	{
		write(1, "Error1\nInvalid file\n", 21);
		exit (1);
	}
	raw_map = get_raw_map(argv[1]);
	if (!raw_map)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	map = ft_split(raw_map, '\n');
	if (!final_check(map, vars, raw_map))
	{
		write(1, "Error2\nInvalid map\n", 20);
		free(raw_map);
		exit (1);
	}
	free(raw_map);
	return (map);
}

void	flood_fill(char **map, int x, int y, t_vars *vars)
{
	if (x < 0 || y < 0 || x > vars->width || y > vars->height
		|| map[y][x] == '1' || map[y][x] == '.')
		return ;
	map[y][x] = '.';
	flood_fill(map, x + 1, y, vars);
	flood_fill(map, x - 1, y, vars);
	flood_fill(map, x, y + 1, vars);
	flood_fill(map, x, y - 1, vars);
}

char	**final_map(int argc, char **argv, t_vars *vars)
{
	vars->x = 0;
	vars->y = 0;
	vars->moves = 0;
	vars->map = get_map(argc, argv, vars);
	p_position(vars);
	flood_fill(vars->map, vars->x, vars->y, vars);
	if (count_char_map('E', vars->map) > 0
		|| count_char_map('C', vars->map) > 0)
	{
		write(1, "Error\nInvalid exit\n", 19);
		free_map(vars->map);
		return (NULL);
	}
	free_map(vars->map);
	vars->map = get_map(argc, argv, vars);
	return (vars->map);
}
