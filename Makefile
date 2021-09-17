NAME		= 	so_long
LIB			=	libft/libft.a
INCS		=	libft -I ./

SRCS		=	main.c 							\
				movement.c						\
				gnl/get_next_line.c

HEADERS		= 	so_long.h
OBJ			=	$(SRCS:.c=.o)
FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc

all: $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_Linux -O3 -c $< -o $@

$(NAME): $(HEADERS) $(OBJ)
	@make -C ./libft
	$(CC) $(OBJ) $(LIB) -I$(INCS) -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz -g -o $(NAME)

clean:
	rm -f  $(OBJ)
	@make clean -C ./libft

fclean:	clean
	rm -f $(NAME) $(OBJ)
	@make fclean -C ./libft

re: fclean all
.PHONY:    all clean fclean re
