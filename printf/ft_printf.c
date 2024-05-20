/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:23:34 by yaolivei          #+#    #+#             */
/*   Updated: 2023/11/06 17:23:50 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int format)
{
	if (write(1, &format, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
		cont++;
	}
	return (i);
}

int	ft_process(char type, va_list ptr)
{
	int	cont;

	cont = 0;
	if (type == 'c')
		cont += ft_putchar(va_arg(ptr, int));
	else if (type == 's')
		cont = ft_putstr(va_arg (ptr, char *));
	else if (type == 'p')
		cont = ft_putptr(va_arg(ptr, unsigned long), "0x0123456789abcdef") + 2;
	else if (type == 'd' || type == 'i')
		cont = ft_putnbr(va_arg(ptr, int));
	else if (type == 'u')
		cont = ft_putnbr_uns(va_arg(ptr, unsigned int));
	else if (type == 'x')
		cont = ft_putnbr_hx(va_arg(ptr, int), "0123456789abcdef");
	else if (type == 'X')
		cont = ft_putnbr_hx(va_arg(ptr, int), "0123456789ABCDEF");
	else if (type == '%')
	{
		if (write (1, "%", 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}

int	ft_printf(char const *format, ...)
{
	int				cont;
	va_list			ptr;
	int				i;

	va_start(ptr, format);
	cont = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			cont += ft_process(format[i + 1], ptr);
			i++;
		}
		else
		{
			if (write (1, &format[i], 1) == -1)
				return (-1);
			cont++;
		}
		i++;
	}
	va_end(ptr);
	return (cont);
}

/*int	main(void)
{
	char	*c;
	// int		retorno;
	// int		retorno2;
	c = "hola";
	// retorno = ft_printf("MI: %p\n", &c);
	// retorno2 = printf("SU: %p\n", &c);
	//printf("%p\n%p\n", retorno, retorno2);
	ft_printf("MI: %p\n", &c);
	printf("SU: %p\n", &c);
	return (0);
}*/
