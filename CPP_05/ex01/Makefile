CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SOURCE =  Bureaucrat.cpp  main.cpp Form.cpp
OBJ = $(SOURCE:.cpp=.o)
NAME = Form

all: $(NAME)

$(NAME): $(OBJ) Bureaucrat.hpp Form.hpp
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re