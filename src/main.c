/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:04:50 by agouin            #+#    #+#             */
/*   Updated: 2025/06/10 18:04:52 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"
#include "libft.h"
#include "mlx.h"

int	ft_find_point(char *temp, int k)
{
	int	j;

	j = 0;
	while (temp[j++] != '\0')
	{
		if (temp[j] == '.')
			k++;
		if (temp[j] == '/' && k > 0)
			k--;
	}
	return (k);
}

int	ft_size_window(t_data *game, int i, int j)
{
	if (i > game->screen_size_width && j > game->screen_size_height)
		game->win_ptr = mlx_new_window(game->mlx_ptr,
				game->screen_size_width * 64,
				game->screen_size_height * 64, "So_long");
	else if (j > game->screen_size_height)
			game->win_ptr = mlx_new_window(game->mlx_ptr, i * 64,
				game->screen_size_height * 64, "So_long");
	else if (i > game->screen_size_width)
			game->win_ptr = mlx_new_window(game->mlx_ptr,
				game->screen_size_width * 64, j * 64, "So_long");
	else
		game->win_ptr = mlx_new_window(game->mlx_ptr, i * 64,
				j * 64, "So_long");
	if (!game->win_ptr)
		return (ft_error(10, game, "Problem to open the window\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*game;

	if (argc != 2)
		return (ft_error(9, NULL, "Need 2 arguments : ./so_long file.ber\n"));
	game = ft_calloc(sizeof(t_data), 1);
	if (game == NULL)
		return (ft_error(0, game, "Malloc failed\n"));
	ft_initialization(game);
	game->big_map->map = ft_check(argv[1], game);
	if (game->big_map->map == NULL)
		return (ft_error(0, game, "Malloc failed\n"));
	game->p_info = ft_init_screen(game->p_info, game);
	ft_size_window(game, game->p_info.longueur, game->p_info.nb_ligne);
	init_map(game);
	game->position = ft_position(game);
	ft_display_map(game);
	mlx_key_hook(game->win_ptr, keyboard_key, game);
	mlx_hook(game->win_ptr, 17, 0, on_destroy, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
