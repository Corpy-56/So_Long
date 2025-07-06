/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:57:39 by agouin            #+#    #+#             */
/*   Updated: 2025/06/29 14:57:40 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"
#include "libft.h"
#include "mlx.h"

int	keyboard_key(int keycode, t_data *game)
{
	if (keycode == 65307)
		on_destroy(game);
	else if (keycode == 119)
		ft_move_w(game);
	else if (keycode == 115)
		ft_move_s(game);
	else if (keycode == 97)
		ft_move_a(game);
	else if (keycode == 100)
		ft_move_d(game);
	return (-1);
}

void	ft_move_w(t_data *game)
{
	if (game->position.y != 0)
	{
		if (game->big_map->map[game->position.y - 1][game->position.x] == 'C')
			game->coin = game->coin - 1;
		if (game->big_map->map[game->position.y - 1][game->position.x] == 'E')
			ft_exit_game(game);
		else if (game->big_map->map[game->position.y - 1]
			[game->position.x] != '1')
		{
			game->big_map->map[game->position.y][game->position.x] = '0';
			game->big_map->map[game->position.y - 1][game->position.x] = 'P';
			ft_count_move(game);
			game->position = ft_position(game);
			ft_display_map(game);
		}
	}
}

void	ft_move_s(t_data *game)
{
	if (game->position.y != 0)
	{
		if (game->big_map->map[game->position.y + 1][game->position.x] == 'C')
			game->coin = game->coin - 1;
		if (game->big_map->map[game->position.y + 1][game->position.x] == 'E')
			ft_exit_game(game);
		else if (game->big_map->map[game->position.y + 1]
			[game->position.x] != '1')
		{
			game->big_map->map[game->position.y][game->position.x] = '0';
			game->big_map->map[game->position.y + 1][game->position.x] = 'P';
			ft_count_move(game);
			game->position = ft_position(game);
			ft_display_map(game);
		}
	}
}

void	ft_move_a(t_data *game)
{
	if (game->position.y != 0)
	{
		if (game->big_map->map[game->position.y][game->position.x - 1] == 'C')
			game->coin = game->coin - 1;
		if (game->big_map->map[game->position.y][game->position.x - 1] == 'E')
			ft_exit_game(game);
		else if (game->big_map->map[game->position.y]
			[game->position.x - 1] != '1')
		{
			game->big_map->map[game->position.y][game->position.x] = '0';
			game->big_map->map[game->position.y][game->position.x - 1] = 'P';
			ft_count_move(game);
			game->position = ft_position(game);
			ft_display_map(game);
		}
	}
}

void	ft_move_d(t_data *game)
{
	if (game->position.y != 0)
	{
		if (game->big_map->map[game->position.y][game->position.x + 1] == 'C')
			game->coin = game->coin - 1;
		if (game->big_map->map[game->position.y][game->position.x + 1] == 'E')
			ft_exit_game(game);
		else if (game->big_map->map[game->position.y]
			[game->position.x + 1] != '1')
		{
			game->big_map->map[game->position.y][game->position.x] = '0';
			game->big_map->map[game->position.y][game->position.x + 1] = 'P';
			ft_count_move(game);
			game->position = ft_position(game);
			ft_display_map(game);
		}
	}
}
