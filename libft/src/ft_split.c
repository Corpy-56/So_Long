/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:44:15 by agouin            #+#    #+#             */
/*   Updated: 2025/01/29 15:33:39 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	protect_malloc(char **words_v, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		free(words_v[i]);
		i++;
	}
	free(words_v);
	return (1);
}

size_t	nb_words(char const *s, char len)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != len && (s[i + 1] == len || s[i + 1] == '\0'))
			words++;
		i++;
	}
	if (words == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (words);
}

char	*copy_words(const char *start, size_t len)
{
	char	*words;
	size_t	i;

	i = 0;
	words = malloc(len + 1);
	if (words == NULL)
		return (NULL);
	while (i < len)
	{
		words[i] = start[i];
		i++;
	}
	words[len] = '\0';
	return (words);
}

int	cpy(char **words_v, char const *s, char len)
{
	const char	*start;
	size_t		j;
	int			k;

	k = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == len)
			s++;
		start = s;
		j = 0;
		while (*s != '\0' && *s++ != len)
			j++;
		if (j > 0)
		{
			words_v[k] = copy_words(start, j);
			if (words_v[k] == NULL)
				return (protect_malloc(words_v, k));
			k++;
		}
	}
	words_v[k] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**words_v;

	if (s == NULL)
		return (NULL);
	words = 0;
	words = nb_words(s, c);
	if (words == 0)
		return (NULL);
	words_v = malloc(sizeof(char *) * (words + 1));
	if (words_v == NULL)
		return (NULL);
	if (cpy(words_v, s, c))
		return (NULL);
	return (words_v);
}

// int	main(void)
// {
// 	char *s = "      ";
// 	char **v = ft_split(s, ' ');

// 	while (*v)
// 	{
// 		printf("%s\n", *v);
// 		free(*v);
// 		v++;
// 	}
// 	return (0);
// }
