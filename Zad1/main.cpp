// Urszula Romaniuk 347442

#include <iostream>
#include <cmath>
#include <limits>
#include <complex>

#include "functions.h"

#include <vector>
#include <mgl2/mgl.h>

double fun1(double xi)
{
    return std::sin(xi);
}

double fun2(double xi)
{
    return std::cos(xi);
}

double fun3(double xi)
{
    return std::sin(xi) + std::sin(4 * xi);
}

double fun4(double xi)
{
    return std::exp(- (xi * xi));
}


int main()
{
    double k_range = 10;
    double dk = 0.1;

    
    std::vector<double> x, y;
    createXY(fun1, x, y);
    std::cout << "Wartosc fouriera: " << getFourier(x, y, 1) << std::endl;

    std::vector<double> x_rys, y_re, y_im;
    std::complex<double> temp;
    for(double k = -k_range; k < k_range; k += dk)
    {
        // k = 2*pi*f
        x_rys.push_back(k);
        temp = getFourier(x, y, k);
        y_re.push_back(temp.real());
        y_im.push_back(temp.imag());
    }
    
    
    std::string plotName_fun = "fun.png";
    std::string xTitle = "x";
    std::string yTitle = "y";
    double reference_value = 0;
    plot1D(x, y, reference_value, plotName_fun, xTitle, yTitle);

    std::string plotName_re = "Re.png";
    plot1D(x_rys, y_re, reference_value, plotName_re, xTitle, yTitle);

    std::string plotName_im = "Im.png";
    plot1D(x_rys, y_im, reference_value, plotName_im, xTitle, yTitle);

    
    return 0;
}

