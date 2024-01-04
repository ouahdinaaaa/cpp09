#include "Rnp.hpp"


int main(int argc, char **argv)
{
    if (argc != 2){
        std::cout << "Error of arg" << std::endl;
        return 1;
    }
    try{
        Rpn pilee;
        pilee.parse(argv[1]);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;}
    return 0;
}