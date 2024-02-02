# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 20:10:07 by sbejaoui          #+#    #+#              #
#    Updated: 2023/12/13 17:19:06 by sabejaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY_DIR	=	srcs
OBJ_DIR			=	.objs

SRCS =  $(MANDATORY_DIR)/window.c		\
		$(MANDATORY_DIR)/ft_geometric.c \
		$(MANDATORY_DIR)/ft_parsing.c   \
		$(MANDATORY_DIR)/ft_utils.c     \
		$(MANDATORY_DIR)/ft_atoi_base.c \
		$(MANDATORY_DIR)/ft_psone.c     \
		$(MANDATORY_DIR)/ft_pstwo.c 	\
		$(MANDATORY_DIR)/ft_debug.c		\

OBJS			=	$(patsubst $(MANDATORY_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

HEADER_SRCS		=	fdf.h
HEADERS_DIR		=	incl/
HEADERS			=	$(addprefix $(HEADERS_DIR), $(HEADER_SRCS))
CC				=	cc
RM				=	rm -f
CFLAGS			=	-O3 -I incl -g3#-Wall -Wextra -Werror
MLX_LIB			=	-L./libmlx -lmlx -lXext -lX11 -L./gnl -lgnl 
NAME			=	fdf

GREEN			=	\033[1;32m
BLUE			=	\033[1;34m
RED				=	\033[1;31m
YELLOW      	=	\033[1;33m
DEFAULT			=	\033[0m
UP				=	"\033[A"
CUT				=	"\033[K"

$(OBJ_DIR)/%.o: $(MANDATORY_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$<]$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf ${UP}${CUT}

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$<]$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf ${UP}${CUT}

all: lib $(NAME)

lib:
	@echo "$(YELLOW)Make MLX$(DEFAULT)"
	@make -C libmlx
	@echo "$(YELLOW)Make gnl$(DEFAULT)"
	@make -C gnl
	@echo "$(BLUE)Compiling...$(DEFAULT)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX_LIB) -o $(NAME) -lm
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"

bonus: lib $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(MLX_LIB) -o $(NAME) -lm
	@echo "$(GREEN)$(NAME) bonus compiled!$(DEFAULT)"

clean:
	@echo "$(RED)Cleaning build folder$(DEFAULT)"
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)$(DEFAULT)"
	@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
