NAME = libftprintf.a

SRCS = ft_printf.c ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_pointer.c ft_print_string.c ft_print_unsigned_int.c

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