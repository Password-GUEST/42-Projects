# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 20:10:07 by sbejaoui          #+#    #+#              #
#    Updated: 2022/01/22 20:27:09 by sbejaoui         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  ft_memset.c     \
		ft_isalnum.c    \
		ft_isprint.c    \
		ft_memcpy.c     \
		ft_putendl_fd.c \
		ft_strchr.c     \
		ft_strlcat.c    \
		ft_strncmp.c    \
		ft_substr.c     \
		ft_atoi.c       \
		ft_isalpha.c    \
		ft_itoa.c       \
		ft_memmove.c    \
		ft_putnbr_fd.c  \
		ft_strdup.c     \
		ft_strlcpy.c    \
		ft_strnstr.c    \
		ft_tolower.c    \
		ft_bzero.c      \
		ft_isascii.c    \
		ft_memchr.c     \
		ft_memset.c     \
		ft_putstr_fd.c  \
		ft_striteri.c   \
		ft_strlen.c     \
		ft_strrchr.c    \
		ft_toupper.c    \
		ft_calloc.c     \
		ft_isdigit.c    \
		ft_memcmp.c     \
		ft_putchar_fd.c \
		ft_split.c      \
		ft_strjoin.c    \
		ft_strmapi.c    \
		ft_strtrim.c 	\
		ft_atoi_base.c	\
		ft_splitcmd.c	\
		ft_lstnew.c 	    \
		ft_lstadd_front.c \
    	ft_lstsize.c      \
    	ft_lstlast.c      \
    	ft_lstadd_back.c  \
    	ft_lstdelone.c	\
		ft_lstclear.c     \
		ft_lstiter.c      \
		ft_lstmap.c 	  \
		ft_strichr.c	

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
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean fclean re