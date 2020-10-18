# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/30 01:23:03 by amonteli          #+#    #+#              #
#    Updated: 2020/10/18 06:20:48 by amonteli         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			=		cub3D

INC_DIR			=		includes

HEADERS			=		includes/cub3d.h

CC				=		clang-9

CFLAGS 			= 		-Wall -Wextra -g3 -fsanitize=address

SRCS			=		\
						main.c \
						$(addprefix parser/, parser.c args_parser.c configuration_parser.c map_parser.c parser_utils.c maps/map_checker.c) \
						$(addprefix engine/, window_manager.c keyboard_manager.c movement_manager.c rotation_manager.c) \
						$(addprefix engine/ui/, raycast.c init_raycast.c) \
						$(addprefix utils/, exit_manager.c utilities.c) \

OBJS			= 		$(addprefix srcs/, $(SRCS:.c=.o))

LIB 			= 		libft/libft.a

all				: 		$(NAME)

$(NAME)		: $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -I $(HEADERS) -g3 -L./mlx -lX11 -lXext -lmlx -lm -pthread -lbsd $(LIB) -o $(NAME)

%.o: %.c $(HEADERS)
		@$(CC) $(CFLAGS) -g3 -c $< -o $@ -I $(INC_DIR)
		@echo "\033[34mCompiled $<\033[0m"

bonus		:		$(NAME)

clean		:
		@/bin/rm -f $(OBJS)
		# @make clean -C libft
		@echo "\033[90m[\033[91mft_printf\033[90m]\033[31m Deleted *.o\033[0m"

fclean		:		clean
		@/bin/rm -f $(NAME)
		# @make fclean -C libft
		@echo "\033[90m[\033[91mft_printf\033[90m]\033[31m Deleted $(NAME)\033[0m"

re			:		fclean all
