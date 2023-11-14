/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:18:55 by nsion             #+#    #+#             */
/*   Updated: 2023/02/27 16:23:30 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_base(int n, char *base, int num)
{
	int	xbase;
	int	n_final[16];
	int	i;

	xbase = ft_len(base);
	i = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			num += ft_putstr("-2147483648");
			return (num);
		}
		num += ft_putchar('-');
		n = n * -1;
	}
	while (n || i == 0)
	{
		n_final[i] = n % xbase;
		n = n / xbase;
		i++;
	}
	while (--i >= 0)
		num += ft_putchar(base[n_final[i]]);
	return (num);
}

int	ft_unput(unsigned int n, char *base, int num)
{
	int	xbase;
	int	n_final[16];
	int	i;

	xbase = ft_len(base);
	i = 0;
	while (n || i == 0)
	{
		n_final[i] = n % xbase;
		n = n / xbase;
		i++;
	}
	while (--i >= 0)
		num += ft_putchar(base[n_final[i]]);
	return (num);
}

int	find(char s, va_list trois, int num)
{
	if (s == 'c')
		num += ft_putchar(va_arg(trois, int));
	if (s == 's')
		num += ft_putstr(va_arg(trois, char *));
	if (s == 'p')
		num = for_p(va_arg(trois, void *), "0123456789abcdef", num);
	if (s == 'd')
		num = ft_putnbr_base(va_arg(trois, int), "0123456789", num);
	if (s == 'i')
		num = ft_putnbr_base(va_arg(trois, int), "0123456789", num);
	if (s == 'u')
		num = ft_unput(va_arg(trois, unsigned int), "0123456789", num);
	if (s == 'x')
		num = ft_unput(va_arg(trois, unsigned int), "0123456789abcdef", num);
	if (s == 'X')
		num = ft_unput(va_arg(trois, unsigned int), "0123456789ABCDEF", num);
	if (s == '%')
		num += ft_putchar('%');
	return (num);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		num;
	va_list	trois;

	va_start(trois, s);
	i = 0;
	num = 0;
	while (s[i])
	{
		if (s[i] == '%')
			num = find(s[++i], trois, num);
		else
			num += ft_putchar(s[i]);
		i++;
	}
	va_end(trois);
	return (num);
}
