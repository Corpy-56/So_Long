/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_samitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:12:31 by agouin            #+#    #+#             */
/*   Updated: 2025/02/12 12:36:31 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

int	ft_putnbr2(unsigned int n)
{
	char	*ptr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	ptr = "0123456789ABCDEF";
	if (n < 16 && n >= 0)
	{
		i = n;
		count += write(1, &ptr[i], 1);
	}
	if (n >= 16)
	{
		count += ft_putnbr2(n / 16);
		count += ft_putnbr2(n % 16);
	}
	return (count);
}

int	ft_putnbrx(unsigned int n)
{
	char	*ptr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	ptr = "0123456789abcdef";
	if (n < 16 && n >= 0)
	{
		i = n;
		count += write(1, &ptr[i], 1);
	}
	if (n >= 16)
	{
		count += ft_putnbrx(n / 16);
		count += ft_putnbrx(n % 16);
	}
	return (count);
}

int	samtaille(unsigned int l)
{
	int	j;

	j = 1;
	while (l >= 10)
	{
		l = l / 10;
		j++;
	}
	return (j);
}

char	*samcpy_t(int j, char *ptr, unsigned int l)
{
	ptr[j] = '\0';
	j--;
	while (l > 0)
	{
		ptr[j] = l % 10 + 48;
		l = l / 10;
		j--;
	}
	return (ptr);
}

char	*ft_samitoa(unsigned int l)
{
	unsigned int	j;
	char			*ptr;

	j = 0;
	j = samtaille(l);
	ptr = malloc(j + 1);
	if (!ptr)
		return (NULL);
	if (l == 0)
		ptr[j - 1] = 0 + 48;
	return (samcpy_t(j, ptr, l));
}
