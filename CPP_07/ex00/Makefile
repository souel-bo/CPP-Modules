NAME = whatever

SRC =  main.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) whatever.hpp
	c++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean :
	rm -rf $(NAME)

re: clean all

.PHONY: all clean re fclean