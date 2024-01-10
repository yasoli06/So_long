/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:03:01 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/09 19:55:37 by yaolivei         ###   ########.fr       */
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
	i2 = ft_strlen((const char *)ptr2); //pq calculo la longitud de const char?
	while (i < n + 1)
	{
		if (ptr1[i1] != ptr2[i2])
			return (ptr1[i1] - ptr2[i2]);
		if (i1 == 0 || i2 == 0)
			break ;
		i++;
		i1--;
		i2--;
	}
	if (i < n)
		return (-1);
	return (0);
}
