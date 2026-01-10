CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SOURCE = main.cpp 
OBJ = $(SOURCE:.cpp=.o)
NAME = ./stack_mutant

all: $(NAME)

$(NAME): $(OBJ) MutantStack.hpp
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re