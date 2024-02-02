# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 15:56:34 by sabejaou          #+#    #+#              #
#    Updated: 2023/11/08 11:05:03 by sabejaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  srcs/ft_printf.c		\
		srcs/ft_putadd_fd.c		\
		srcs/ft_putadd_ul_fd.c	\
		srcs/ft_putnbr_fd.c		\
		srcs/ft_putnbr_ul_fd.c	\
		srcs/ft_putstr_fd.c		\

			
OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f

FLAGS = -Wall -Wextra -Werror

%.o : %.c libft.h
	${CC} ${FLAGS} -I includes -c $< -o $@

$(NAME): ${OBJS} 
	ar rc ${NAME} ${OBJS}

all: ${NAME} 

clean:
	${RM} ${OBJS} ${OBJS_BNS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean fclean re