#include "src/Computor.hpp"

int main(int argc, char ** argv) {

    //std::string eval(argv[1]);
    Computor computor(argv[1]);
    if (!computor.checkInput())
        std::cout << "Something wrong with youre input!" << std::endl;
    else
        {
            computor.split();
            computor.showEval();
            computor.solveEval();
        }
    return 0;
}