CC      = gcc
CFLAGS  =
AR      = ar rcs

NAME    = libft.a
HEAD    = libft.h
SRCS    = ft_memcpy.c ft_memset.c ft_bzero.c ft_isalpha.c ft_isdigit.c \
	ft_islower.c ft_isspace.c ft_isupper.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
	ft_strnstr.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_calloc.c\
	ft_toupper.c ft_tolower.c ft_strdup.c ft_atoi.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c\
	ft_strjoin.c ft_itoa.c ft_substr.c ft_strtrim.c ft_split.c \
	ft_strrchr.c ft_strncmp.c\
	ft_strsfree.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(HEAD)
		$(AR) $(NAME) $?

%.o : %.c $(HEAD)
		$(CC) $(CFLAGS)  -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

bonus:	$(NAME)

.PHONY: all, clean, fclean, re
