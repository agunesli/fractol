SRC_M	= fractol.c utils.c hook.c color.c \
	mandelbrot.c julia.c burningship.c

SRC_H	= fractol.h

OBJ_M	= $(SRC_M:%.c=%.o)

NAME	=	fractol
CC	=	gcc
FLAGS	=	-g3 -Wall -Wextra -Werror
RM	=	rm -rf

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx -O3 -c $< -o $@	


$(NAME):$(OBJ_M) $(SRC_H)
	$(CC) $(OBJ_M) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME) 

all:	$(NAME)

bonus:	$(NAME)

clean:
		$(RM) $(OBJ_M)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean bonus re
