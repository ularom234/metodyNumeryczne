#include <cmath>
#include <mgl2/mgl.h>
#include <iostream>

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
long int factorial(int n){

  long int value = 1;
  
  while(n){
    value*=n;
    --n;
  }
  return value;
}
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
void plot1D(double x[], double y[], int len, double y_inf)
{
    mglGraph gr;
    
    mglData x_mgl;
    x_mgl.Set(x, len);
    
    mglData y_mgl;
    y_mgl.Set(y, len);
    
    mglData y_inf_mgl(len);
    for(int i = 0; i < len; i++)
    {
        y_inf_mgl.a[i] = y_inf;
    }
    
    gr.SetRanges(x_mgl, y_mgl);
    gr.Title("Kolejne wartosci szacowania e^x", 0, 5);
    gr.Plot(x_mgl,y_mgl, "B-*4");
    gr.Plot(x_mgl, y_inf_mgl, "R-2");
    gr.Axis();
    gr.Label('x', "n", 0);
    gr.Label('y', "n-te rozwiniecie e^x", 0);
    gr.WriteFrame("exp.png");
    
}
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
long double exp(int n, float x)
{
    long double suma = 1.0;
    long double temp;
    double xx[n/2];
    double yy[n/2];
    
    long double pamiec = 1;
    for(int k = 1; k <= n; k = k + 2)
    {
    //    temp1 = pamiec * x / k;
  //      temp2 = pamiec * x / (k + 1);
        temp = pamiec * (x / k) * ((x + k + 1) / (k + 1));
        pamiec = pamiec * x * x / (k * (k + 1));
//        std::cout << "k: " << k << std::endl;
        suma += temp;
        xx[(k-1)/2] = (k+1);
        yy[(k-1)/2] = temp;
    }
    plot1D(xx, yy, n/2, std::pow(M_E, x));
    return suma;
}
