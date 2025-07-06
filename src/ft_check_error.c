/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:04:30 by agouin            #+#    #+#             */
/*   Updated: 2025/06/10 18:04:31 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"
#include "libft.h"
#include "mlx.h"

char	*ft_creat_big_map(char *temp, int fd, t_data *game, int i)
{
	int	j;

	j = 0;
	while (1 < 2)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			return (game->big_map->map[j] = NULL);
		if (temp[0] == '1')
		{
			game->big_map->map[j] = ft_strdup(temp);
			if (game->big_map->map[j] == NULL)
			{
				free(temp);
				get_next_line(-1);
				return (game->big_map->map[j] = NULL);
			}
			j++;
		}
		if (temp[0] != '1' && j > 0 && j < i)
			ft_line_in_middle(temp, game, j);
		free(temp);
	}
}

char	**new_tab(t_data *game, char *argv, int fd, int j)
{
	int		i;
	int		fd2;
	char	*temp;

	i = ft_count_file(fd, game);
	game->big_map->map = ft_calloc(sizeof(t_map *), (i + 1));
	if (game->big_map->map == NULL)
		return (NULL);
	fd2 = open(argv, O_RDONLY);
	if (fd2 == -1)
		ft_error(0, game, "Fd failed\n");
	ft_creat_big_map(temp, fd, game, i);
	close(fd2);
	return (game->big_map->map);
}

void	ft_test_char_map(t_data *game, int i, char **tab, int temp)
{
	int	j;

	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'E' || tab[i][j] == 'C' || tab[i][j] == 'P')
				ft_count_e_p(tab[i][j], game);
			if (tab[i][j] == 'E' || tab[i][j] == 'C' || tab[i][j] == 'P' ||
				tab[i][j] == '0' || tab[i][j] == '1' || tab[i][j] == '\n')
				j++;
			else
				ft_error(1, game, "Bad map\n");
		}
		temp = j;
		i++;
	}
	ft_count_e_p('A', game);
}

void	ft_test_line_1(t_data *game, int j, int i, char **tab)
{
	while (tab[0][j++] != '\0')
	{
		if (tab[0][j] != '1' && tab[0][j] != '\0' && tab[0][j] != '\n')
			ft_error(1, game, "Bad map\n");
	}
	while (tab[i])
	{
		j = 0;
		if (tab[i][0] != '1')
			ft_error(1, game, "Bad map\n");
		while (tab[i][j] != '\0' && tab[i][j] != '\n')
			j++;
		if (tab[i][j - 1] != '1')
			ft_error(1, game, "Bad map\n");
		i++;
	}
	j = 0;
	i--;
	while (tab[i][j++] != '\0')
	{
		if (tab[i][j] != '1' && tab[i][j] != '\0' && tab[i][j] != '\n')
			ft_error(1, game, "Bad map\n");
	}
}

char	**ft_check(char *argv, t_data *game)
{
	int	fd;
	int	i;
	int	j;
	int	temp;

	temp = -1;
	j = 1;
	i = 0;
	check_ber(argv, game, ft_strlen(argv));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error(0, game, "Fd failed\n");
	game->big_map->map = new_tab(game, argv, fd, i);
	ft_test_char_map(game, i, game->big_map->map, temp);
	ft_test_line_1(game, i, j, game->big_map->map);
	ft_test_longueur(game->big_map->map, game);
	flood_fill(game);
	close(fd);
	return (game->big_map->map);
}
