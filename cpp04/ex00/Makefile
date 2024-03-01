CC	= c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors

NAME = polymorphisme
SRCS =	main.cpp Animal.cpp Cat.cpp Dog.cpp\
		WrongAnimal.cpp WrongCat.cpp\

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

leak: re
	leaks --atExit -- ./$(NAME)
