
NAME = so_long

OBJ=$(SRC:.c=.o)

CC = cc
MAKE = make
CFLAG=-Wall -Wextra -Werror -g3

SRCS_DIR = ./src/
OBJ_DIR = ./objects/
INC_DIR = ./includes/
PARSE_DIR = $(SRCS_DIR)parsing/
OPE_DIR = $(SRCS_DIR)operations/
LIBFT_DIR = ./libft/
MLX_DIR = ./minilibx-linux 

SRCS=main.c error_free.c flood_fill.c ft_check_error.c ft_check_error2.c ft_move_player.c ft_init_map.c ft_display.c

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o)) 

#INC_H = -I $(INC_DIR) -I $(LIBFT_DIR)/includes/

INC_H = -I $(INC_DIR) -I $(LIBFT_DIR)/includes/ -I $(MLX_DIR)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
#	@$(CC) $(CFLAGS) $(INC_H) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@$(CC) $(CFLAGS) $(INC_H) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -o $(NAME)
#	@$(CC) $(CFLAGS) $(INC_H) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) pour MAC

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_H) -c -o $@ $<

$(OBJ_DIR)%.o: $(PARSE_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_H) -c -o $@ $<

$(OBJ_DIR)%.o: $(OPE_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_H) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all



.PHONY: all clean fclean re
