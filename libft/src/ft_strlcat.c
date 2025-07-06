/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:00:37 by agouin            #+#    #+#             */
/*   Updated: 2025/01/09 16:01:35 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	while (dest[j] != '\0')
		j++;
	if (n == 0 || j > n)
		return (n + i);
	if (!src)
		return (j);
	i = 0;
	while (src[i] != '\0' && ((i + j) < n - 1))
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i + j);
}
/*
int main(void)
{
	char chaine[] = "pqrstuvwxyz";
	const char chaine1[] = "abcd";
	size_t n = 0;
	//int	p;

//	p = strlcat(chaine, chaine1, n);
	printf("%zu", ft_strlcat(chaine, chaine1, n));
	printf("%s", chaine);
	return (0);
}*/
