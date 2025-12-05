# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 19:39:29 by htoe              #+#    #+#              #
#    Updated: 2025/12/05 09:08:09 by htoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = main.c utils.c check.c parse.c utils2.c process.c
OBJS = ${SRCS:%.c=%.o}

%.o: %.c
	@${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@${CC} ${FLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

test: all clean
	./${NAME} 1234567
	@${RM} ${NAME}

#test: all clean
#	@echo test1
#	@./${NAME} 1234567890
#	@echo test2
#	@./${NAME} newnumbers.dict 1234567890
#	@echo test3
#	@./${NAME} -
#	@${RM} ${NAME}

.PHONY: all clean fclean re test