NAME = libft.a

SRC_DIR = ./src/
INC_DIR = ./includes/
OBJ_DIR = ./objects/

SRCS =   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
       ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_calloc.c \
       ft_split.c ft_striteri.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c \
       ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c \
       ft_strdup.c ft_strlcat.c ft_strrchr.c \
       get_next_line.c ft_putstr.c \
       ft_printf.c ft_printf2.c ft_printf3.c \
       ft_str_isnumeric.c


OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
    
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
INC_H = -I $(INC_DIR)


all: $(NAME)


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re