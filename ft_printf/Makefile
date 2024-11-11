OBJS = \
	ft_printf.o \
	print_hex.o \
	print_str.o \
	print_char.o \
	print_dec.o \

all: libftprintf.a

libftprintf.a: Libft/libft.a $(OBJS)
	ar rcs $@ $^

Libft/libft.a:
	make -C Libft all

%.o: %.c
	cc -c $< -Wall -Wextra -Werror -I Libft -o $@

test: libftprintf.a
	cc test.c -Wall -Wextra -Werror -L. -LLibft -lftprintf -lft -o test.out

clean:
	rm -f $(OBJS)
	make -C Libft clean

fclean: clean
	rm -f libftprintf.a test.out
	make -C Libft fclean

re: fclean all

.PHONY: all clean fclean re