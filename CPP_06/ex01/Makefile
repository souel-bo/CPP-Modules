NAME = reinterpreter_casting

SRC = Serializer.cpp main.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) Serializer.hpp Data.hpp
	c++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean :
	rm -rf $(NAME)

re: clean all

.PHONY: all clean re fclean