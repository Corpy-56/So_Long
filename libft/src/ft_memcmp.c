/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:07:35 by agouin            #+#    #+#             */
/*   Updated: 2025/01/04 15:59:46 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(p1 + i) == *(unsigned char *)(p2 + i))
			i++;
		else
			return (*(unsigned char *)(p1 + i) - *(unsigned char *)(p2 + i));
	}
	return (0);
}
/*
int	main(void)
{
	char chaine[] = "1234575";
	char chaine1[] = "1234583";
	size_t	p;

	p = 3;
	printf("%d", ft_memcmp(chaine, chaine1, p));
	return (0);
}*/
