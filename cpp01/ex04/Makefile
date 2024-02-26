CC	= c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors

INFILE = tmp/infile.txt
STR1 = red
STR2 = blue


NAME = mySed
# SRCS = $(wildcard *.cpp)
SRCS =	main.cpp\

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
	valgrind ./$(NAME)
