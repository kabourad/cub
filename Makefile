# NAME =	Cub3D

# SRCS =	main.c srcs/execution/calculations.c srcs/execution/drawing.c \
# srcs/execution/key_manager.c srcs/execution/movements.c \
# srcs/execution/ray_casting.c srcs/execution/textures.c srcs/extras/ft_arrdel.c \
# srcs/extras/ft_arrlen.c srcs/extras/ft_split_whitespaces.c \
# srcs/extras/ft_strcmp.c srcs/extras/ft_strdel.c srcs/extras/ft_strlen.c \
# srcs/extras/put_and_quit.c srcs/parsing/fills.c srcs/parsing/id_extra.c \
# srcs/parsing/id_parse.c srcs/parsing/map_check_extra.c srcs/parsing/map_check.c \
# srcs/parsing/map_parse.c srcs/parsing/parse_inits.c srcs/parsing/parsing.c

# OBJ =	$(SRCS:.c=.o)

# FLAGS = -Wall -Werror -Wextra

# CC = gcc

# INCLUDES = headers/

# .PHONY: clean fclean all re

# all: $(NAME)

# $(NAME): $(OBJ)
# 	make -C libft
# 	make -C mlx_old
# 	# ar rc $(NAME) $(OBJ)
# 	$(CC) $(OBJ) libft/libft.a mlx_old/libmlx.a -o $(NAME)

# %.o : %.c
# 	$(CC) $(FLAGS) -I/$(INCLUDES) -c $< -o $@

# clean:
# 	make -C libft  fclean
# 	rm -f *.o

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

NAME=Cub3D

INC=-I./inc
FLAGSD=-Wall -Wextra -Werror -fsanitize=address
FLAGS=-Wall -Wextra -Werror

LIB_LINUX=-L./libft -lft -I/usr/local/include -L/usr/local/lib -lmlx -L/usr/include -lm -lbsd -lX11 -lXext
LIB_MAC=-L./libft -lft -I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIB=$(LIB_MAC)

SRC_PATH=./src/
PARSING=parsing/check_args.c \
	parsing/read_map.c \
	parsing/get_cub_data.c \
	parsing/get_color_handle.c \
	parsing/check_cub_data.c \
	parsing/get_layout.c \
	parsing/check_layout.c \
	parsing/get_textures.c
UTILS=utils/handle_errors.c \
	utils/free_functions.c \
	utils/init.c \
	utils/init2.c \
	utils/display.c \
	utils/set_position.c \
	utils/clear.c \
	utils/utils.c
ENGINE=engine/camera.c \
	engine/digital_differential_analyser.c \
	engine/ply.c \
	engine/raycasting.c \
	engine/sprite.c
EVENT=event_manager/key_event_handler.c \
	event_manager/main_loop.c \
	event_manager/window_destroy.c
RENDER=render/draw.c \
	render/texture.c \
	render/sprite.c \
	render/bitmap.c
SRCS=$(PARSING) \
	$(UTILS) \
	$(ENGINE) \
	$(EVENT) \
	$(RENDER) \
	cub3d.c

SRC=$(addprefix $(SRC_PATH), $(SRCS))

OBJ=$(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAGSD) $(INC) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	@gcc $(FLAGS) $(INC) -o $@ -c $<

clean: $(OBJ)
	@make $@ -C libft
	@rm -f $(OBJ)

fclean: clean
	@make $@ -C libft
	@rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re