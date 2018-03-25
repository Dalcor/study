#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
system("chcp 1251 & cls"); 
double y;

double eps = 0.000001;
double x_k = eps;
double y_k = (eps * eps - 1)/2;

double k0, k1, k2, k3, k4;

double h1 = (1-eps)/5, h2 = h1/5, h3 = h1/25;

double znachennia_y[127];
double masf[127];



znachennia_y[0] = (eps * eps - 1)/2;


double znachennia_fx[127];
double masE[127];
double mas100E[127];


 
  int j = 0;
  int k = 1;

  cout << "-------------------------------------------------------------------------------\n";
  cout << "|    x   |      y(xk)      |       yk        |        e        |      e%      |\n";
  cout << "-------------------------------------------------------------------------------\n";
  for (int l = 0; l <= 1; l++) {
   k0 = h1 * ((y_k + (sqrt(x_k * x_k + y_k * y_k)))/x_k);
   k1 = h1 * (((y_k + ((2*k0)/9)) + sqrt((x_k + (2*h1)/9) * (x_k + (2*h1)/9) + (y_k + (2*k0)/9) * (y_k + (2*k0)/9)))/(x_k + (2*h1)/9)); 
   k2 = h1 * (((y_k + k0/12 + k1/4) + sqrt((x_k + h1/3) * (x_k + h1/3) + (y_k + k0/12 + k1/4) * (y_k + k0/12 + k1/4)))/(x_k + h1/3));
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
   j = 0;
  //masy[0] = znachennia_y[j]; // y(k-2)
  //masy[1] = znachennia_y[j+1]; //y(k-1)
  //masy[2] = znachennia_y[j+2]; //y(k)
  masf[0] = ((znachennia_y[j+2] + (sqrt(x_k * x_k + znachennia_y[j+2] * znachennia_y[j+2])))/x_k);  
  masf[1] = ((znachennia_y[j+1] + (sqrt(x_k * x_k + znachennia_y[j+1] * znachennia_y[j+1])))/x_k);
  masf[2] = ((znachennia_y[j] + (sqrt(x_k * x_k + znachennia_y[j] * znachennia_y[j])))/x_k);
  masf[3] = (((znachennia_y[j] + masf[2] - masf[1]) + (sqrt(x_k * x_k + (znachennia_y[j] + masf[2] - masf[1]) * (znachennia_y[j] + masf[2] - masf[1]))))/x_k);//y_k = (znachennia_y[j] + mas[2] - mas[1])
 int  d = 2;
for(int i = 3; i <= 6; i++) {


   y = znachennia_y[i - 1] + h1/24 * (19*masf[2] - 5 * masf[1] + masf[0] + 9*masf[3]);
   znachennia_y[i] = y;
   znachennia_fx[d] = (x_k*x_k - 1)/2;
 
   masE[d] = abs(znachennia_fx[d] - znachennia_y[d]);
   mas100E[d] = abs(100 * masE[d]/znachennia_y[d]);

   cout << fixed;
   cout.precision(5);
   cout.setf(ios :: showpos);
   cout <<"|" << x_k;
    cout.precision(13);
    cout <<"|" << znachennia_fx[d] << " ";
    cout <<"|" << znachennia_y[d] << " ";
   cout.unsetf(ios :: showpos);
   cout <<"|" << masE[d] << " "; 
  
   cout <<" |" << setw(13) << setprecision(10) << mas100E[d] << "%" << "|\n";

   j++;
   d++;
   masf[0] = masf[1];
   masf[1] = masf[2];
   masf[2] = ((znachennia_y[i] + (sqrt(x_k * x_k + znachennia_y[i] * znachennia_y[i])))/x_k);
   masf[3] = (((znachennia_y[j] + masf[2] - masf[1]) + (sqrt(x_k * x_k + (znachennia_y[j] + masf[2] - masf[1]) * (znachennia_y[j] + masf[2] - masf[1]))))/x_k);
   x_k += h1;
}
//**************************************************************************************************************
  j = 0;
  k = 1;
  x_k = eps;
  y_k = (eps * eps - 1)/2;
  znachennia_y[0] = (eps * eps - 1)/2;

  cout << "--------------------------------------------------------------------------------\n";
  cout << "|    x   |      y(xk)      |       yk        |        e        |       e%      |\n";
  cout << "--------------------------------------------------------------------------------\n";

  for (int l = 0; l <= 1; l++) {
   k0 = h2 * ((y_k + (sqrt(x_k * x_k + y_k * y_k)))/x_k);
   k1 = h2 * (((y_k + ((2*k0)/9)) + sqrt((x_k + (2*h2)/9) * (x_k + (2*h2)/9) + (y_k + (2*k0)/9) * (y_k + (2*k0)/9)))/(x_k + (2*h2)/9)); 
   k2 = h2 * (((y_k + k0/12 + k1/4) + sqrt((x_k + h2/3) * (x_k + h2/3) + (y_k + k0/12 + k1/4) * (y_k + k0/12 + k1/4)))/(x_k + h2/3));
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
  
   cout <<" |" << setw(13) << setprecision(10) << mas100E[j] << "%" << "|\n";

   y_k = y;
   j++;
   k++;
   x_k += h2;
  }
   j = 0;
  //masy[0] = znachennia_y[j]; // y(k-2)
  //masy[1] = znachennia_y[j+1]; //y(k-1)
  //masy[2] = znachennia_y[j+2]; //y(k)
  masf[0] = (znachennia_y[j+2] + (sqrt(x_k * x_k + znachennia_y[j+2] * znachennia_y[j+2])))/x_k;  
  masf[1] = (znachennia_y[j+1] + (sqrt(x_k * x_k + znachennia_y[j+1] * znachennia_y[j+1])))/x_k;
  masf[2] = (znachennia_y[j] + (sqrt(x_k * x_k + znachennia_y[j] * znachennia_y[j])))/x_k;
  masf[3] = (((znachennia_y[j] + masf[2] - masf[1]) + (sqrt(x_k * x_k + (znachennia_y[j] + masf[2] - masf[1]) * (znachennia_y[j] + masf[2] - masf[1]))))/x_k);//y_k = (znachennia_y[j] + mas[2] - mas[1])
   d = 2;
for(int i = 3; i <= 26; i++) {


   y = znachennia_y[i - 1] + h2/24 * (19*masf[2] - 5 * masf[1] + masf[0] + 9*masf[3]);
   znachennia_y[i] = y;
   znachennia_fx[d] = (x_k*x_k - 1)/2;
 
   masE[d] = abs(znachennia_fx[d] - znachennia_y[d]);
   mas100E[d] = abs(100 * masE[d]/znachennia_y[d]);

   cout << fixed;
   cout.precision(5);
   cout.setf(ios :: showpos);
   cout <<"|" << x_k;
    cout.precision(13);
    cout <<"|" << znachennia_fx[d] << " ";
    cout <<"|" << znachennia_y[d] << " ";
   cout.unsetf(ios :: showpos);
   cout <<"|" << masE[d] << " "; 
  
   cout <<" |" << setw(13) << setprecision(10) << mas100E[d] << "%" << "|\n";

   j++;
   d++;
   masf[0] = masf[1];
   masf[1] = masf[2];
   masf[2] = ((znachennia_y[i] + (sqrt(x_k * x_k + znachennia_y[i] * znachennia_y[i])))/x_k);
    masf[3] = (((znachennia_y[j] + masf[2] - masf[1]) + (sqrt(x_k * x_k + (znachennia_y[j] + masf[2] - masf[1]) * (znachennia_y[j] + masf[2] - masf[1]))))/x_k);
   x_k += h2;
}
//**********************************************************************************************
  j = 0;
  k = 1;
  x_k = eps;
  y_k = (eps * eps - 1)/2;
  znachennia_y[0] = (eps * eps - 1)/2;

  cout << "--------------------------------------------------------------------------------\n";
  cout << "|    x   |      y(xk)      |       yk        |        e        |       e%      |\n";
  cout << "--------------------------------------------------------------------------------\n";

  for (int l = 0; l <= 1; l++) {
   k0 = h3 * ((y_k + (sqrt(x_k * x_k + y_k * y_k)))/x_k);
   k1 = h3 * (((y_k + ((2*k0)/9)) + sqrt((x_k + (2*h3)/9) * (x_k + (2*h3)/9) + (y_k + (2*k0)/9) * (y_k + (2*k0)/9)))/(x_k + (2*h3)/9)); 
   k2 = h3 * (((y_k + k0/12 + k1/4) + sqrt((x_k + h3/3) * (x_k + h3/3) + (y_k + k0/12 + k1/4) * (y_k + k0/12 + k1/4)))/(x_k + h3/3));
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
   j = 0;
  //masy[0] = znachennia_y[j]; // y(k-2)
  //masy[1] = znachennia_y[j+1]; //y(k-1)
  //masy[2] = znachennia_y[j+2]; //y(k)
  masf[0] = (znachennia_y[j+2] + (sqrt(x_k * x_k + znachennia_y[j+2] * znachennia_y[j+2])))/x_k;  
  masf[1] = (znachennia_y[j+1] + (sqrt(x_k * x_k + znachennia_y[j+1] * znachennia_y[j+1])))/x_k;
  masf[2] = (znachennia_y[j] + (sqrt(x_k * x_k + znachennia_y[j] * znachennia_y[j])))/x_k;
  masf[3] = (((znachennia_y[j] + masf[2] - masf[1]) + (sqrt(x_k * x_k + (znachennia_y[j] + masf[2] - masf[1]) * (znachennia_y[j] + masf[2] - masf[1]))))/x_k);//y_k = (znachennia_y[j] + mas[2] - mas[1])
  d = 2;
for(int i = 3; i <= 126; i++) {


  y = znachennia_y[i - 1] + h3/24 * (19*masf[2] - 5 * masf[1] + masf[0] + 9*masf[3]);
   znachennia_y[i] = y;
   znachennia_fx[d] = (x_k*x_k - 1)/2;
 
   masE[d] = abs(znachennia_fx[d] - znachennia_y[d]);
   mas100E[d] = abs(100 * masE[d]/znachennia_y[d]);

   cout << fixed;
   cout.precision(5);
   cout.setf(ios :: showpos);
   cout <<"|" << x_k;
    cout.precision(13);
    cout <<"|" << znachennia_fx[d] << " ";
    cout <<"|" << znachennia_y[d] << " ";
   cout.unsetf(ios :: showpos);
   cout <<"|" << masE[d] << " "; 
  
   cout <<" |" << setw(13) << setprecision(10) << mas100E[d] << "%" << "|\n";

   j++;
   d++;
   masf[0] = masf[1];
   masf[1] = masf[2];
   masf[2] = ((znachennia_y[i] + (sqrt(x_k * x_k + znachennia_y[i] * znachennia_y[i])))/x_k);
   masf[3] = (((znachennia_y[j] + masf[2] - masf[1]) + (sqrt(x_k * x_k + (znachennia_y[j] + masf[2] - masf[1]) * (znachennia_y[j] + masf[2] - masf[1]))))/x_k);
   x_k += h3;
}

system("pause");
return 0;
}
