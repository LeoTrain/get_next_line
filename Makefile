CC = cc
FLAGS = -Wall -Wextra -Werror
STATIC = -D BUFFER_SIZE=$(BUFFER_SIZE)
SRCS = get_next_line.c
FILE_PATH = files/
NAME = prog
BUFFER_SIZE ?= 100
FILE ?= file1.txt
FULL_PATH = $(FILE_PATH)$(FILE)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(STATIC) $(SRCS) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

test: $(NAME)
	./$(NAME) $(FULL_PATH)

.PHONY: all clean fclean re test
