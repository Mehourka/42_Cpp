CC	= c++
CFLAGS = -g -Wall -Werror -Wextra -std=c++98 -pedantic-errors

NAME := $(notdir $(shell pwd))
SRCS := $(wildcard *.cpp)

OBJDIR	:= obj/
OBJS	:= $(SRCS:%.cpp=$(OBJDIR)%.o)

CYAN	:= "\033[0;36m"
PURPLE	:= "\033[0;35m"



all: $(NAME)

run: re
	@echo $(CYAN)Running ./$(NAME) ... "\n"
	@./$(NAME)

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
	@rm -f $(OBJS)

fclean: clean
	@echo $(PURPLE)Deleting ./$(NAME)
	@rm -rf $(NAME)

re: fclean $(NAME)

leak: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)