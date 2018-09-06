//
// Created by Mirex on 06.09.2018.
//

#include "Computor.hpp"


Computor::Computor() {}

Computor::Computor(char * str) {
    inputString = str;
}

Computor::~Computor() {}

void Computor::split() {
    int i = 0;
    int j = 0;
    char * substring;

    while (inputString[i] != '\0')
    {
        while(inputString[i] != '+' or inputString[i] != '-' or inputString[i] != '=')
        {
            substring[j++] = inputString[i++];
        }
        std::cout<<substring;
        j = 0;
        i++;
    }

}