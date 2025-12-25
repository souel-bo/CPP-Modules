CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SOURCE =  Bureaucrat.cpp  AForm.cpp  ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp main.cpp
OBJ = $(SOURCE:.cpp=.o)
NAME = AForm

all: $(NAME)

$(NAME): $(OBJ) Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

remove : 
	rm -rf home_shrubbery

.PHONY: all clean fclean re remove