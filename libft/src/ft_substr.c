/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:31:47 by agouin            #+#    #+#             */
/*   Updated: 2025/01/24 12:32:43 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ptr;
	unsigned int	j;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (start >= j || len == 0)
		return (ft_calloc(1, sizeof(char)));
	if (len > j || (j - start) < len)
		len = j - start;
	ptr = (char *)ft_calloc(sizeof(char), (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] != '\0' && j < len)
	{
		ptr[j++] = s[i++];
	}
	return (ptr);
}

// int	main(void)
// {
// 	char const chaine[] = "prout";
// 	unsigned int i = 1;
// 	size_t u = 2;

// 	printf("%s \n", ft_substr(chaine, i, u));
// 	return (0);
// }
