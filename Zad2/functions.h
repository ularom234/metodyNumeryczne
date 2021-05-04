#include <vector>
#include <iostream>
void plot1D(const std::vector<double>& x, const std::vector<double>& y,double referenceValue,const std::string& plotName,const std::string& xTitle,const std::string& yTitle);



std::vector<double> LinearSpacedArray(double a, double b, std::size_t N);
double getIntegralBoole(const std::vector<double>& x, const std::vector<double>& y);

double getIntegralError(std::vector<double>& x, std::vector<double>& y, double trueValue);
