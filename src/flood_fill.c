/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:04:20 by agouin            #+#    #+#             */
/*   Updated: 2025/06/10 18:04:21 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"
#include "libft.h"
#include "mlx.h"

int	check_ber(char *temp, t_data *game, int i)
{
	int		fd;
	char	buf;
	int		k;

	k = 0;
	if (i <= 4)
		return (ft_error(0, game, "Bad file\n"));
	fd = open(temp, O_RDONLY);
	if (fd == -1)
		return (ft_error(0, game, "Fd failed - Bad file\n"));
	if (read(fd, &buf, 1) < 0)
	{
		close(fd);
		return (ft_error(4, game, "Argument is not a file\n"));
	}
	close(fd);
	k = ft_find_point(temp, k);
	if (temp[i - 1] == 'r' && temp[i - 2] == 'e'
		&& temp[i - 3] == 'b' && temp[i - 4] == '.'
		&& (temp[i - 5] != '/' && temp[i - 5] != '\0') && k == 1)
		return (0);
	return (ft_error(2, game, "Bad file\n"));
}

void	fill(char **tab, int x, int y, t_info test)
{
	if (x < 0 || y < 0 || y >= test.nb_ligne || x >= test.longueur)
		return ;
	if (tab[y][x] == 'F' || (tab[y][x] != '0' && tab[y][x] != 'C'))
		return ;
	tab[y][x] = 'F';
	fill(tab, x + 1, y, test);
	fill(tab, x - 1, y, test);
	fill(tab, x, y + 1, test);
	fill(tab, x, y - 1, test);
}

int	ft_count_line(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

t_point	find_p(char **tab)
{
	t_point	position;

	position.y = 0;
	while (tab[position.y])
	{
		position.x = 0;
		while (tab[position.y][position.x] != '\0')
		{
			if (tab[position.y][position.x] == 'P')
				return (position);
			position.x++;
		}
		position.y++;
	}
	position.x = -1;
	return (position);
}

int	flood_fill(t_data *game)
{
	int		i;
	t_point	position;
	t_info	test;
	char	**temp;

	test.longueur = ft_strlen(game->big_map->map[0]) - 1;
	test.nb_ligne = ft_count_line(game->big_map->map);
	position = find_p(game->big_map->map);
	if (position.x != -1)
	{
		temp = ft_duplicate_tab(game->big_map->map, game);
		temp[position.y][position.x] = '0';
		fill(temp, position.x, position.y, test);
		ft_test_flood(temp, game);
		ft_test_flood_for_c(temp, game);
		ft_free_tab(temp);
	}
	else
		return (ft_error(1, game, "Need 1 exit, 1 player and minimun 1 coin\n"));
	return (0);
}
