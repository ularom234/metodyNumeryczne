#include <iostream>
#include <cmath>
#include <limits>

#include "functions.h"

#include <vector>
#include <mgl2/mgl.h>


int main()
{
    int N = 100;
    std::vector<double> x = LinearSpacedArray(0, M_PI , N);
    std::vector<double> y;
    std::vector<double> x_rys, err, err2, y_rys;

    for(int i = 0; i != x.size(); i++)
    {
		y.push_back(std::sin(x[i]));
    }
    
    std::cout << getIntegralBoole(x, y) << std::endl;
    
    /*
    for(int i = 0; i < M_PI; i += M_PI/N)
    {
		std::vector<double> xx = LinearSpacedArray(i, M_PI , N);
		std::vector<double> yy;
		for(int j = 0; j != x.size(); j++)
		{
			yy.push_back(std::sin(xx[j]));
		}
		x_rys.push_back(i);
        y_rys.push_back(getIntegralBoole(xx, yy));
    }
    */
 
    for(int i = 1; i <= N; i += 4)
    {
		std::vector<double> xx = LinearSpacedArray(0, M_PI , i);
		std::vector<double> yy;
		for(int j = 0; j != x.size(); j++)
		{
			yy.push_back(std::sin(xx[j]));
		}
		x_rys.push_back(i);
        err.push_back(getIntegralError(xx, yy, 2.) * std::pow(i,5));
    }
    
    std::string plotName1 = "blad.png";
    std::string plotName2 = "calka.png";
    std::string xTitle = "x";
    std::string yTitle = "y";
    double reference_value = 0;
    plot1D(x_rys, err, reference_value, plotName1, xTitle, yTitle);
    plot1D(x_rys, y_rys, reference_value, plotName2, xTitle, yTitle);
 


    
    return 0;

}

