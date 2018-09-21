#include "src/Computor.hpp"

int main(int argc, char ** argv) {

if (argc == 2)
{
    Computor computor(argv[1]);
    if (!computor.checkInput())
        std::cout << "Something wrong with youre input!" << std::endl;
    else
        {
            computor.split();
            computor.showEval();
            computor.solveEval();
        }
}
else
	{
		std::cout << "Wrong number of parameters!" << std::endl;
	}
    return 0;
}
