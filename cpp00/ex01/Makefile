UNAME_S := $(shell uname -s)
OS = None
NAME = phonebook
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors

SRCS = $(wildcard *.cpp)

# Changes for linux execution
ifeq ($(UNAME_S),Linux)
	OS=Linux
endif

all: $(NAME)
	./$(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	@rm -rf $(NAME)
fclean: clean

re: fclean $(NAME)

test: re
	@./$(NAME)

.PHONY: all clean fclean re
