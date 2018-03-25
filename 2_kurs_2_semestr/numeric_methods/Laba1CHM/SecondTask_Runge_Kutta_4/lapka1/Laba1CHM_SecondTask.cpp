#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
system("chcp 1251 & cls"); 
double x;
double y;
double eps = 0.000001;
double x_k = eps;
double y_k = (eps * eps - 1)/2;

double h1 = (1-eps)/5, h2 = h1/5, h3 = h1/25;
double znachennia_y[127];
znachennia_y[0] = -0.5;
double znachennia_fx[127];
double masE[127];
double mas100E[127];
double i;
  int j = 0;
  int k = 1;
double k1[127];
double k2[127];
double k3[127];
double k4[127];

  cout << "------------------------------------------------------------------------------\n";
  cout << "|   x    |       y(xk)     |        yk       |       e        |      e%      |\n";
  cout << "------------------------------------------------------------------------------\n";

for(i = x_k; i <= 1 + eps; i += h1) {

   k1[j] = h1 * ((y_k + (sqrt(x_k * x_k + y_k * y_k)))/x_k);
   k2[j] = h1 * (((y_k + k1[j]/2) + (sqrt((x_k + h1/2) * (x_k + h1/2) + (y_k + k1[j]/2) * (y_k + k1[j]/2))))/(x_k + h1/2)); // x_k = (x_k + h1/2) y_k = (yk + k1[j]/2)
   k3[j] = h1 * (((y_k + k2[j]/2) + (sqrt((x_k + h1/2) * (x_k + h1/2) + (y_k + k2[j]/2) * (y_k + k2[j]/2))))/(x_k + h1/2));// x_k = (x_k + h1/3) yk = (yk + (1*k0)/12 + k1[j]/4)
   k4[j] = h1 * (((y_k + k3[j]) + (sqrt((x_k + h1) * (x_k + h1) + (y_k + k3[j]) * (y_k + k3[j]))))/(x_k + h1));// x_k = (x_k + h1) y_k = (y_k + k3[j])
   
   y = y_k + (k1[j] + 2*k2[j] + 2*k3[j] + k4[j])/6;
   znachennia_y[k] = y;
   znachennia_fx[j] = (x_k*x_k - 1)/2;
   masE[j] = abs(znachennia_fx[j] - znachennia_y[j]);
   mas100E[j] = abs(100 * masE[j]/znachennia_y[j]);

   cout << fixed;
   cout.precision(5);
   cout.setf(ios :: showpos);
   cout <<"|" << x_k;
   cout.precision(13);
   cout <<"|" << znachennia_fx[j] << " ";
   cout <<"|" << znachennia_y[j] << " ";
   cout.unsetf(ios :: showpos);
   cout <<"|" << masE[j] << " "; 
  
   cout <<"|" << setw(13) << setprecision(10) << mas100E[j] << "%" << "|\n";

   y_k = y;
   j++;
   k++;
   x_k += h1;
}
  cout << "------------------------------------------------------------------------------\n\n\n\n\n";

  j = 0;
  k = 1;
  x_k = eps;
  y_k = (eps * eps - 1)/2;
  znachennia_y[0] = -0.5;

  cout << "-------------------------------------------------------------------------------\n";
  cout << "|   x    |       y(xk)     |        yk       |       e         |      e%      |\n";
  cout << "-------------------------------------------------------------------------------\n";

for(i = x_k; i <= 1 + eps; i += h2) {

   k1[j] = h2 * ((y_k + (sqrt(x_k * x_k + y_k * y_k)))/x_k);
   k2[j] = h2 * (((y_k + k1[j]/2) + (sqrt((x_k + h2/2) * (x_k + h2/2) + (y_k + k1[j]/2) * (y_k + k1[j]/2))))/(x_k + h2/2)); // x_k = (x_k + h1/2) y_k = (yk + k1[j]/2)
   k3[j] = h2 * (((y_k + k2[j]/2) + (sqrt((x_k + h2/2) * (x_k + h2/2) + (y_k + k2[j]/2) * (y_k + k2[j]/2))))/(x_k + h2/2));// x_k = (x_k + h1/3) yk = (yk + (1*k0)/12 + k1[j]/4)
   k4[j] = h2 * (((y_k + k3[j]) + (sqrt((x_k + h2) * (x_k + h2) + (y_k + k3[j]) * (y_k + k3[j]))))/(x_k + h2));// x_k = (x_k + h1) y_k = (y_k + k3[j])
   
   y = y_k + (k1[j] + 2*k2[j] + 2*k3[j] + k4[j])/6;
   znachennia_y[k] = y;
   znachennia_fx[j] = (x_k*x_k - 1)/2;
   masE[j] = abs(znachennia_fx[j] - znachennia_y[j]);
   mas100E[j] = abs(100 * masE[j]/znachennia_y[j]);

   cout << fixed;
   cout.precision(5);
   cout.setf(ios :: showpos);
   cout <<"|" << x_k;
   cout.precision(13);
   cout <<"|" << znachennia_fx[j] << " ";
   cout <<"|" << znachennia_y[j] << " ";
   cout.unsetf(ios :: showpos);
   cout <<"|" << masE[j] << " "; 
  
   cout <<" |" << setw(13) << setprecision(10) << mas100E[j] << "%" << "|\n";

   y_k = y;
   j++;
   k++;
   x_k += h2;
}

cout << "-------------------------------------------------------------------------------\n\n\n\n\n";


  j = 0;
  k = 1;
  x_k = eps;
  y_k = (eps * eps - 1)/2;
  znachennia_y[0] = -0.5;

  cout << "-------------------------------------------------------------------------------\n";
  cout << "|   x    |       y(xk)     |        yk       |       e         |      e%      |\n";
  cout << "-------------------------------------------------------------------------------\n";

for(i = x_k; i <= 1 + eps; i += h3) {

   k1[j] = h3 * ((y_k + (sqrt(x_k * x_k + y_k * y_k)))/x_k);
   k2[j] = h3 * (((y_k + k1[j]/2) + (sqrt((x_k + h3/2) * (x_k + h3/2) + (y_k + k1[j]/2) * (y_k + k1[j]/2))))/(x_k + h3/2)); // x_k = (x_k + h1/2) y_k = (yk + k1[j]/2)
   k3[j] = h3 * (((y_k + k2[j]/2) + (sqrt((x_k + h3/2) * (x_k + h3/2) + (y_k + k2[j]/2) * (y_k + k2[j]/2))))/(x_k + h3/2));// x_k = (x_k + h1/3) yk = (yk + (1*k0)/12 + k1[j]/4)
   k4[j] = h3 * (((y_k + k3[j]) + (sqrt((x_k + h3) * (x_k + h3) + (y_k + k3[j]) * (y_k + k3[j]))))/(x_k + h3));// x_k = (x_k + h1) y_k = (y_k + k3[j])
   
   y = y_k + (k1[j] + 2*k2[j] + 2*k3[j] + k4[j])/6;
   znachennia_y[k] = y;
   znachennia_fx[j] = (x_k*x_k - 1)/2;
   masE[j] = abs(znachennia_fx[j] - znachennia_y[j]);
   mas100E[j] = abs(100 * masE[j]/znachennia_y[j]);

   cout << fixed;
   cout.precision(5);
   cout.setf(ios :: showpos);
   cout <<"|" << x_k;
   cout.precision(13);
   cout <<"|" << znachennia_fx[j] << " ";
   cout <<"|" << znachennia_y[j] << " ";
   cout.unsetf(ios :: showpos);
   cout <<"|" << masE[j] << " "; 
  
   cout <<" |" << setw(13) << setprecision(10) << mas100E[j] << "%" << "|\n";

   y_k = y;
   j++;
   k++;
   x_k += h3;
}

cout << "-------------------------------------------------------------------------------\n\n\n\n\n";

system("pause");
return 0;
}
