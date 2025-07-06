/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:50:50 by agouin            #+#    #+#             */
/*   Updated: 2025/01/29 15:01:27 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)&s[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
/*
int main(void)
{
	char chaine[] = "12345";
	size_t j;

	j = 4;
	ft_memset(chaine, 'y', j);
	printf("%s", chaine);
	return (0);
}*/
