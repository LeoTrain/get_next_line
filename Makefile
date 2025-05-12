CC = cc
FLAGS = -Wall -Wextra -Werror
STATIC = -D BUFFER_SIZE=$(BUFFER_SIZE)
SRCS = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.h
FILE_PATH = files/
NAME = prog
BUFFER_SIZE ?= 100
FILE ?= file1
ENDING ?= .txt
FULL_PATH = $(FILE_PATH)$(FILE)$(ENDING)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(STATIC) $(SRCS) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

t: re test

test: $(NAME)
	./$(NAME) $(FULL_PATH)

.PHONY: all clean fclean re test
