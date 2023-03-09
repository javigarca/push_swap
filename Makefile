# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 15:38:08 by javigarc          #+#    #+#              #
#    Updated: 2023/03/09 17:37:56 by javigarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CHECK		=	checker

SDIR        =   sources
PSDIR       =   ps_main
CHDIR       =   ps_checker

SRCS		=	$(SDIR)/ps_actions.c \
				$(SDIR)/ps_actions_2.c \
				$(SDIR)/ps_data.c \
				$(SDIR)/ps_data_2.c \
				$(SDIR)/ps_errors.c \
				$(SDIR)/ps_list_utils.c\
				$(SDIR)/ps_sorting.c \
				$(SDIR)/ps_sorting_2.c \
				$(SDIR)/ps_sorting_3.c \
				$(SDIR)/ps_sorting_4.c \
				$(SDIR)/ps_sorting_new.c \
				$(SDIR)/ps_utils.c \

PSSRCS		=	$(PSDIR)/push_swap.c

CHSRCS		=	$(CHDIR)/checker.c \
				$(CHDIR)/ps_checker.c \
				$(CHDIR)/ps_checker_2.c \

C_OBJS		=	${SRCS:.c=.o}

PS_OBJS		=	${PSSRCS:.c=.o}

CHECK_OBJS	=	${CHSRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -Iincludes -g3 -fsanitize=address
#-g3 -fsanitize=address

RM			=	rm -rf

all: ${NAME} ${CHECK}

${NAME}: ${C_OBJS} ${PS_OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${C_OBJS} ${PS_OBJS} ./libft/libft.a -o ${NAME}

${CHECK}: ${C_OBJS} ${CHECK_OBJS}
	@${CC} ${CFLAGS} ${C_OBJS} ${CHECK_OBJS} ./libft/libft.a -o ${CHECK}

clean:
	@${MAKE} -C ./libft fclean
	@${RM} ${PS_OBJS}
	@${RM} ${C_OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}
	@make clean -C libft/

re: fclean all

.PHONY: all push_swap clean fclean re checker
