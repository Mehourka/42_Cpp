CC	= c++
#CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors


NAME = zombieHord
SRCS = $(wildcard *.cpp)


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
	valgrind ./$(NAME)
