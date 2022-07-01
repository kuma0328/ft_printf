NAME = libftprintf.a

SRCS = ft_printf.c print_utils.c printf_contents.c

CC = gcc
CFLAGS = -Wall-Werror-Werror
AR = ar rcs
RM = rm -f

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

.c.o:
	$(CC) $(CFLAG) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all