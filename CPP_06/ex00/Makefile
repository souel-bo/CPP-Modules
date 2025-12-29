NAME = convert

SRC = ScalarConverter.cpp main.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) ScalarConverter.hpp
	c++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean :
	rm -rf $(NAME)

re: clean all

.PHONY: all clean re fclean