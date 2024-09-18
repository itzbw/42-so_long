# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwong <bwong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 16:27:57 by bwong             #+#    #+#              #
#    Updated: 2022/07/10 16:43:39 by bwong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

LIBFT_DIR	=	libft/

MLX_DIR		=	minilibx_opengl_20191021/

SRCS_DIR	=	srcs/

HEADER_DIR	=	includes/

SRCS_LST	=	main.c			parse.c			create_map.c\
				render_map.c	key.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LST))

HEADER		=	$(addprefix $(HEADER_DIR), so_long.h)

OBJS		=	$(patsubst %.c, %.o, $(SRCS))

CC			=	gcc

INCLUDES	=	-I$(HEADER_DIR) -I$(LIBFT_DIR)$(HEADER_DIR) -I$(MLX_DIR)

LFT_FLAGS	=	-L$(LIBFT_DIR) -lft

MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

RM			=	rm -f

OBJECTS 	=	$(OBJS)

.PHONY		:	all clean fclean re bonus

all			:	$(NAME)

$(NAME)		:	$(OBJECTS) $(HEADER)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LFT_FLAGS) $(MLX_FLAGS) $(OBJECTS) -o $@

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean		:	clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re			:	fclean all