/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:31:50 by agouin            #+#    #+#             */
/*   Updated: 2025/01/08 17:24:40 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *f, const char *s, size_t l)
{
	size_t	i;

	i = 0;
	while (i < l)
	{
		if (f[i] != s[i])
			return ((unsigned char) f[i] - (unsigned char) s[i]);
		if (f[i] == '\0')
			return (0);
		if ((f[i] == s[i]) && (f[i] != 0))
			i++;
	}
	return (0);
}
/*
int	main(void)
{
	char chaine[] = "1234";
	char chaine1[] = "1235";
	size_t a = 3;

	printf("%d", ft_strncmp(chaine, chaine1, a));
	return (0);
}*/
