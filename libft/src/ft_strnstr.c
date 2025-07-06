/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:56:40 by agouin            #+#    #+#             */
/*   Updated: 2025/01/24 15:22:20 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[i])
		return ((char *) big);
	while ((big[i] != '\0') && (i < len))
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	size_t n;

	n = 10;
	const char chaine1[] = "orem ipsum dolor sit amet";
	const char chaine2[] = "";
	ft_strnstr (chaine1, chaine2, n);
	printf("%s \n", ft_strnstr (chaine1, chaine2, n));
	return (0);
}*/
