# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 16:54:13 by kabourad          #+#    #+#              #
#    Updated: 2021/02/19 11:07:15 by kabourad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME     = cub3D.a
EXEC    = cub3D
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra
LIBFT = libft/libft.a
LIBS     = -lmlx -framework OpenGL -framework AppKit -lm

SRC = srcs/execution/calculations.c srcs/execution/clear_game.c \
		srcs/execution/drawing.c srcs/execution/key_manager.c \
		srcs/execution/movements.c srcs/execution/ray_casting.c \
		srcs/execution/save.c srcs/execution/sprites_calc.c \
		srcs/execution/sprites_rend.c srcs/execution/textures.c \
		srcs/extras/ft_arrdel.c srcs/extras/ft_arrlen.c \
		srcs/extras/ft_split_whitespaces.c srcs/extras/ft_strcmp.c \
		srcs/extras/ft_strdel.c srcs/extras/ft_strlen.c srcs/extras/quit.c \
		srcs/parsing/fills.c srcs/parsing/id_extra.c srcs/parsing/id_parse.c \
		srcs/parsing/map_check_extra.c srcs/parsing/map_check.c \
		srcs/parsing/map_parse.c srcs/parsing/parse_inits.c \
		srcs/parsing/parsing.c main.c \

OBJ = $(SRC:.c=.o)


all : $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ)

	ar rcs $(NAME) $(OBJ) libft/*.o
	$(CC) $(FLAG) $(LIBS) $(SRC) $(NAME) -o $(EXEC)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CAFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f $(EXEC)
	make fclean -C libft

re: fclean all
