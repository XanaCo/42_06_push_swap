# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 18:07:11 by ancolmen          #+#    #+#              #
#    Updated: 2023/04/06 19:06:41 by ancolmen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######	VARIABLES

NAME		= push_swap
CHECKER		= checker
LIBFT		= libft.a

LFT_PATH	= ./libft/
INC_PATH	= ./include
SRC_PATH	= ./src/

PS			= ${SRC_PATH}main.c
CH			= ${SRC_PATH}checker_bonus.c

SRC			= ${SRC_PATH}fill_and_check.c \
				${SRC_PATH}start_program.c \
				${SRC_PATH}list_utils.c \
				${SRC_PATH}utils.c \
				${SRC_PATH}lis.c \
				${SRC_PATH}cost.c \
				${SRC_PATH}sort.c \
				${SRC_PATH}instructions.c \
				${SRC_PATH}print_and_check.c \
				${SRC_PATH}free_and_exit.c

OBJ			= ${notdir ${PS:.c=.o}} ${notdir ${SRC:.c=.o}}
OBJ_BONUS	= ${notdir ${CH:.c=.o}} ${notdir ${SRC:.c=.o}}

CC			= cc
CFLAGS		= -Wall -Wextra -Werror 
CFI 		= -I${INC_PATH}

LEAKS 		= valgrind ./push_swap

LF 			= --leak-check=full \
        		--show-leak-kinds=all \
        		--track-origins=yes \
        		--verbose \

RM			= rm -rf

#######	RULES

${NAME}: ${OBJ} ${LIBFT}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} ${LFT_PATH}${LIBFT}

${CHECKER} : ${OBJ_BONUS} ${LIBFT}
	${CC} ${CFLAGS} -o ${CHECKER} ${OBJ_BONUS} ${LFT_PATH}${LIBFT}

${OBJ}: ${PS} ${SRC}
	${CC} ${CFLAGS} -c -I${INC_PATH} ${PS} ${SRC}

${OBJ_BONUS}: ${CH} ${SRC}
	${CC} ${CFLAGS} -c -I${INC_PATH} ${CH} ${SRC}

${LIBFT}:
	@make -C ${LFT_PATH}
	

all: ${NAME}

bonus: ${CHECKER}

leaks:
	${LEAKS} ${LF}

clean:
	@make clean -C ${LFT_PATH}
	${RM} ${OBJ}
	${RM} ${OBJ_BONUS}

fclean: clean
	@make fclean -C ${LFT_PATH}
	${RM} ${NAME}
	${RM} ${CHECKER}	

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
