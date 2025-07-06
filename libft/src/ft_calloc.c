/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:23:28 by agouin            #+#    #+#             */
/*   Updated: 2025/01/24 09:25:25 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t c, size_t s)
{
	size_t	i;
	void	*ptr;

	i = 0;
	i--;
	if (s != 0 && i / s < c)
		return (NULL);
	i = 0;
	ptr = malloc(c * s);
	if (ptr == NULL)
		return (NULL);
	while (i < c * s)
	{
		*(unsigned char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
/*
int	main(void)
{
	int	*chaine;
	size_t	nb = 5;
	size_t	po = sizeof(int);

	chaine = ft_calloc(nb, po);
	printf("calloc");

	return (0);
}*/
