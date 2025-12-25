#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat bob("Bob", 140);
        Bureaucrat alice("Alice", 150);
        Bureaucrat charlie("Charlie", 130);

        ShrubberyCreationForm form("home");

        std::cout << "Bob tries to sign the form..." << std::endl;
        bob.signForm(form);

        // std::cout << "Alice tries to sign the form..." << std::endl;
        // alice.signForm(form);

        std::cout << "Bob tries to execute the form..." << std::endl;
        bob.executeForm(form);

        std::cout << "Charlie tries to execute the form..." << std::endl;
        charlie.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
