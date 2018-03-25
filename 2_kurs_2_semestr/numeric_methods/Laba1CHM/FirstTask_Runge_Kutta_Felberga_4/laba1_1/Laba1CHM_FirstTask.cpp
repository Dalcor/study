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
double k0, k1, k2, k3, k4;
double h1 = (1-eps)/5, h2 = h1/5, h3 = h1/25;
double znachennia_y[127];
znachennia_y[0] = (eps * eps - 1)/2;
double znachennia_fx[127];
double masE[127];
double mas100E[127];
double i;
  int j = 0;
  int k = 1;

  cout << "-------------------------------------------------------------------------------\n";
  cout << "|    x   |      y(xk)      |       yk        |        e        |      e%      |\n";
  cout << "-------------------------------------------------------------------------------\n";

for(i = x_k; i <= 1 + eps; i += h1) {

   k0 = h1 * ((y_k + (sqrt(x_k * x_k + y_k * y_k)))/x_k);
   k1 = h1 * (((y_k + ((2*k0)/9)) + sqrt((x_k + (2*h1)/9) * (x_k + (2*h1)/9) + (y_k + (2*k0)/9) * (y_k + (2*k0)/9)))/(x_k + (2*h1)/9)); // xk = (xk + (2*h1)/9) yk = (yk + (2*k0)/9)
   k2 = h1 * (((y_k + k0/12 + k1/4) + sqrt((x_k + h1/3) * (x_k + h1/3) + (y_k + k0/12 + k1/4) * (y_k + k0/12 + k1/4)))/(x_k + h1/3));// xk = (xk + h1/3) yk = (yk + (1*k0)/12 + k1/4)
   k3 = h1 * (((y_k + (69*k0)/128 - (243*k1)/128 + (135*k2)/64) + sqrt((x_k + (3*h1)/4) * (x_k + (3*h1)/4) + (y_k + (69*k0)/128 - (243*k1)/128 + (135*k2)/64) * (y_k + (69*k0)/128 - (243*k1)/128 + (135*k2)/64)))/(x_k + (3*h1)/4));// xk = (xk + (3*h1)/4) yk = (yk + (69*k0)/128 - (243*k1)/128 + (135*k2)/64)
   k4 = h1 * (((y_k - (17*k0)/12 + (27*k1)/4 - (27*k2)/5 + (16*k3)/15) + sqrt((x_k + h1) * (x_k + h1) + (y_k - (17*k0)/12 + (27*k1)/4 - (27*k2)/5 + (16*k3)/15) * (y_k - (17*k0)/12 + (27*k1)/4 - (27*k2)/5 + (16*k3)/15)))/(x_k + h1)); // xk = (xk + h1 + 0.000001) yk = (yk - (17*k0)/12 + (27*k1)/4 - (27*k2)/5 + (16*k3)/15);
   y = y_k + k0/9 + (k2*9)/20 + (16*k3)/45 + k4/12;
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
   x_k += h1;
}
cout << "-------------------------------------------------------------------------------\n\n\n\n\n";

  j = 0;
  k = 1;
  x_k = eps;
  y_k = (eps * eps - 1)/2;
  znachennia_y[0] = (eps * eps - 1)/2;

  cout << "--------------------------------------------------------------------------------\n";
  cout << "|    x   |      y(xk)      |       yk        |        e        |       e%      |\n";
  cout << "--------------------------------------------------------------------------------\n";

for(i = x_k; i <= 1 + eps; i += h2) {

   k0 = h2 * ((y_k + (sqrt(x_k * x_k + y_k * y_k)))/x_k);
   k1 = h2 * (((y_k + ((2*k0)/9)) + sqrt((x_k + (2*h2)/9) * (x_k + (2*h2)/9) + (y_k + (2*k0)/9) * (y_k + (2*k0)/9)))/(x_k + (2*h2)/9)); // xk = (xk + (2*h2)/9) yk = (yk + (2*k0)/9)
   k2 = h2 * (((y_k + k0/12 + k1/4) + sqrt((x_k + h2/3) * (x_k + h2/3) + (y_k + k0/12 + k1/4) * (y_k + k0/12 + k1/4)))/(x_k + h2/3));// xk = (xk + h2/3) yk = (yk + (1*k0)/12 + k1/4)
   k3 = h2 * (((y_k + (69*k0)/128 - (243*k1)/128 + (135*k2)/64) + sqrt((x_k + (3*h2)/4) * (x_k + (3*h2)/4) + (y_k + (69*k0)/128 - (243*k1)/128 + (135*k2)/64) * (y_k + (69*k0)/128 - (243*k1)/128 + (135*k2)/64)))/(x_k + (3*h2)/4));// xk = (xk + (3*h2)/4) yk = (yk + (69*k0)/128 - (243*k1)/128 + (135*k2)/64)
   k4 = h2 * (((y_k - (17*k0)/12 + (27*k1)/4 - (27*k2)/5 + (16*k3)/15) + sqrt((x_k + h2) * (x_k + h2) + (y_k - (17*k0)/12 + (27*k1)/4 - (27*k2)/5 + (16*k3)/15) * (y_k - (17*k0)/12 + (27*k1)/4 - (27*k2)/5 + (16*k3)/15)))/(x_k + h2)); // xk = (xk + h2 + 0.000001) yk = (yk - (17*k0)/12 + (27*k1)/4 - (27*k2)/5 + (16*k3)/15);
   y = y_k + k0/9 + (k2*9)/20 + (16*k3)/45 + k4/12;
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
  
   cout <<" |" << setw(14) << setprecision(10) << mas100E[j] << "%" << "|\n";

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
  znachennia_y[0] = (eps * eps - 1)/2;

  cout << "-----------------------------------------------------------------------------------\n";
  cout << "|    x   |       y(xk)      |        yk        |        e        |        e%      |\n";
  cout << "-----------------------------------------------------------------------------------\n";

for(i = x_k; i <= 1 + eps; i += h3) {

   k0 = h3 * ((y_k + (sqrt(x_k * x_k + y_k * y_k)))/x_k);
   k1 = h3 * (((y_k + ((2*k0)/9)) + sqrt((x_k + (2*h3)/9) * (x_k + (2*h3)/9) + (y_k + (2*k0)/9) * (y_k + (2*k0)/9)))/(x_k + (2*h3)/9)); // xk = (xk + (2*h3)/9) yk = (yk + (2*k0)/9)
   k2 = h3 * (((y_k + k0/12 + k1/4) + sqrt((x_k + h3/3) * (x_k + h3/3) + (y_k + k0/12 + k1/4) * (y_k + k0/12 + k1/4)))/(x_k + h3/3));// xk = (xk + h3/3) yk = (yk + (1*k0)/12 + k1/4)
   k3 = h3 * (((y_k + (69*k0)/128 - (243*k1)/128 + (135*k2)/64) + sqrt((x_k + (3*h3)/4) * (x_k + (3*h3)/4) + (y_k + (69*k0)/128 - (243*k1)/128 + (135*k2)/64) * (y_k + (69*k0)/128 - (243*k1)/128 + (135*k2)/64)))/(x_k + (3*h3)/4));// xk = (xk + (3*h3)/4) yk = (yk + (69*k0)/128 - (243*k1)/128 + (135*k2)/64)
   k4 = h3 * (((y_k - (17*k0)/12 + (27*k1)/4 - (27*k2)/5 + (16*k3)/15) + sqrt((x_k + h3) * (x_k + h3) + (y_k - (17*k0)/12 + (27*k1)/4 - (27*k2)/5 + (16*k3)/15) * (y_k - (17*k0)/12 + (27*k1)/4 - (27*k2)/5 + (16*k3)/15)))/(x_k + h3)); // xk = (xk + h3 + 0.000001) yk = (yk - (17*k0)/12 + (27*k1)/4 - (27*k2)/5 + (16*k3)/15);
   y = y_k + k0/9 + (k2*9)/20 + (16*k3)/45 + k4/12;
   znachennia_y[k] = y;
   znachennia_fx[j] = (x_k*x_k - 1)/2;
   masE[j] = abs(znachennia_fx[j] - znachennia_y[j]);
   mas100E[j] = abs(100 * masE[j]/znachennia_y[j]);

   cout << fixed;
   cout.precision(5);
   cout.setf(ios :: showpos);
   cout <<"|" << x_k;
   cout.precision(14);
   cout <<"|" << znachennia_fx[j] << " ";
   cout <<"|" << znachennia_y[j] << " ";
   cout.unsetf(ios :: showpos);
   cout <<"|" << masE[j] << " "; 
  
   cout <<"|" << setw(15) << setprecision(11) << mas100E[j] << "%" << "|\n";

   y_k = y;
   j++;
   k++;
   x_k += h3;
}

cout << "-----------------------------------------------------------------------------------\n\n\n\n\n";

system("pause");
return 0;
}
