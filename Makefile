# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 19:04:01 by jpfuhl            #+#    #+#              #
#    Updated: 2022/07/13 10:59:12 by arendon-         ###   ########.fr        #
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
X			=	raycasting/
R			=	rendering/

 #move get_next_line to libft ?
OBJS		=	$(patsubst $S%.c, $O%.o, $(SRCS))
SRCS		=	$Smain.c \
				$S$Eexit_with_error.c \
				$S$Mbuttons.c \
				$S$Mdata.c \
				$S$Mmap.c \
				$S$Mplayer.c \
				$S$Mwindow.c \
				$S$Pcheck_cub_file_extension.c \
				$S$Pcheck_grid_borders.c \
				$S$Pconvert_rgb_to_hex.c \
				$S$Pcreate_cub_array.c \
				$S$Pcreate_tile_grid.c \
				$S$Pget_texture.c \
				$S$Plaunch_parser.c \
				$S$Pparse_elements.c \
				$S$Pparse_map.c \
				$S$Pread_cub_file.c \
				$S$Pset_colour.c \
				$S$Pset_dimensions.c \
				$S$Pset_player_position.c \
				$S$Pset_texture.c \
				$S$Pset_tile_grid.c \
				$S$Pset_tile_size.c \
				$S$Xcalculate_line_height.c \
				$S$Xcalculate_line_position.c \
				$S$Xcalculate_perp_wall_distance.c \
				$S$Xcheck_wall_collision.c \
				$S$Xcheck_walls.c \
				$S$Xdda_algorithm.c \
				$S$Xraycasting.c \
				$S$Rcreate_image.c \
				$S$Rdraw_background.c \
				$S$Rdraw_map.c \
				$S$Rdraw_pixel.c \
				$S$Rdraw_player.c \
				$S$Rdraw_square.c \
				$S$Rdraw_wall.c \
				$S$Rkeyhooks.c \
				$S$Rmovement_collision.c \
				$S$Rmovement.c \
				$S$Rrender_frame.c \
				$S$Rresize_image.c \




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
			@[ -d $(O)$(X) ] || mkdir -p $(O)$(X)
			@[ -d $(O)$(R) ] || mkdir -p $(O)$(R)
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