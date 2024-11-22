ARGS = ./data/data.csv
CC	= g++
CFLAGS = -g -Wall -Werror -Wextra -std=c++98 -pedantic-errors -Wno-unused -Wconversion

NAME := btc
SRCS := $(wildcard *.cpp)

OBJDIR	:= obj/
OBJS	:= $(SRCS:%.cpp=$(OBJDIR)%.o)

CYAN	:= "\033[0;36m"
PURPLE	:= "\033[0;35m"
RESET	:= "\033[00m"


all: $(NAME)

run: re
	@echo $(CYAN)Running ./$(NAME) ...$(RESET)"\n"
	@./$(NAME) $(ARGS)

$(NAME): $(OBJS)
	@echo $(PURPLE)Compiling ./$(NAME) ... $(RESET)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	@echo $(CYAN)"Done !\n"$(RESET)

$(OBJDIR)%.o: %.cpp
	@mkdir -p $(@D);
	@$(CC) -c $(CFLAGS) -MMD -MP $< -o $@

-include $(DEPS)

clean:
	@echo $(PURPLE)Deleting Object files
	@rm -rf $(OBJDIR)

fclean: clean
	@echo $(PURPLE)Deleting ./$(NAME)
	@rm -rf $(NAME)

re: fclean $(NAME)

leak: re
	leaks -atExit -- ./$(NAME)
