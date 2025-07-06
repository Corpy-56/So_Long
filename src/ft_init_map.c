/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:02:46 by agouin            #+#    #+#             */
/*   Updated: 2025/06/29 15:02:47 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"
#include "libft.h"
#include "mlx.h"

void	ft_initialization(t_data *game)
{
	game->width = 0;
	game->lenght = 0;
	game->p_info.longueur = 0;
	game->p_info.nb_ligne = 0;
	game->position.x = 0;
	game->position.y = 0;
	game->screen_size_width = 0;
	game->screen_size_height = 0;
	game->coin = 0;
	game->move = 0;
	game->i = 0;
	game->j = 0;
	game->big_map = NULL;
	game->big_map = ft_calloc(sizeof(t_map), 1);
	if (game->big_map == NULL)
		ft_error(0, game, "Malloc failed\n");
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_error(0, game, "Mlx_init failed\n");
	mlx_get_screen_size(game->mlx_ptr, &game->screen_size_width,
		&game->screen_size_height);
	game->screen_size_width = game->screen_size_width / 64;
	game->screen_size_height = game->screen_size_height / 64;
}

t_info	ft_init_screen(t_info p_info, t_data *game)
{
	int	i;

	i = 0;
	p_info.longueur = ft_strlen(game->big_map->map[0]) - 1;
	while (game->big_map->map[i])
		i++;
	p_info.nb_ligne = i;
	return (p_info);
}

void	init_map(t_data *game)
{
	game->width = 64;
	game->lenght = 64;
	game->imag_player = mlx_xpm_file_to_image(game->mlx_ptr, "assets/star.xpm",
			&game->width, &game->lenght);
	game->image_back = mlx_xpm_file_to_image(game->mlx_ptr, "assets/back.xpm",
			&game->width, &game->lenght);
	game->image_exit = mlx_xpm_file_to_image(game->mlx_ptr, "assets/exit.xpm",
			&game->width, &game->lenght);
	game->image_wall = mlx_xpm_file_to_image(game->mlx_ptr, "assets/wall.xpm",
			&game->width, &game->lenght);
	game->image_coin = mlx_xpm_file_to_image(game->mlx_ptr, "assets/plant.xpm",
			&game->width, &game->lenght);
	if (!game->imag_player || !game->image_back || !game->image_exit
		|| !game->image_wall || !game->image_coin)
	{
		ft_error(6, game, "Problem with Assets\n");
	}
}

void	free_image(t_data *game)
{
	if (game->imag_player != NULL)
		mlx_destroy_image(game->mlx_ptr, game->imag_player);
	if (game->image_back != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image_back);
	if (game->image_exit != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image_exit);
	if (game->image_wall != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image_wall);
	if (game->image_coin != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image_coin);
}

void	ft_line_in_middle(char *temp, t_data *game, int j)
{
	free(temp);
	get_next_line(-1);
	game->big_map->map[j] = NULL;
	ft_error(1, game, "Bad map\n");
}
