ARGS=42.42f

CC	= g++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors -Wno-unused -Wconversion

NAME := $(notdir $(shell pwd))
NAME := convert
SRCS := $(wildcard *.cpp)

OBJDIR	:= obj/
OBJS	:= $(SRCS:%.cpp=$(OBJDIR)%.o)

CYAN	:= "\033[0;36m"
PURPLE	:= "\033[0;35m"


all: $(NAME)

run: re
	@echo $(CYAN)Running ./$(NAME) ... "\n"
	@./$(NAME) $(ARGS)

$(NAME): $(OBJS)
	@echo $(PURPLE)Compiling ./$(NAME) ...
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	@echo $(CYAN)"Done !\n"

$(OBJDIR)%.o: %.cpp
	@mkdir -p $(@D);
	@$(CC) -c $(CFLAGS) -MMD -MP $< -o $@

-include $(DEPS)

clean:
	@echo $(PURPLE)Deleting Object files
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo $(PURPLE)Deleting ./$(NAME)
	@rm -rf $(NAME)

re: fclean $(NAME)

test: re
	./$(NAME) 0
	./$(NAME) nan
	./$(NAME) 42.0f
	./$(NAME) 123
	./$(NAME) -nanf
	./$(NAME) -inf
	./$(NAME) inff
	./$(NAME) 5000000000
	./$(NAME) -420000000


leak: re
	leaks -atExit -- ./$(NAME)
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
