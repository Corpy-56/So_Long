/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:46:17 by agouin            #+#    #+#             */
/*   Updated: 2025/01/24 10:39:37 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(str + i) == (unsigned char)c)
			return ((void *)(str + i));
		else
			i++;
	}
	return (0);
}
/*
int	main(void)
{
	char chaine[] = "12a345";
	size_t u = 3;
	int c = 'a';
	char *result = ft_memchr(chaine, c, u);

	printf("%s", result);
	return (0);
}*/
