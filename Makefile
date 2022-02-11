NAME = so_long

SRC = main.c \
srcs/ft_draw_it.c \
srcs/ft_map.c \
srcs/ft_map_utils.c \
srcs/ft_itoa.c \
srcs/show_points.c \
srcs/val_map.c \
srcs/ft_split.c \
srcs/ft_utils.c \
srcs/player.c \
srcs/enemy.c \
srcs/enemy_utils.c \
srcs/ft_animate.c \
srcs/ft_win_or_lose.c \
srcs/ft_game_utils.c

HDRS = incl/lib.h

OBJ = $(SRC:.c=.o)

RM = rm -f

%.o: %.c
	gcc -Wall -Wextra -Werror -Imlx -I ${HDRS} -c $< -o $@

$(NAME): $(OBJ)
	make -C ./mlx/mlxb/
	gcc $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

ex: $(NAME)
	./$(NAME) maps/map2.ber
	make clean
	make -C ./mlx/mlxb/ clean

clean:
	${RM} $(OBJ)
	make -C ./mlx/mlxb/ clean

fclean: clean
	${RM} $(NAME) ${OBJ}
	make -C ./mlx/mlxb/ clean

re: $(NAME)

.PHONY: all clean fclean re
