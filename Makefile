# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 16:54:13 by kabourad          #+#    #+#              #
#    Updated: 2021/02/20 14:48:17 by kabourad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


MLX = -lmlx -lm -framework OpenGL -framework AppKit
#MLX = -I /usr/include -g -L /usr/lib -lX11 -lmlx -lXext -lm -fsanitize=address

NAME = cub3D

SRCS = srcs/execution/calculations.c srcs/execution/clear_game.c \
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


OBJSRCS = $(SRCS:.c=.o)

$(NAME) : $(OBJSRCS)
	@echo "\033[33m[Remove last version...]"
	@rm -rf Cub3D
	@echo "\033[33m[Libft compilation...]"
	@$(MAKE) -C ./libft
	@echo "\033[33m[Cub3D compilation...]"
	@gcc  $(OBJSRCS) -I./includes -I./usr/include -Wall -Wextra -Werror $(MLX) ./libft/libft.a -o $(NAME)
	@echo "\033[33m[Done !]"

all : credit $(NAME)

clean :
	rm -rf $(OBJSRCS)
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./mlx

fclean : clean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./mlx
	rm -rf $(NAME)
	rm -rf cub3d.bmp

re : fclean all

credit:
	@echo ":::::::::     :::     ::::    ::: :::::::::      :::     "
	@echo ":+:    :+:  :+: :+:   :+:+:   :+: :+:    :+:   :+: :+:   "
	@echo "+:+    +:+ +:+   +:+  :+:+:+  +:+ +:+    +:+  +:+   +:+  "
	@echo "+#++:++#+ +#++:++#++: +#+ +:+ +#+ +#+    +:+ +#++:++#++: "
	@echo "+#+       +#+     +#+ +#+  +#+#+# +#+    +#+ +#+     +#+ "
	@echo "#+#       #+#     #+# #+#   #+#+# #+#    #+# #+#     #+# "
	@echo "###       ###     ### ###    #### #########  ###     ### "
