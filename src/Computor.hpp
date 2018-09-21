//
// Created by Mirex on 06.09.2018.
//

#ifndef COMPUTORV1_COMPUTOR_HPP
#define COMPUTORV1_COMPUTOR_HPP

#define MAX_DEGREE 4

#include <iostream>

class Computor {
    public:
        Computor();
        Computor(char * str);
        ~Computor();
        void addPower(int power, double val);
        void split();
        void getNumbers(char * substring, int inverse);
        void showEval();
        void solveEval();
        bool checkInput();
        int getDegree();

    private:
        double  powers[MAX_DEGREE];
        char *inputString;
        int _PolynomalDegree = 0;


};


#endif //COMPUTORV1_COMPUTOR_HPP
