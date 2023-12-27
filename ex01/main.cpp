#include "Rnp.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "Error of arg" << std::endl;
    Rnp pilee(argv[1]);

    return (0);
}