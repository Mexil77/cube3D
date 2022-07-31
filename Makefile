# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 12:54:45 by emgarcia          #+#    #+#              #
#    Updated: 2022/07/31 18:14:15 by vguttenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c														\
			parse/parse_map.c parse/validations.c						\
			utils/utils.c utils/utils2.c utils/ft_error.c				\
			utils/parse_angle.c utils/tile_value.c						\
			raycast/raycast.c											\
			graphics/ft_window.c graphics/draw.c graphics/ft_minimap.c	\
			graphics/draw_pixel.c graphics/draw_map.c					\
			graphics/draw_player.c graphics/draw_fan.c					\
			game/ft_game.c
LIBFT	=	Libft/libft.a
OBJS	=	${SRCS:.c=.o}
NAME	=	cube3d
CC		=	gcc
# CFLAGS	=	-Wall -Wextra -Werror -Imlx
CFLAGS	=	-Wall -Wextra -Werror -Imlx -g3 -fsanitize=address
RM		=	rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@make -C Libft
	@${CC} ${CFLAGS} ${LIBFT} ${OBJS} -Iincludes -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	@cd Libft ; make fclean
	@${RM} ${OBJS} ${OBJS_B}

fclean: clean
	@cd Libft : make fclean
	@${RM} ${NAME} ${NAME_B} 

re: fclean all