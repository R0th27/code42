# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 06:06:39 by htoe              #+#    #+#              #
#    Updated: 2025/12/12 07:03:14 by htoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables
NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c

OBJS = ${SRCS:%.c=%.o}

CC = cc 

FLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

#pattern rules
%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

#Non-file declaration
.PHONY: all clean fclean re