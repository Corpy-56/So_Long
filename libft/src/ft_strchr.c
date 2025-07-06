/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:01:22 by agouin            #+#    #+#             */
/*   Updated: 2025/01/29 15:42:22 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char) c)
			return ((char *)&str[i]);
		i++;
	}
	if (((unsigned char) c) == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
/*
int	main(void)
{
	char chaine[] = "teste";
	int i = 1024;

	printf("%s", ft_strchr(chaine, i));
	return (0);
}
*/
