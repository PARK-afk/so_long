# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 16:08:11 by hojsong           #+#    #+#              #
#    Updated: 2023/07/28 18:58:13 by junsepar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAG = -Wall -Wextra -Werror
CLIB = -I -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
HEAD = head/
NAME = so_long
SRCS = \
srcs/main.c \
srcs/check.c \
srcs/key.c \
srcs/mlx_start.c \
srcs/check_size.c \
srcs/dfs.c \
srcs/check_error.c \
srcs/exit.c \
srcs/ft_split.c \
srcs/get_next_line.c \
srcs/get_next_line_utils.c \
srcs/mlx_utils.c

OBJS = $(SRCS:.c=.o)

OBJ_CUR = $(OBJS)
NAME_CUR = $(NAME)

all : $(NAME_CUR)
	
.c.o :
	$(CC) $(CFLAG) -I $(HEAD) -c $< -o $@
$(NAME_CUR) : $(OBJ_CUR)
	$(CC) $(CFLAG) $(CLIB) -o $(NAME_CUR) $(OBJ_CUR)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME_CUR)
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re :
	make fclean
	make all

.PHONY : all re clean fclean
