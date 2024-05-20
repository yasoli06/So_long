/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:14:13 by yaolivei          #+#    #+#             */
/*   Updated: 2023/11/06 17:22:27 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int			count;
	long int	n;

	n = nb;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar ('-');
		n *= -1;
	}
	if (n <= 9)
	{
		count += ft_putchar (n + '0');
	}
	else
	{
		count += ft_putnbr (n / 10);
		if (ft_putchar (n % 10 + '0') == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putnbr_uns(unsigned int nb)
{
	int			count;

	count = 0;
	if (nb <= 9)
	{
		if (ft_putchar (nb + '0') == -1)
			return (-1);
		count++;
	}
	else
	{
		count += ft_putnbr_uns (nb / 10);
		if (ft_putchar (nb % 10 + '0') == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putnbr_hx(unsigned int hx, char *base)
{
	int			count;

	count = 0;
	if (hx < 16)
	{
		if (ft_putchar(base[hx % 16]) == -1)
			return (-1);
		count++;
	}
	else
	{
		count += ft_putnbr_hx (hx / 16, base);
		count += ft_putchar (base [hx % 16]);
	}
	return (count);
}

int	ft_putptr(unsigned long hx, char *base)
{
	int			count;

	base = "0123456789abcdef";
	count = 0;
	if (hx < 16)
	{
		ft_putstr("0x");
		ft_putchar(base[hx % 16]);
		count++;
	}
	else
	{
		count += ft_putptr (hx / 16, base);
		count += ft_putchar (base [hx % 16]);
	}
	return (count);
}
