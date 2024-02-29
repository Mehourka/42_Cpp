CC	= c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors
CFLAGS = -g


NAME = fragTrap
SRCS =	main.cpp\
		ClapTrap.cpp\
		ClapTrap_list.cpp\
		ClapTrap_accessors.cpp\
		FragTrap.cpp\

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
	leaks --atExit -- ./$(NAME)
