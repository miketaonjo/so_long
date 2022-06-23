# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 10:07:52 by mcloarec          #+#    #+#              #
#    Updated: 2022/06/23 11:04:18 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  srcs/main.c
SRCS += srcs/init.c
SRCS += srcs/map.c
SRCS += srcs/check.c
SRCS += srcs/error.c
SRCS += srcs/img.c
SRCS += srcs/destroy.c
SRCS += srcs/key.c
SRCS += srcs/move.c
SRCS += srcs/imgbis.c

NAME =	so_long

CC =	gcc

RM =	rm -f

CFLAGS =	-g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
		make -C libft
		$(CC) $(CFLAGS) $(SRCS) -Llibft -lft -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:	
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
