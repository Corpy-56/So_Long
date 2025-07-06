/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:45:55 by agouin            #+#    #+#             */
/*   Updated: 2025/06/29 14:45:57 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"
#include "libft.h"
#include "mlx.h"

int	ft_test_flood(char **tab, t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] != '\0' && tab[i][j] != 'E')
			j++;
		if (tab[i][j] == 'E')
		{
			if (tab[i][j +1] == 'F' || tab[i][j -1] == 'F' ||
				tab[i +1][j] == 'F' || tab[i - 1][j] == 'F')
				return (0);
			else
			{
				ft_free_tab(tab);
				return (ft_error(1, game, "Exit not accessible\n"));
			}
		}
		i++;
	}
	return (0);
}

int	ft_test_flood_for_c(char **tab, t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] != '\0' && tab[i][j] != 'C')
			j++;
		if (tab[i][j] == 'C')
		{
			ft_free_tab(tab);
			return (ft_error(1, game, "Coins not accessible\n"));
		}
		i++;
	}
	return (0);
}

char	**ft_duplicate_tab(char **tab, t_data *game)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	while (tab[i])
		i++;
	temp = ft_calloc(sizeof(char *), (i + 1));
	if (temp == NULL)
		ft_error(0, game, "Malloc failed\n");
	i = 0;
	while (tab[i])
	{
		temp[i] = ft_strdup(tab[i]);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

void	ft_count_e_p(char c, t_data *game)
{
	static int	p = 0;
	static int	sortie = 0;

	if (c == 'E')
		sortie += 1;
	if (c == 'C')
		game->coin += 1;
	if (c == 'P')
		p += 1;
	if ((sortie != 1 || p != 1) && c == 'A')
		ft_error(3, game, "Need 1 exit, 1 character and minimun 1 coin\n");
	if (c == 'A' && game->coin == 0)
		ft_error(3, game, "Need 1 exit, 1 character and minimun 1 coin\n");
}

int	ft_count_file(int fd, t_data *game)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	j = 0;
	while (1 < 2)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		j = ft_strlen(str);
		if (j > 250)
			break ;
		if (str[0] == '1')
			i++;
		free(str);
	}
	if (str != NULL)
		free(str);
	get_next_line(-1);
	close(fd);
	if (i > 250 || j > 250)
		ft_error(7, game, "Map too huge\n");
	return (i);
}
