/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:34:19 by agouin            #+#    #+#             */
/*   Updated: 2025/01/03 18:15:09 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		valeur;
	size_t	i;
	int		sign;

	i = 0;
	valeur = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		valeur = valeur * 10 + (str[i] - 48);
		i++;
	}
	return (valeur * sign);
}
/*
int main(void)
{
	char chaine1[] = "  -123-45";

	printf("%d", ft_atoi(chaine1));
	return (0);
}*/
