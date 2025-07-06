/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:31:34 by agouin            #+#    #+#             */
/*   Updated: 2025/01/24 14:54:45 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

size_t	debut(char const *set, char const *s1)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && set[j] != '\0')
	{
		while (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}

size_t	fin(char const *set, char const *s1)
{
	size_t	k;
	size_t	j;

	k = ft_strlen(s1);
	j = 0;
	while (k > 0 && set[j] != '\0')
	{
		while (set[j] != '\0' && s1[k - 1] == set[j])
		{
			k--;
			j = 0;
		}
		j++;
	}
	return (k);
}

char	*pb(void)
{
	char	*ptr;

	ptr = 0;
	ptr = (char *)malloc(sizeof(char) * 1);
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ptr;

	ptr = 0;
	i = 0;
	if (!s1 || !set)
		return (0);
	if (set != 0 && s1 != 0)
		i = debut(set, s1);
	k = fin(set, s1);
	if (i == ft_strlen(s1))
		return (pb());
	ptr = malloc(sizeof(char) * (k - i + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (i < k)
	{
		ptr[j++] = s1[i];
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
/*
int	main(void)
{
 	char	s1[] = "aaaaaa";
 	char	set[] = "a";
 	char *res = ft_strtrim(s1, set);
 	if (res[0] == '\0')
 	{
 		printf("%s\n", res);
 		free(res);
 	}
 	printf("lol\n");
 	return (0);
}*/
