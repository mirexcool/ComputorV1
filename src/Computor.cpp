//
// Created by Mirex on 06.09.2018.
//"5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0

#include "Computor.hpp"
#include <stdio.h>
#include <string.h>

double SquareRoot(double _val) {
    double low = 0;
    double high = _val;
    double mid = 0;

    while (high - low > 0.0000001) {
        mid = low + (high - low) / 2;
        if (mid  *mid > _val) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return mid;
}

Computor::Computor() {}

Computor::Computor(char * str) {
    inputString = str;
    memset(this->powers, 0, sizeof(double)* MAX_DEGREE);
}

Computor::~Computor() {}

void Computor::split() {
    int i = 0;
    int j = 0;
    int signPlus = 1;
    char * substring;

    substring = (char *)std::malloc(sizeof(char) * MAX_DEGREE);
    memset(substring, '\0', sizeof(char)*MAX_DEGREE);

    while (inputString[i])
    {
        if (inputString[i] == '=')
        {
            signPlus = -1;
            i++;
            substring[j++] = inputString[i++];
        }
        substring[j++] = inputString[i++];
        if (inputString[i] == '+' or inputString[i] == '-' or inputString[i] == '=' )
        {
            getNumbers(substring, signPlus);
            j = 0;
            memset(substring, '\0', sizeof(char)*MAX_DEGREE);
        }
    }
    getNumbers(substring, signPlus);
}

void Computor::getNumbers(char *substring, int inverse) {
    int i = 0;
    int signPlus = 1;
    double number = 0;
    int power = 0;
    int noNumber = 0;

    while (substring[i] < '0' or substring[i] > '9' )
    {
        if (substring[i] == '-')
            signPlus = -1;
        if (substring[i] == 'X')
        {
            noNumber = 1;
            break;
        }
        i++;
    }
    if (!noNumber)
        number = std::atof(substring+i) * signPlus * inverse;
    else
        number = 1 * inverse;
    while (substring[i] != '^' && substring[i] != '\0')
        i++;
    if (i == strlen(substring) and strchr(substring, 'X'))
        power = 1;
    else if (strchr(substring, '^'))
        power = std::atoi(substring + i+1);
    if (_PolynomalDegree < power)
        _PolynomalDegree = power;
    this->powers[power]+=number;
}

void Computor::showEval() {
    _PolynomalDegree = getDegree();

    if (_PolynomalDegree != 0 and powers[_PolynomalDegree] != 0)
    {
        std::cout << "Reduced form: ";
        for (int i = 0; i < MAX_DEGREE ; ++i) {
            if (this->powers[i] != 0)
            {
                if (i == 0)
                {
                    if ( this->powers[i] < 0)
                        std::cout << "- " << this->powers[i] *(-1) << " ";
                    else
                        std::cout << this->powers[i]  << " ";
                }
                else
                {
                    if (i > 1)
                    {
                        if (this->powers[i] < 0)
                            std::cout << "- " << this->powers[i] * (-1) << " * X^" << i << " ";
                        else
                            std::cout << "+ " << this->powers[i] << " * X^" << i << " ";
                    }
                    else
                    {
                        if (this->powers[i] < 0)
                            std::cout << "- " << this->powers[i] * (-1) << " * X" << " ";
                        else
                            std::cout << "+ " << this->powers[i] << " * X" << " ";
                    }
                }
            }
        }
        std::cout << " = 0" <<std::endl;
    }

}

void Computor::solveEval() {
    double D = 0;
    double x1 = 0;
    double x2 = 0;

    std::cout<< "Polynomial degree = " <<_PolynomalDegree <<std::endl;
    if (_PolynomalDegree < 3) {
        if (_PolynomalDegree == 2 and powers[2] != 0)
        {
            D = this->powers[1] * this->powers[1] - 4 * this->powers[2] * this->powers[0];

            std::cout << "Desceminant = " << D << std::endl;

            if (D > 0) {
                x1 = ((-1) * this->powers[1] + SquareRoot(D)) / (2 * this->powers[2]);
                x2 = ((-1) * this->powers[1] - SquareRoot(D)) / (2 * this->powers[2]);
                std::cout << "Roots: " << x1 << ", " << x2 << std::endl;
            } else if (D == 0) {
                x1 = ((-1) * this->powers[1] -
                        SquareRoot(D)) /
                     (2 * this->powers[2]);
//                x2 = x1;
                std::cout << "Roots: " << x1 << std::endl;
            } else
            {
                std::cout << "Roots is not real numbers!  " << std::endl;
                x1 = ((-1) * this->powers[1] + SquareRoot(-D)) /  (2 * this->powers[2]);
                x2 = ((-1) * this->powers[1] - SquareRoot(-D)) / (2 * this->powers[2]);
                std::cout << "Roots: " << x1 << "i, " << x2 <<"i" << std::endl;
            }
        }
        else if (_PolynomalDegree == 1 and powers[1] != 0)
            std::cout << "Root: " << this->powers[0]/this->powers[1] * -1 << std::endl;
        else
            if (this->powers[0] == 0 and _PolynomalDegree > 0)
                std::cout << "All the real numbers are solution." << std::endl;
            else
                std::cout<< "I can't solve it! Sory... =( " <<std::endl;
    }
    else
        std::cout<< "I can't solve it! Sory... =( " <<std::endl;

}

void trimSpace(char s[])
{
    int i = 0;
    int count = 0;

    while(s[i])
    {
        if( s[i]!= ' ' )
            s[count++] = s[i++];
        else
            while(s[i] == ' ')
                i++;
    }

    s[count]='\0';
}

bool Computor::checkInput() {
    int i = 0;
    bool ret = true;
    int countPow = 0;
    trimSpace(inputString);
    int len = strlen(inputString);
    int equal = 0;
    int dot = 0;

    while(( inputString[i] >= '0' and inputString[i] <= '9') or inputString[i] == '^'
            or inputString[i] == '+' or inputString[i] == '-' or inputString[i] == '*'
            or inputString[i] == '=' or inputString[i] == 'X' or inputString[i] == '.'
            or inputString[i] == ' ')
    {
        if (inputString[i] == '=')
            equal++;
        if (countPow != 0 and countPow != 1)
            ret = false;
        if (inputString[i] =='X')
        {
            dot--;
            countPow++;
            if ( inputString[i + 1] != '^'  or (inputString[i + 2] < 0 or inputString[i + 2] > '9') )
                ret = false;
            if ( inputString[i + 1] == '+' or  inputString[i + 1] == '-' or  inputString[i + 1] == '=' or  inputString[i + 1] == '\0')
            {
                ret = true;
                countPow--;
            }

        }
        if (inputString[i] =='^')
        {
            dot--;
            countPow--;
        }
        if (inputString[i] == '.')
        {

            if (inputString[i - 1] < '0' or inputString[i - 1] > '9' or inputString[i + 1] < '0' or inputString[i + 1] > '9' or dot == 0)
                ret = false;
            dot = 0;
        }
        if (inputString[i] == '=')
        {
            dot--;
            if ((inputString[i - 1] < '0' or inputString[i - 1] > '9' and inputString[i - 1] != 'X' and inputString[i - 1] != '0' and inputString[i - 1] != '-')
                or (inputString[i + 1] < '0' or inputString[i + 1] > '9' and inputString[i + 1] != 'X') and inputString[i + 1] != '0' and inputString[i + 1] != '-' )
                ret = false;
        }
        if (inputString[i] == '+')
        {
            dot--;
            if ((inputString[i - 1] < '0' or inputString[i - 1] > '9' and inputString[i - 1] != 'X')
                or (inputString[i + 1] < '0' or inputString[i + 1] > '9' and inputString[i + 1] != 'X') )
                ret = false;
        }
        if (inputString[i] == '-')
        {
            dot--;
            if ((inputString[i - 1] < '0' or inputString[i - 1] > '9' and inputString[i - 1] != 'X' and inputString[i - 1] != '=')
                or (inputString[i + 1] < '0' or inputString[i + 1] > '9' and inputString[i + 1] != 'X') )
                ret = false;
        }
        i++;
    }
    if (len > i or equal == 0)
        ret = false;
    return ret;
}

int Computor::getDegree() {

    for (int i = MAX_DEGREE - 1; i >0; i--) {
        if (this->powers[i] != 0)
            return i;
    }
    return _PolynomalDegree;
}
