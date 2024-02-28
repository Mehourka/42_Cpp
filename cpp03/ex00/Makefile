CC	= c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors
CFLAGS = -g


NAME = claptrap
SRCS =	main.cpp\
		ClapTrap.cpp\
		ClapTrap_list.cpp\


all: re

$(NAME): $(SRCS)
	@echo Compiling ./$(NAME) ...
	$(CC) $(CFLAGS) -o $@ $(SRCS)
	@echo "Done !\n"

clean:
	@echo Deleting ./$(NAME)
	@rm -rf $(NAME)

fclean: clean

re: fclean $(NAME)

leak: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
