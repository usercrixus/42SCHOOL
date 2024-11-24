OBJS = \
	base.o \

all: libftmath.a

libftmath.a: $(OBJS)
	ar rcs $@ $^

%.o: %.c \
	cc -c $< -Wall -Wextra -Werror -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re
