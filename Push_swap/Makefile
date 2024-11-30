OBJS = \
	main.o \
	push_swap_action.o \
	push_swap_brute_force.o \
	push_swap_helper.o \
	push_swap_lis.o \
	push_swap_normalize.o \
	push_swap_utils.o \

all: libft.a libftmath.a push_swap

push_swap: $(OBJS)
	cc $^ -L../libft/base -lft -L../libft/math -lftmath -o $@

debug: $(OBJS)
	cc $^ -L../libft/base -lft -L../libft/math -lftmath -o $@ -g3

%.o: %.c \
	cc -c $< -Wall -Wextra -Werror -o $@

libftmath.a:
	make -C ../libft/math all

libft.a:
	make -C ../libft/base all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re
