OBJS = \
	srcs/ft_putchar.o\
	srcs/ft_swap.o\
	srcs/ft_putstr.o\
	srcs/ft_strlen.o\
	srcs/ft_strcmp.o

all: libft.a

libft.a: $(OBJS)
	ar rcs $@ $^
	
%.o: %.c
	cc -c $< -Wall -Wextra -Werror -I ./includes -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re
