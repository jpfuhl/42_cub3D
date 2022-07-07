# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 19:04:01 by jpfuhl            #+#    #+#              #
#    Updated: 2022/07/07 14:56:33 by jpfuhl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
# -fsanitize=address

S			=	src/
O			=	obj/
E			=	error/
M			=	memory/
P			=	parsing/

 #move get_next_line to libft ?
OBJS		=	$(patsubst $S%.c, $O%.o, $(SRCS))
SRCS		=	$Smain.c \
				$S$Eexit_with_error.c \
				$S$Mdata.c \
				$S$Mmap.c \
				$S$Mplayer.c \
				$S$Mwindow.c \
				$S$Pcheck_cub_file_extension.c \
				$S$Pcreate_cub_array.c \
				$S$Plaunch_parser.c \
				$S$Pread_cub_file.c \



# MLX = -Lminilibx -lmlx -framework OpenGL -framework AppKit
LIBFT_PATH = libft/
# LIBFT =	make -C $(LIBFT_PATH)
LIBRARIES	=	-Llibft -lft -Llibmlx -lmlx -framework OpenGL -framework AppKit
INCLUDES	=	-I ./inc -Ilibft -Ilibmlx


all: $(NAME)

# Linking...
$(NAME):	libft/libft.a libmlx/libmlx.a $(OBJS)
			@echo "\033[1;32m$(NAME) ʕ·͡ᴥ·ʔ\033[1;0m\033[32m linking...\033[0m"
			@$(CC) $(OBJS) $(LIBRARIES) -o $(NAME)
			@echo "\033[1;32m$(NAME) ʕ·͡ᴥ·ʔ\033[1;0m\033[32m created.\033[0m"

# Compiling...
$O%.o:		$S%.c
			@[ -d $(O) ]	 || mkdir -p $(O)
			@[ -d $(O)$(E) ] || mkdir -p $(O)$(E)
			@[ -d $(O)$(M) ] || mkdir -p $(O)$(M)
			@[ -d $(O)$(P) ] || mkdir -p $(O)$(P)
			@echo "\033[1;32m$(NAME) ʕ·͡ᴥ·ʔ\033[1;0m\033[32m compiling...\033[0m"
			@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
			@rm -rf $(O)
			@make -C libmlx clean
			@make -C libft clean
			@echo "\033[31mObjects files in $(NAME) \033[1;0m\033[31mremoved.\033[0m"

#${RM} ./mlx/libmlx.a? I think it is already removed with make clean...
fclean:		clean
			@make -C libft fclean
			@rm -f $(NAME)
			@rm -f $(NAME_LK)
			@echo "\033[1;31m$(NAME) ʕ·͡ᴥ·ʔ\033[1;0m\033[31m Removed.\033[0m"

re: fclean all

libft/libft.a:
			@make -C libft all

libmlx/libmlx.a:
			@make -C libmlx all

.PHONY: all clean fclean re