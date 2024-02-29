CC	= c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors

INFILE = tmp/infile.txt
STR1 = cas
STR2 = X


NAME = mySed
# SRCS = $(wildcard *.cpp)
SRCS =	main.cpp\

all: $(NAME)

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
