/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:03:01 by yaolivei          #+#    #+#             */
/*   Updated: 2024/02/26 14:22:16 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strnendcmp(char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;
	int				i1;
	int				i2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i1 = ft_strlen((const char *)ptr1);
	i2 = ft_strlen((const char *)ptr2);
	while (i < n + 1)
	{
		if (ptr1[i1] != ptr2[i2])
			return (ptr1[i1] - ptr2[i2]);
		i++;
		i1--;
		i2--;
	}
	if (i < n)
		return (-1);
	return (0);
}

int	count_char(char c, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	count_char_map(char c, char **map)
{
	int	n;
	int	j;

	n = 0;
	j = 0;
	while (map[j])
	{
		n = n + count_char(c, map[j]);
		j++;
	}
	return (n);
}

void	p_position(t_vars *vars)
{
	vars->pos_h = 32;
	vars->pos_w = 32;
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
}
