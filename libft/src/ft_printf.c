/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:01:02 by agouin            #+#    #+#             */
/*   Updated: 2025/02/12 12:33:54 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

int	ft_putstrs(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(unsigned int p, const char *format, size_t i)
{
	int	count;

	count = 0;
	if (format[i] == 'X')
		count += ft_putnbr2(p);
	if (format[i] == 'x')
		count += ft_putnbrx(p);
	return (count);
}

int	ft_autres(const char *format, va_list args, size_t i, unsigned int p)
{
	int				count;
	int				j;
	void			*w;

	count = 0;
	if (format[i] == 'i' || format[i] == 'd')
	{
		j = va_arg(args, int);
		count += (ft_putstr((unsigned char *)ft_itoa(j)));
	}
	if (format[i] == 'u')
	{
		p = va_arg(args, unsigned int);
		count += (ft_putstr((unsigned char *)ft_samitoa(p)));
	}
	if (format[i] == 'p')
	{
		w = va_arg(args, void *);
		count += ft_pointeur(w);
	}
	return (count);
}

int	ft_symboles(const char *format, va_list args, size_t i, unsigned int p)
{
	char		*s;
	int			count;

	count = 0;
	if (format[i] == '%')
		count += write(1, "%", 1);
	if (format[i] == 's')
	{
		s = va_arg(args, char *);
		count += ft_putstrs(s);
	}
	if (format[i] == 'c')
	{
		s = va_arg(args, char *);
		count += write(1, &s, 1);
	}
	if (format[i] == 'X' || format[i] == 'x')
	{
		p = va_arg(args, unsigned int);
		count += ft_putnbr(p, format, i);
	}
	if (format[i] == 'i' || format[i] == 'd'
		|| format[i] == 'u' || format[i] == 'p')
		count += ft_autres(format, args, i, p);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int				count;
	size_t			i;
	unsigned int	p;

	va_list(args);
	va_start(args, format);
	i = 0;
	count = 0;
	p = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_symboles(format, args, i, p);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
