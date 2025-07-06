/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointeur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:33:37 by agouin            #+#    #+#             */
/*   Updated: 2025/02/12 12:11:00 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

int	ft_pointeur3(unsigned long long q)
{
	int		count;

	count = 0;
	while (q > 0)
	{
		q = q / 16;
		count++;
	}
	return (count);
}

void	ft_pointeur2(unsigned long long q, char *s)
{
	if (q < 16 && q >= 0)
	{
		write(1, &s[q], 1);
	}
	if (q >= 16)
	{
		ft_pointeur2(q / 16, s);
		ft_pointeur2(q % 16, s);
	}
}

int	ft_pointeur(void *w)
{
	char				*s;
	int					count;
	unsigned long long	q;

	if (!w)
		return (write(1, "(nil)", 5));
	count = 0;
	s = "0123456789abcdef";
	q = (unsigned long long) w;
	count += write(1, "0x", 2);
	if (q > 0)
	{
		ft_pointeur2(q, s);
		count += ft_pointeur3(q);
	}
	return (count);
}
