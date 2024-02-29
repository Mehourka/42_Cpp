CC	= c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors

NAME = HarlFilter
SRCS =	main.cpp\
		Harl.cpp\

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

run: re
	./$(NAME) $(INFILE) $(STR1) $(STR2)

leak: re
	leaks -atExit -- ./$(NAME)
