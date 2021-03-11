CC = gcc
CFLAGS = -Wextra -Wall -Werror
AR = ar rcs

NAME = libftprintf.a

SRCS = ft_printf.c\
		putstr.c\
		printf_argument.c\
		check_type.c\
		type_char.c\
		type_int.c\
		flag_int.c\
		type_integer.c\
		flag_integer.c\

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME): $(OBJS)
	make -C libft/
	cp ./libft/libft.a ./libftprintf.a
	$(AR) $@ $(OBJS)

all: $(NAME)

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

clean:
	rm -rf $(OBJS)
	make clean -C libft/

re: fclean all
