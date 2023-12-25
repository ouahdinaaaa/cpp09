#include "Rnp.hpp"


int main(int argc, char **argv)
{
    if (argc != 1){
        std::cout << "error arg" << std::endl;
        return 1;
    }
    std::string line;
    int         resultat;
    std::cout << "Give me your operation" << std::endl;
    std::getline(std::cin, line);
    resultat = RPN(line);
    std::cout << "Resultat : " << resultat << std::endl;
    return (0);
}