# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 12:39:51 by ancolmen          #+#    #+#              #
#    Updated: 2023/04/06 18:42:58 by ancolmen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######	VARIABLES

NAME	= libft.a

CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_striteri.c ft_strmapi.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	get_next_line.c ft_printf.c ft_format_base.c ft_putchar.c \
	ft_putnbr.c ft_putnbr_u.c ft_putnbr_base.c ft_putptr.c \
	ft_putstr.c ft_strrncmp.c ft_countchar.c ft_free_matrix.c ft_iswspace.c \
	ft_abs.c ft_strcmp.c

INC		= .

OBJS	= ${SRCS:.c=.o}

CC		= cc

RM 		= rm -rf

LIBC	= ar rc

#######	RULES

all: ${NAME}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INC}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re