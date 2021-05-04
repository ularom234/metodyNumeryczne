// Urszula Romaniuk 347442

#include <vector>
#include <complex>

double getIntegralSimpson(const std::vector<double>& xv, const std::vector<double>& yv);

std::vector<double> under_integral(const std::vector <double>& xv, const std::vector <double>& yv, const double& k, double (*f)(double));

std::complex<double> getFourier(const std::vector <double>& xv, const std::vector <double>& yv, const double& k);

void plot1D(const std::vector<double>& x, const std::vector<double>& y, double referenceValue, const std::string& plotName, const std::string& xTitle,const std::string& yTitle);

std::vector<double> LinearSpacedArray(double a, double b, std::size_t N);

void createXY(double (*f)(double), std::vector<double>& xv, std::vector<double>& yv, double xMax = 10, double dx = 0.1);

