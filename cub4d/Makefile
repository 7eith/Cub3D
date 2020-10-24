# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/30 01:23:03 by amonteli          #+#    #+#              #
#    Updated: 2020/10/24 04:08:50 by amonteli         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			=		Cub3D

INC_DIR			=		includes

HEADERS			=		includes/cub3d.h

CC				=		clang-9

CFLAGS 			= 		-Wall -Wextra -Werror -O3

SRCS			=		\
						main.c \
						$(addprefix parser/, parser.c args_parser.c configuration_parser.c map_parser.c parser_utils.c maps/map_checker.c sprite_parser.c) \
						$(addprefix engine/, window_manager.c keyboard_manager.c movement_manager.c rotation_manager.c) \
						$(addprefix engine/ui/, raycast.c init_raycast.c raycast_drawer.c sprite_drawer.c) \
						$(addprefix bmp/, bmp.c) \
						$(addprefix utils/, exit_manager.c utilities.c) \

OBJS			= 		$(addprefix srcs/, $(SRCS:.c=.o))

LIB 			= 		libft/libft.a

all				: 		$(NAME)

$(NAME)		: $(OBJS)
		@make -C mlx re
		@make -C libft
		@$(CC) $(CFLAGS) $(OBJS) -I $(HEADERS) -L./mlx -lX11 -lXext -lmlx -lm -pthread -lbsd $(LIB) -o $(NAME)

%.o: %.c $(HEADERS)
		@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)
		@echo "\033[34m[Cub42D] Compiled $<\033[0m"

bonus		:		$(NAME)

clean		:
		@/bin/rm -f $(OBJS)
		@make clean -C libft
		@make clean -C mlx
		@echo "\033[90m[\033[91mCub42D\033[90m]\033[31m Deleted *.o\033[0m"

fclean		:		clean
		@/bin/rm -f $(NAME)
		@/bin/rm -f capture.bmp
		@make fclean -C libft
		@echo "\033[90m[\033[91mCub42D\033[90m]\033[31m Deleted $(NAME)\033[0m"

re			:		fclean all
