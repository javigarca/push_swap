# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 15:38:08 by javigarc          #+#    #+#              #
#    Updated: 2023/01/07 20:53:51 by javigarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
#CHECK = checker

SRCS	=	$(wildcard sources/*.c)
#CHECK_SRCS = $(wildcard utils/*.c) src/instructions.c checker.c

OBJS	=	${SRCS:.c=.o}
#CHECK_OBJS = ${CHECK_SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -Iincludes -g
#-g3 -fsanitize=address

RM		=	rm -rf

all: ${NAME} ${CHECK}

${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

${CHECK}: ${CHECK_OBJS}
	@${CC} ${CFLAGS} ${CHECK_OBJS} ./libft/libft.a -o ${CHECK}

clean:
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}
	@make clean -C libft/

re: fclean all

.PHONY: all push_swap clean fclean re checker
