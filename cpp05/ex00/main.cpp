#include "Bureaucrat.hpp"

int main() {
    // Testing default constructor
    Bureaucrat bureaucrat1;
    std::cout << "Bureaucrat 1: " << bureaucrat1 << std::endl;

    // Testing parameterized constructor
    try {
        Bureaucrat bureaucrat2("John", 50);
        std::cout << "Bureaucrat 2: " << bureaucrat2 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Testing copy constructor
    Bureaucrat bureaucrat3 = bureaucrat1;
    std::cout << "Bureaucrat 3 (Copy of 1): " << bureaucrat3 << std::endl;

    // Testing assignment operator
    Bureaucrat bureaucrat4;
    bureaucrat4 = bureaucrat3;
    std::cout << "Bureaucrat 4 (Assigned from 3): " << bureaucrat4 << std::endl;

    // Testing increment and decrement
    try {
        bureaucrat1.incrementGrade();
        std::cout << "After increment: " << bureaucrat1 << std::endl;

        bureaucrat1.decrementGrade();
        std::cout << "After decrement: " << bureaucrat1 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Testing invalid grade
    try {
        Bureaucrat invalidBureaucrat("Invalid", 160);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
