# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 20:10:07 by sbejaoui          #+#    #+#              #
#    Updated: 2023/11/20 13:43:01 by sabejaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

SRCS =  get_next_line_utils.c \
		get_next_line.c

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f

FLAGS = -Wall -Wextra -Werror

%.o : %.c gnl.h
	${CC} ${FLAGS} -I includes -c $< -o $@

$(NAME): ${OBJS} 
	ar rc ${NAME} ${OBJS} 

all: ${NAME} 

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean fclean re