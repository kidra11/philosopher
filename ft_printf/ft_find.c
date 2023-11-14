/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:29:11 by nsion             #+#    #+#             */
/*   Updated: 2023/07/29 12:24:53 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (!ft_len(s))
		return (0);
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	for_p(unsigned long long int *n, char *base, int num)
{
	unsigned long long int	ln;
	unsigned long long int	xbase;
	int						n_final[16];
	int						i;

	if (!n)
	{
		num += ft_putstr("(nil)");
		return (num);
	}
	num += ft_putstr("0x");
	ln = (unsigned long long int)n;
	i = 0;
	xbase = ft_len(base);
	while (ln || i == 0)
	{
		n_final[i] = ln % xbase;
		ln = ln / xbase;
		i++;
	}
	while (--i >= 0)
		num += ft_putchar(base[n_final[i]]);
	return (num);
}
