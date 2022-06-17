# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 13:32:42 by gifulvi           #+#    #+#              #
#    Updated: 2022/06/13 19:36:07 by mtoia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol


SRC=  algo.c draw.c ft_atoi.c main.c key.c
HDRS = mlx/

OBJ = $(SRC:.c=.o)

RM = rm -f

CC		=	gcc

CFLAGS	= -g

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -I ${HDRS} -c $< -o $@

$(NAME): $(OBJ)
		@(test -f $(MLX)  && echo "\033[32mMLX already built\033[0m") || (make -C ./minilibx && mv minilibx/libmlx.dylib .)
		$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) 

all: $(NAME)
	make clean

clean:
	${RM} $(OBJ)

fclean:
	${RM} $(NAME) ${OBJ}
	make -C ./mlx clean

re: fclean $(NAME)

run: all


.PHONY: all clean fclean re reb
