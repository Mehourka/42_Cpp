CC		= c++
CFLAGS	= -Wall -Werror -Wextra  -std=c++98

NAME	= megaphone

SRCS	= $(wildcard *.cpp)

all: re
	./$(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $@ $(SRCS)

re: fclean $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

.PHONY: all re clean fclean