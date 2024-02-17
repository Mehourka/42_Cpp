UNAME_S := $(shell uname -s)
OS = None
NAME = megaphone
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors
SRCS = $(wildcard *.cpp)

ifeq ($(UNAME_S),Linux)
	OS=Linux
endif


all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	@rm -rf $(NAME)
fclean: clean

re: fclean $(NAME)

test: re
	@./$(NAME) "shhhhh... I think the students are asleep..."
	@./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@./$(NAME) Marry " had a little" " Lamb ?"

.PHONY: all clean fclean re
