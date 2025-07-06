/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:04:10 by agouin            #+#    #+#             */
/*   Updated: 2025/06/10 18:04:12 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"
#include "libft.h"
#include "mlx.h"

int	ft_error(int i, t_data *game, char *string)
{
	if (game != NULL && i != 9 && i != 6)
		ft_free_struct(game);
	if (i == 6)
	{
		write(2, "Error\nProblem with Assets\n", 27);
		on_destroy(game);
	}
	write(2, "Error\n", 7);
	write(2, string, ft_strlen(string));
	exit (EXIT_FAILURE);
}

void	ft_exit_game(t_data *game)
{
	if (game->coin == 0)
	{
		game->move = game->move + 1;
		ft_printf("Number of movements : %d\n", game->move);
		on_destroy(game);
	}
	else
		ft_display_map(game);
}

void	ft_free_struct(t_data *game)
{
	if (game)
	{
		if (game->mlx_ptr)
		{
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
		}
		if (game->big_map)
		{
			if (game->big_map->map)
				ft_free_tab(game->big_map->map);
			free(game->big_map);
		}
		free(game);
	}
}

int	on_destroy(t_data *game)
{
	free_image(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	if (game->big_map != NULL || game->big_map->map != NULL)
	{
		ft_free_tab(game->big_map->map);
		free(game->big_map);
		free(game);
	}
	exit(0);
	return (0);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	return ;
}
