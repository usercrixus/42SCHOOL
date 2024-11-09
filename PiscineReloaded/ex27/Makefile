OBJS = \
	ft_display_file.o\

all: ft_display_file

ft_display_file: $(OBJS)
	gcc $^ -o $@
	
%.o: %.c
	gcc -c $< -Wall -Wextra -Werror -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ft_display_file

re: fclean all

.PHONY: all clean fclean re
