#include <iostream>
#include <time.h>
#include <cmath>

#include "functions.h"

/*
g++ -std=gnu++11 -I ${MATHGL_PATH}/include -L ${MATHGL_PATH}/lib -lmgl main.cpp functions.cpp -o main
*/

int main()
{
    std::cout.precision(8);
    
    double x = -20;
    int n = 100;
    
    double temp = exp(n, x);
    std::cout << "Wartosc oszacowana: " << temp << "\nWartosc prawdziwa: " << std::pow(M_E, x) << std::endl;
    std::cout << "Blad: " << (std::pow(M_E, x) - temp) / std::pow(M_E, x) << std::endl;
	return 0;
}
