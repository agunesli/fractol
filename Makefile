SRC_M	= test.c utils.c mandelbrot.c

SRC_H	= fractol.h

OBJ_M	= $(SRC_M:%.c=%.o)

NAME	=	fractol
CC	=	gcc
FLAGS	=	-g3 -Wall -Wextra -Werror
MLX	=	-g3 -lmlx -framework OpenGL -framework Appki
RM	=	rm -rf

%.o: %.c
#	$(CC) $(FLAGS) -I/usr/include -Imlx -O3 -c $< -o $@	
	$(CC) -I/usr/include -Imlx -O3 -c $< -o $@	

$(NAME):$(OBJ_M) $(SRC_H)
	$(CC) $(OBJ_M) -g3 -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

all:	$(NAME)

#$(NAME_B)	: $(OBJ_F) $(OBJ_B) $(SRC_H)
#		$(CC) $(OBJ_F) $(OBJ_B) -o $(NAME_B)

#bonus:	$(NAME_B)
clean:
		$(RM) $(OBJ_M)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean bonus re
