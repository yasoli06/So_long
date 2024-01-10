/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:40:47 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/10 17:14:13 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (raw_map);
}

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

char	**get_map(int argc, char **argv, t_vars *vars)
{
	char	*raw_map;
	char	**map;

	if (argc != 2 || !map_name_is_correct(argv[1]))
		return (write(2, "Error\n", 6), NULL);
	raw_map = get_raw_map(argv[1]);
	if (!raw_map)
		return (write(2, "Error\n", 6), NULL);
	if (!checks_in_raw_map_are_valids(raw_map, vars))
	{
		free(raw_map);
		return (write(2, "Error\n", 6), NULL);
	}
	map = ft_split(raw_map, '\n');
	if (!map)
	{
		free(raw_map);
		return (write(2, "Error\n", 6), NULL);
	}
	if (!checks_in_final_map(map, vars, raw_map))
	{
		free(raw_map);
		return (write(2, "Error\n", 6), NULL);
	}
	return (map);
}
