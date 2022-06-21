# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 13:32:42 by gifulvi           #+#    #+#              #
#    Updated: 2022/06/21 16:57:25 by mtoia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

GREENGREEN = \033[38;5;46m
RESET = \033[0m

SRC=  algo.c draw.c ft_atoi.c main.c key.c Julia.c ft_strncmp.c \

PRINTF = ft_printf

HDRS = mlx/

OBJ = $(SRC:.c=.o)

RM = rm -f

CC		=	gcc

CFLAGS	= -g

LIBS = -lm -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -I ${HDRS} -c $< -o $@

$(NAME): printf $(OBJ)
		@(test -f $(MLX)  && echo "[$(GREENGREEN)MLX already built$(RESET): Was Created $(NAME)...$(RESET)") || (make -C ./minilibx && mv minilibx/libmlx.dylib .)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS) ft_printf/ft_printf.a

printf:
	@echo "[$(GREENGREEN)Printf$(RESET)]: Creating $(PRINTF)...$(RESET)"
	make -C $(PRINTF)

all: $(NAME)
	make clean

clean:
	${RM} $(OBJ)

fclean:
	${RM} $(NAME) ${OBJ}
	make -C ./mlx clean
	make -C ./ft_printf fclean

re: fclean $(NAME)

run: all


.PHONY: all clean fclean re reb
