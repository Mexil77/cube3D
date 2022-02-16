# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 12:54:45 by emgarcia          #+#    #+#              #
#    Updated: 2022/02/15 12:55:21 by emgarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c
LIBFT	=	Libft/libft.a
OBJS	=	${SRCS:.c=.o}
NAME	=	cube3d
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Imlx
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