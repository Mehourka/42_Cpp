CC	= c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors


NAME = fixed_2_0
SRCS = main.cpp\
	   Fixed.cpp\
	   Fixed_overloads.cpp\



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

leak:
	leaks -atExit -- ./$(NAME)
