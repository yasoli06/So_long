/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:35:54 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/25 19:18:38 by yaolivei         ###   ########.fr       */
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
	printf("%s\n", "name_is_correct");
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
	printf("%s\n", "tenemos raw_map");
}

char	**load_map(int argc, char **argv, t_vars *vars)
{
	char	*raw_map;
	char	**map;

	if (argc != 2 || !map_name_is_correct(argv[1]))
		return (write(2, "Erro\n", 6), NULL);
	raw_map = get_raw_map(argv[1]);
	if (!raw_map)
		return (write(2, "Erro1\n", 6), NULL);
	if (!checks_in_raw_map_are_valids(raw_map, vars))
	{
		free(raw_map);
		return (write(2, "Erro2\n", 6), NULL);
	}
	map = ft_split(raw_map, '\n');
	if (!map)
	{
		free(raw_map);
		return (write(2, "Erro3\n", 6), NULL);
	}
	return (map);
	printf("%s\n", "se carga el mapa");
}

int	exit_finder(char **map, int x, int y, t_vars *vars)
{
	int		e;
	int		c;

	e = 0;
	c = 0;
	if (map[y][x] == 'E')
		e++;
	if (map[y][x] == 'C')
		c++;
	if (map[y][x] == '1')
		return (0);
	// if (e == 1 && c == vars->collect)
	// 	return (1);
	map[y][x] = '1';
	if (exit_finder(map, x - 1, y, vars) == 1)
		return (1);
	if (exit_finder(map, x + 1, y, vars) == 1)
		return (1);
	if (exit_finder(map, x, y - 1, vars) == 1)
		return (1);
	if (exit_finder(map, x, y + 1, vars) == 1)
		return (1);
	return (1);
	printf("%s\n", "exit es ok");
}

char	**map(int argc, char **argv, t_vars *vars)
{
	vars->x = -1;
	vars->y = 0;
	vars->map = load_map(argc, argv, vars);
	while (vars->map[vars->y])
	{
		vars->x = -1;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'P')
				break ;
		}
		if (vars->map[vars->y][vars->x] == 'P')
			break ;
		vars->y++;
	}
	if (vars->map[vars->y] == NULL || vars->map[vars->y][vars->x] != 'P')
	{
		free_map(vars->map);
		return (NULL);
	}
	if (!exit_finder(vars->map, vars->x, vars->y, vars))
		return (write(1, "Error_ff\n", 9), NULL);
	free(vars->map);
	vars->map = load_map(argc, argv, vars);
	return (vars->map);
}
