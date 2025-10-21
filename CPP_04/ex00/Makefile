CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SOURCE =  Animal.cpp  Cat.cpp  Dog.cpp  main.cpp WrongAnimal.cpp WrongCat.cpp
OBJ = $(SOURCE:.cpp=.o)
NAME = animal

all: $(NAME)

$(NAME): $(OBJ) Animal.hpp  Cat.hpp  Dog.hpp WrongCat.hpp WrongAnimal.hpp
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re