/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:01:49 by agouin            #+#    #+#             */
/*   Updated: 2025/01/14 19:39:29 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while ((size_t)i < n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}	
	return (dest);
}

/*
int	main(void)
{
	char chaine1[] = "123456";
	char chaine2[] = "ddd";

	size_t	j;
	
	j = 4;
	ft_memmove(chaine1, chaine2, j);
	printf("%s", chaine1);
	return (0);
}
*/
