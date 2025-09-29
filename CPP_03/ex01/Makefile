CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SOURCE =  ClapTrap.cpp  main.cpp ScavTrap.cpp
OBJ = $(SOURCE:.cpp=.o)
NAME = Clap_Trap

all: $(NAME)

$(NAME): $(OBJ) ClapTrap.hpp ScavTrap.hpp
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re