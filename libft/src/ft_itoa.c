/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:56:43 by agouin            #+#    #+#             */
/*   Updated: 2025/01/24 11:41:07 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	taille(int n)
{
	int	j;

	j = 0;
	while (n >= 10)
	{
		n = n / 10;
		j++;
	}
	j++;
	return (j);
}

char	*int_min(int n)
{
	char	*ptr;

	if (n == -2147483648)
	{
		ptr = malloc(12);
		if (!ptr)
			return (NULL);
		ptr[0] = '-';
		ptr[1] = '2';
		ptr[2] = '1';
		ptr[3] = '4';
		ptr[4] = '7';
		ptr[5] = '4';
		ptr[6] = '8';
		ptr[7] = '3';
		ptr[8] = '6';
		ptr[9] = '4';
		ptr[10] = '8';
		ptr[11] = 0;
		return (ptr);
	}
	return (NULL);
}

char	*cpy_t(int j, char *ptr, int n)
{
	ptr[j] = '\0';
	j--;
	while (n > 0)
	{
		ptr[j] = n % 10 + 48;
		n = n / 10;
		j--;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (n == -2147483648)
		return (int_min(n));
	if (n < 0)
	{
		n = -n;
		i = -1;
	}
	j = taille(n);
	if (i == -1)
		j++;
	ptr = malloc(j + 1);
	if (!ptr)
		return (NULL);
	if (n == 0)
		ptr[j - 1] = 0 + 48;
	if (i == -1)
		ptr[0] = '-';
	return (cpy_t(j, ptr, n));
}
/*
int	main(void)
{
	int	i = -214748347;

	printf("%s\n", ft_itoa(i));
	return(0);
}*/
// -2147483648
