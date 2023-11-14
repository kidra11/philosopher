/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:29:16 by nsion             #+#    #+#             */
/*   Updated: 2023/02/27 18:24:21 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int	ft_printf(const char *s, ...);

int	ft_len(char *s);

int	ft_putchar(char c);

int	ft_putstr(char *s);

int	for_p(unsigned long long int *n, char *base, int num);

int	ft_putnbr_base(int n, char *base, int num);

int	ft_unput(unsigned int n, char *base, int num);

int	find(char s, va_list trois, int num);

#endif
