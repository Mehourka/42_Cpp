CC	= c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors

NAME = Materia
SRCS =	main.cpp \
		AMateria.cpp \
		AMateria_list.cpp\
		Ice.cpp\
		Cure.cpp\
		Character.cpp\



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
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
# leaks --atExit -- ./$(NAME)
