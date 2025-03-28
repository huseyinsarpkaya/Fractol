NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_PATH = ./minilibx-linux
MLX_FLAGS = -L $(MLX_PATH) -lmlx -lXext -lX11 -lm

SRC = main.c utils.c free_memory.c mlx_function.c hook_operation.c color.c error.c set.c julia.c mandelbrot.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(MLX_PATH)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)  

clean:
		make -C $(MLX_PATH) clean  
		rm -rf $(OBJ) 

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
