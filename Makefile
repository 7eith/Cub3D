# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/30 21:50:12 by amonteli          #+#    #+#              #
#    Updated: 2020/07/23 04:04:20 by amonteli         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME		=		cub3D

HEADERS		=		includes/cub3d.h		\

SRCS 		=		cub3d.c					\
					parser/parser.c			\
					parser/conf_parser.c	\
					parser/map_parser.c		\
					utils/utilities.c		\
					ui/raycast.c			\
					ui/window.c				\
					engine/keybinds.c		\
					engine/movement.c		\

FLAGS 		= 		-Wall -Wextra -g3 -fsanitize=address

OBJS		= 		$(addprefix srcs/, $(SRCS:.c=.o)) 

LIB 		= 		libft/libft.a

all			: 		$(NAME)

$(NAME)		: $(OBJS)
		@make -C mlx re
		@make -C libft
		clang-9 $(OBJS) -I $(HEADERS) -g3 -L./mlx -lX11 -lXext -lmlx -lm -pthread -lbsd libft/libft.a -o $(NAME)
		@echo "\033[32mCub3d ready to be launched!\033[0m"

%.o: %.c libft/libft.h
		@gcc -o $@ -c $< $(FLAGS) -I libft -I mlx
		@echo "\033[34mCompiled $<\033[0m"

bonus		:		$(NAME)

clean		:
		@/bin/rm -f $(OBJS)
		@make clean -C libft
		@echo "\033[90m[\033[91mft_printf\033[90m]\033[31m Deleted *.o\033[0m"

fclean		:		clean
		@/bin/rm -f $(NAME)
		@make fclean -C libft
		@echo "\033[90m[\033[91mft_printf\033[90m]\033[31m Deleted $(NAME)\033[0m"

re			:		fclean all

norme		:
		clear
		@echo "\033[90m_________________________________________________________\n"
		@echo "\t\t\t\033[34mLibft\n"
		@norminette libft/*.c libft/*.h | grep Norme
		@echo "\033[91m"
		@-norminette libft/*.c libft/*.h | grep -B 1 Error
		@echo "\033[90m_________________________________________________________\n"
		@echo "\t\t\t\033[34mHeaders\n"
		@norminette includes/*.h | grep Norme
		@echo "\033[91m"
		@-norminette includes/*.h | grep -B 1 Error
		@echo "\033[90m_________________________________________________________\n"
		@echo "\t\t\t\033[34mParser\n"
		@-norminette srcs/parser/*.c | grep Norme
		@echo "\033[91m"
		@-norminette srcs/parser/*.c | grep -B 1 Error
		@echo "\033[90m_________________________________________________________\n"
		@echo "\t\t\t\033[34mSources\n"
		@-norminette srcs/*.c | grep Norme
		@echo "\033[91m"
		@-norminette srcs/*.c | grep -B 1 Error
		@echo "\033[90m_________________________________________________________\n"
		@echo "\t\t\t\033[34mUI\n"
		@-norminette srcs/ui/*.c | grep Norme
		@echo "\033[91m"
		@-norminette srcs/ui/*.c | grep -B 1 Error
		@echo "\033[90m_________________________________________________________\n"
		@echo "\t\t\t\033[34mEngine\n"
		@-norminette srcs/engine/*.c | grep Norme
		@echo "\033[91m"
		@-norminette srcs/engine/*.c | grep -B 1 Error
		@echo "\033[90m_________________________________________________________\n"
		@echo "\t\t\t\033[34mUtilities\n"
		@-norminette srcs/utils/*.c | grep Norme
		@echo "\033[91m"
		@-norminette srcs/utils/*.c | grep -B 1 Error
