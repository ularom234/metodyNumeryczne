// Urszula Romaniuk 347442

#include <cmath>
#include <vector>
#include <iostream>
#include <mgl2/mgl.h>
#include <complex>

double getIntegralSimpson(const std::vector<double>& xv, const std::vector<double>& yv)
{
	int n = xv.size();
	int nDivision = n - 1;
	double integral = 0;
	double h = xv[1] - xv[0];
	for (int i = 0; i < nDivision; i += 2)
	{
		integral += (yv[i] + 4 * yv[i+1] + yv[i+2])/3. * h;
	}
	return integral;
}


std::vector<double> under_integral(const std::vector <double>& xv, const std::vector <double>& yv, const double& k, double (*f)(double))
{
    std::vector<double> result;
    for(int i = 0; i != xv.size(); i++)
	{
		result.push_back(yv[i] * f(k * xv[i]));
    }
	return result;
}

std::complex<double> getFourier(const std::vector <double>& xv, const std::vector <double>& yv, const double& k)
{
    double norm = 1 / std::sqrt(2 * M_PI);
    double re, im;
    re = norm * getIntegralSimpson(xv, under_integral(xv, yv, k, std::cos));
    im = norm * getIntegralSimpson(xv, under_integral(xv, yv, k, std::sin));
    std::complex<double> fourier(re, im);
    return fourier;
}

void plot1D(const std::vector<double>& x, const std::vector<double>& y, double referenceValue, const std::string& plotName, const std::string& xTitle,const std::string& yTitle)
{    
    mglGraph gr;
    mglData data_x, data_y, data_ref;
    
    data_x.Set(x);
    data_y.Set(y);
    data_ref.Set(y);
    
    data_ref.Put(referenceValue);
    
    gr.SetRanges(data_x.Minimal(),
                 data_x.Maximal(),
                 data_y.Minimal(),
                 data_y.Maximal());
    
    gr.Plot(data_x, data_y);
    gr.Plot(data_x, data_ref,"r;");
    gr.Axis();
    gr.Title(plotName.c_str());
    gr.Label('x', xTitle.c_str(),1);
    gr.Label('y', yTitle.c_str(),0);
    gr.WriteFrame(plotName.c_str());
}

std::vector<double> LinearSpacedArray(double a, double b, std::size_t N)
{
    double h = (b - a) / static_cast<double>(N-1);
    std::vector<double> xs(N);
    std::vector<double>::iterator x;
    double val;
    for (x = xs.begin(), val = a; x != xs.end(); ++x, val += h) {
        if (std::abs(val) < 1e-10)
        {
            val = 0;
        }
        *x = val;
    }
    return xs;
}

void createXY(double (*f)(double), std::vector<double>& xv, std::vector<double>& yv, double xMax = 10, double dx = 0.1)
{
    xv = LinearSpacedArray(-xMax, xMax, xMax *2 / dx);
    for(int i = 0; i != xv.size(); i++)
    {
        yv.push_back(f(xv[i]));
    }
}

