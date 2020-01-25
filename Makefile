# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/30 21:50:12 by amonteli     #+#   ##    ##    #+#        #
#    Updated: 2020/01/25 02:35:52 by amonteli    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		=		Cub3D

HEADERS		=		includes/cub3d.h		\

LIBFT_INC	=		libft/libft.h

LIBFT_SRCS	=		ft_atoi.c				\
					ft_bzero.c				\
					ft_isalnum.c			\
					ft_isalpha.c			\
					ft_isascii.c			\
					ft_isdigit.c			\
					ft_isprint.c			\
					ft_memcpy.c				\
					ft_memset.c				\
					ft_strchr.c				\
					ft_strrchr.c			\
					ft_strlen.c				\
					ft_strncmp.c			\
					ft_strnstr.c			\
					ft_tolower.c			\
					ft_toupper.c			\
					ft_memccpy.c			\
					ft_memmove.c			\
					ft_memchr.c				\
					ft_memcmp.c				\
					ft_calloc.c				\
					ft_strdup.c				\
					ft_strlcpy.c			\
					ft_strlcat.c			\
					ft_substr.c				\
					ft_strjoin.c			\
					ft_strtrim.c			\
					ft_split.c				\
					ft_itoa.c				\
					ft_strmapi.c			\
					ft_putchar_fd.c			\
					ft_putstr_fd.c			\
					ft_putendl_fd.c			\
					ft_putnbr_fd.c			\
					ft_lstnew.c				\
					ft_lstadd_front.c		\
					ft_lstsize.c			\
					ft_lstlast.c			\
					ft_lstadd_back.c		\
					ft_lstdelone.c			\
					ft_lstclear.c			\
					ft_lstiter.c			\
					ft_lstmap.c				\

SRCS 		=		cub3d.c					\
					parser/parser.c			\
					parser/conf_parser.c	\
					parser/map_parser.c		\
					utils/utilities.c		\

FLAGS 		= 		-Wall -Wextra -g3 -fsanitize=address

OBJS		= 		$(addprefix srcs/, $(SRCS:.c=.o)) $(addprefix libft/, $(LIBFT_SRCS:.c=.o))

LIB 		= 		libft/libft.a

all			: 		$(NAME)

$(NAME)		: $(OBJS)
		@make -C mlx
		@make -C libft
		@cp libft/libft.a $(NAME)
		@gcc $(FLAGS) -I mlx -L mlx -lmlx -framework OpenGL -framework AppKit -I $(HEADERS) $(OBJS) $(LIB) -o $(NAME)
		@echo "\033[32mCub3d ready to be launched!\033[0m"

%.o: %.c $(HEADERS) libft/libft.h
		@gcc -I $(HEADERS) -I $(LIBFT_INC) -o $@ -c $< $(FLAGS)
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
		@echo "\t\t\t\033[34mUtilities\n"
		@-norminette srcs/utils/*.c | grep Norme
		@echo "\033[91m"
		@-norminette srcs/utils/*.c | grep -B 1 Error
