OBJS = \
	ft_printf.o \
	print_hex.o \
	print_str.o \
	print_char.o \
	print_dec.o \

all: libftprintf.a

libftprintf.a: $(OBJS) libft/libft.a
	# Combine libft.a and ftprintf objects into libftprintf.a
	cp libft/libft.a libftprintf.a
	ar rcs libftprintf.a $(OBJS)

libft/libft.a:
	make -C libft all

%.o: %.c
	cc -c $< -Wall -Wextra -Werror -I libft -o $@

test: libftprintf.a libft/libft.a
	cc test.c -Wall -Wextra -Werror -L. -lftprintf -o test.out

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f libftprintf.a test.out
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
