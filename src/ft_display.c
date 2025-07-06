/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:05:30 by agouin            #+#    #+#             */
/*   Updated: 2025/06/29 15:05:31 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"
#include "libft.h"
#include "mlx.h"

void	ft_display2(t_data *game, char c, int i, int j)
{
	if (c == '0')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image_back,
			i * 64, j * 64);
	}
	else if (c == '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image_wall,
			i * 64, j * 64);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image_exit,
			i * 64, j * 64);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image_coin,
			i * 64, j * 64);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->imag_player,
			i * 64, j * 64);
	}
}

void	ft_display_map(t_data *game)
{
	int	m_i;
	int	m_j;
	int	cam_wid;
	int	cam_long;

	m_j = 0;
	while (m_j < game->screen_size_height)
	{
		cam_wid = m_j + game->j;
		m_i = 0;
		if (cam_wid >= game->p_info.nb_ligne)
			break ;
		while (m_i < game->screen_size_width)
		{
			cam_long = game->i + m_i;
			if (cam_long >= game->p_info.longueur)
				break ;
			ft_display2(game, game->big_map->map[cam_wid][cam_long], m_i, m_j);
			m_i++;
		}
		m_j++;
	}
}

t_point	ft_position(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->big_map->map[i])
	{
		j = 0;
		while (game->big_map->map[i][j] && game->big_map->map[i][j] != 'P')
			j++;
		if (game->big_map->map[i][j] == 'P')
		{
			game->position.y = i;
			game->position.x = j;
			if (i >= game->screen_size_height - 2)
				game->j = i - game->screen_size_height + 2;
			if (j >= game->screen_size_width - 2)
				game->i = j - game->screen_size_width + 2;
			return (game->position);
		}
		i++;
	}
	return (game->position);
}

void	ft_count_move(t_data *game)
{
	game->move = game->move + 1;
	ft_printf("Number of movements : %d\n", game->move);
}

void	ft_test_longueur(char **tab, t_data *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		if (tab[i][j - 1] == '\n')
			j--;
		if (j != k && i != 0)
			ft_error(15, game, "Need a rectangular map\n");
		k = j;
		i++;
	}
	return ;
}
