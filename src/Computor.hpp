//
// Created by Mirex on 06.09.2018.
//

#ifndef COMPUTORV1_COMPUTOR_HPP
#define COMPUTORV1_COMPUTOR_HPP

#include <iostream>

class Computor {
    public:
        Computor();
        Computor(char * str);
        ~Computor();
        void addPower(int power, double val);
        void split();

    private:
        double  powers[10];
        char *inputString;


};


#endif //COMPUTORV1_COMPUTOR_HPP
