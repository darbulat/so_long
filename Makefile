NAME		= 	so_long
LIB			=	libft/libft.a
INCS		=	libft -I ./

SRCS		=	main.c 							\
				movement.c						\
				gnl/get_next_line.c				\
				map_parser.c					\
				map_checker.c					\
				init_vars.c

HEADERS		= 	so_long.h
OBJ			=	$(SRCS:.c=.o)
FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc

OS := $(shell uname)
ifeq ($(OS),Linux)
	MINILIBX = -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz -g
	FLAGS += -I/usr/include -Imlx_Linux -O3
else
	SO_LONG_IS_MACOS = 1
	MINILIBX = -Lmlx -lmlx -framework OpenGL -framework AppKit
	FLAGS += -Imlx
endif

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(HEADERS) $(OBJ)
	@make -C ./libft
	$(CC) $(OBJ) $(LIB) -I$(INCS) $(MINILIBX) -o $(NAME)

clean:
	rm -f  $(OBJ)
	@make clean -C ./libft

fclean:	clean
	rm -f $(NAME) $(OBJ)
	@make fclean -C ./libft

re: fclean all
.PHONY:    all clean fclean re
