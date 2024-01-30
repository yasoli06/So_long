/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:35:54 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/30 21:30:14 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_name_is_correct(char *map_path)
{
	size_t	len;

	len = ft_strlen(map_path);
	if (len < 5)
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

	fd = open (map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	raw_map = ft_strdup("");
	while (line)
	{
		raw_map = gnl_strjoin(raw_map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (raw_map);
}

char	**get_map(int argc, char **argv, t_vars *vars)
{
	char	*raw_map;
	char	**map;

	if (argc != 2 || !map_name_is_correct(argv[1]))
		write(2, "Error\n", 6);
	raw_map = get_raw_map(argv[1]);
	if (!raw_map)
		return (write(2, "Erro1\n", 6), NULL);
	map = ft_split(raw_map, '\n');
	if (!check_final_map(map, vars, raw_map))
	{
		return (write(2, "Erro2\n", 6), NULL);
	}
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
	while (vars->map[vars->y])
	{
		vars->x = 0;
		while (vars->map[vars->y][vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'P')
				break ;
			vars->x++;
		}
		if (vars->map[vars->y][vars->x] == 'P')
			break ;
		vars->y++;
	}
	flood_fill(vars->map, vars->x, vars->y, vars);
	if (count_char_map('E', vars->map) > 0
		|| count_char_map('C', vars->map) > 0)
		return (NULL);
	//free_map(vars->map);
	vars->map = get_map(argc, argv, vars);
	return (vars->map);
}
