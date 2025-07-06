/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:53:24 by agouin            #+#    #+#             */
/*   Updated: 2025/06/30 17:53:25 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct t_noeud
{
	int	nb_ligne;
	int	longueur;
}t_info;

typedef struct t_map
{
	char	**map;
}t_map;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_data
{
	int		width;
	int		lenght;
	t_info	p_info;
	t_map	*big_map;
	t_point	position;
	int		screen_size_width;
	int		screen_size_height;
	int		j;
	int		i;
	int		coin;
	int		move;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*imag_player;
	void	*image_coin;
	void	*image_wall;
	void	*image_exit;
	void	*image_back;	
}t_data;

/* FONCTIONS ERROR   **************************************** */

int		ft_error(int i, t_data *game, char *string);
void	ft_free_tab(char **tab);
void	ft_free_struct(t_data *game);
int		on_destroy(t_data *game);
void	ft_exit_game(t_data *game);

/* CHECK MAPS 1 / 2 ************************************* */

char	**ft_check(char *argv, t_data *game);
char	**new_tab(t_data *game, char *argv, int fd, int j);
void	ft_test_char_map(t_data *game, int i, char **tab, int temp);
void	ft_test_line_1(t_data *game, int j, int i, char **tab);
int		ft_count_file(int fd, t_data *game);
void	ft_count_e_p(char c, t_data *game);
char	**ft_duplicate_tab(char **tab, t_data *game);
int		ft_test_flood_for_c(char **tab, t_data *game);
int		ft_test_flood(char **tab, t_data *game);
void	ft_test_longueur(char **tab, t_data *game);
void	ft_line_in_middle(char *temp, t_data *game, int j);

/* FLOOD FILL */

int		flood_fill(t_data *game);
t_point	find_p(char **tab);
int		check_ber(char *temp, t_data *game, int i);
int		ft_find_point(char *temp, int k);

/* INIT MAP / STRUCTURE  *********************************/

void	ft_initialization(t_data *game);
t_info	ft_init_screen(t_info p_info, t_data *game);
void	init_map(t_data *game);
void	free_image(t_data *game);

/* MOVE PLAYER  ******************************************** */

int		keyboard_key(int keycode, t_data *game);
void	ft_move_w(t_data *game);
void	ft_move_s(t_data *game);
void	ft_move_a(t_data *game);
void	ft_move_d(t_data *game);

/* DISPLAY MAP  ****************************************** */

void	ft_display_map(t_data *game);
t_point	ft_position(t_data *game);
void	ft_count_move(t_data *game);

#endif
