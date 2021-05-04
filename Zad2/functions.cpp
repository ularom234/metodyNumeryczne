#include <cmath>
#include <vector>
#include <iostream>
#include <mgl2/mgl.h>

std::vector<double> LinearSpacedArray(double a, double b, std::size_t N)
{
    double h = (b - a) / static_cast<double>(N-1);
    std::vector<double> xs(N);
    std::vector<double>::iterator x;
    double val;
    for (x = xs.begin(), val = a; x != xs.end(); ++x, val += h) {
        *x = val;
    }
    return xs;
}

void plot1D(const std::vector<double>& x, const std::vector<double>& y,
            double referenceValue,
            const std::string& plotName,
            const std::string& xTitle,
            const std::string& yTitle){
    
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



double getIntegralBoole(const std::vector<double>& x, const std::vector<double>& y)
{
    double integral = 0;
    int n = x.size();
    int nDivision = n - 1;
    double h = x[1] - x[0];
    for(int i = 0; i < nDivision; i += 4)
    {
        integral += (7 * y[i] + 32 * y[i+1] + 12* y[i+2] + 32 * y[i+3] + 7* y[i+4]) / 45.0 * 2. * h;
        
    }
    return integral;
}


double getIntegralError(std::vector<double>& x, std::vector<double>& y, double trueValue)
{
	return std::abs(getIntegralBoole(x, y) - trueValue);
}

