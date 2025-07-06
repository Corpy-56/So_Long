/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:37:32 by agouin            #+#    #+#             */
/*   Updated: 2025/01/09 14:56:22 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t s)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (src[i] != '\0')
		i++;
	if (s == 0)
		return (i);
	while (src[j] != '\0' && s > 1)
	{
		dst[j] = src[j];
		j++;
		s--;
	}
	dst[j] = '\0';
	return (i);
}
/*
int	main(void)
{
	char	chaine[] = "lo";
	char	chaine1[] = "abcde";
	size_t	p = 0;

	printf("%zu", ft_strlcpy(chaine, chaine1, p));
	printf("%s", chaine);
	return (0);
}*/
