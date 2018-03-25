#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
system("chcp 1251 & cls"); 
double x;
double y;
double exp = 2.71828182846;
double eps = 0.000001;
double x_k = 0;
double y_k = 1/sqrt(2);
double k0, k1, k2, k3, k4;
double h1 = 0.2, h2 = h1/5, h3 = h1/25;
double znachennia_y[127];
double masf[127];
znachennia_y[0] = 1/sqrt(2);
double znachennia_fx[127];
double masE[127];
double mas100E[127];
double i;
  int j = 0;
  int k = 1;

  cout << "------------------------------------------------------------------------------\n";
  cout << "|   x    |       y(xk)     |        yk       |       e        |      e%      |\n";
  cout << "------------------------------------------------------------------------------\n";
  for (int l = 0; l <= 2; l++) {
   k1 = h1 * (x_k * x_k * x_k * y_k * y_k * y_k - x_k * y_k); // x_k = (x_k + h1/2) y_k = (y_k + k1/2)
   k2 = h1 * ((x_k + h1/2) * (x_k + h1/2) * (x_k + h1/2) * (y_k + k1/2) * (y_k + k1/2) * (y_k + k1/2) - (x_k + h1/2) * (y_k + k1/2));
   k3 = h1 * ((x_k + h1/2) * (x_k + h1/2) * (x_k + h1/2) * (y_k + k2/2) * (y_k + k2/2) * (y_k + k2/2) - (x_k + h1/2) * (y_k + k2/2));// x_k = (x_k + h1/2) yk = (y_k + k2/2)
   k4 = h1 * ((x_k + h1) * (x_k + h1) * (x_k + h1) * (y_k + k3) * (y_k + k3) * (y_k + k3) - (x_k + h1) * (y_k + k3));
// x_k = (x_k + h1) y_k = (y_k + k3)
   
   y = y_k + (k1 + 2*k2 + 2*k3 + k4)/6;


   znachennia_y[k] = y;
   znachennia_fx[j] = 1/(sqrt(x_k*x_k + 1 + pow(exp,x_k*x_k)));
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
 
   masf[0] = (x_k * x_k * x_k * znachennia_y[j+2] * znachennia_y[j+2] * znachennia_y[j+2] - x_k * znachennia_y[j+2]);
   masf[1] = (x_k * x_k * x_k * znachennia_y[j+1] * znachennia_y[j+1] * znachennia_y[j+1] - x_k * znachennia_y[j+1]);
   masf[2] = (x_k * x_k * x_k * (znachennia_y[j] + masf[1] - masf[0]) * (znachennia_y[j] + masf[1] - masf[0]) * (znachennia_y[j] + masf[1] - masf[0]) - x_k * (znachennia_y[j] + masf[1] - masf[0]));

 int  d = 2;
for(int i = 4; i <= 6; i++) {


   y = (znachennia_y[i - 1]*48 - znachennia_y[i - 2]*36 + znachennia_y[i - 3]*16 - znachennia_y[i - 4]*3 + masf[2]*h1*12)/25;
   znachennia_y[i] = y;
   znachennia_fx[d] = 1/(sqrt(x_k*x_k + 1 + pow(exp,x_k*x_k)));
 
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
   masf[2] = (x_k * x_k * x_k * (znachennia_y[j] + masf[1] - masf[0]) * (znachennia_y[j] + masf[1] - masf[0]) * (znachennia_y[j] + masf[1] - masf[0]) - x_k * (znachennia_y[j] + masf[1] - masf[0]));
   x_k += h1;
}
//**************************************************************************************************************
  j = 0;
  k = 1;
  x_k = 0;
  y_k = 1/sqrt(2);
  znachennia_y[0] = 1/sqrt(2);

  cout << "------------------------------------------------------------------------------\n";
  cout << "|   x    |       y(xk)     |        yk       |       e        |      e%      |\n";
  cout << "------------------------------------------------------------------------------\n";
  for (int l = 0; l <= 2; l++) {
   k1 = h2 * (x_k * x_k * x_k * y_k * y_k * y_k - x_k * y_k); // x_k = (x_k + h2/2) y_k = (y_k + k1/2)
   k2 = h2 * ((x_k + h2/2) * (x_k + h2/2) * (x_k + h2/2) * (y_k + k1/2) * (y_k + k1/2) * (y_k + k1/2) - (x_k + h2/2) * (y_k + k1/2));
   k3 = h2 * ((x_k + h2/2) * (x_k + h2/2) * (x_k + h2/2) * (y_k + k2/2) * (y_k + k2/2) * (y_k + k2/2) - (x_k + h2/2) * (y_k + k2/2));// x_k = (x_k + h2/2) yk = (y_k + k2/2)
   k4 = h2 * ((x_k + h2) * (x_k + h2) * (x_k + h2) * (y_k + k3) * (y_k + k3) * (y_k + k3) - (x_k + h2) * (y_k + k3));// x_k = (x_k + h2) y_k = (y_k + k3)
   
   y = y_k + (k1 + 2*k2 + 2*k3 + k4)/6;


   znachennia_y[k] = y;
   znachennia_fx[j] = 1/(sqrt(x_k*x_k + 1 + pow(exp,x_k*x_k)));
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
 
   masf[0] = (x_k * x_k * x_k * znachennia_y[j+2] * znachennia_y[j+2] * znachennia_y[j+2] - x_k * znachennia_y[j+2]);
   masf[1] = (x_k * x_k * x_k * znachennia_y[j+1] * znachennia_y[j+1] * znachennia_y[j+1] - x_k * znachennia_y[j+1]);
   masf[2] = (x_k * x_k * x_k * (znachennia_y[j] + masf[1] - masf[0]) * (znachennia_y[j] + masf[1] - masf[0]) * (znachennia_y[j] + masf[1] - masf[0]) - x_k * (znachennia_y[j] + masf[1] - masf[0]));

  d = 2;
for(int i = 4; i <= 26; i++) {


   y = (znachennia_y[i - 1]*48 - znachennia_y[i - 2]*36 + znachennia_y[i - 3]*16 - znachennia_y[i - 4]*3 + masf[2]*h2*12)/25;
   znachennia_y[i] = y;
   znachennia_fx[d] = 1/(sqrt(x_k*x_k + 1 + pow(exp,x_k*x_k)));
 
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
   masf[2] = (x_k * x_k * x_k * (znachennia_y[j] + masf[1] - masf[0]) * (znachennia_y[j] + masf[1] - masf[0]) * (znachennia_y[j] + masf[1] - masf[0]) - x_k * (znachennia_y[j] + masf[1] - masf[0]));
   x_k += h2;
}
//**********************************************************************************************
  j = 0;
  k = 1;
  x_k = 0;
  y_k = 1/sqrt(2);
  znachennia_y[0] = 1/sqrt(2);

  cout << "------------------------------------------------------------------------------\n";
  cout << "|   x    |       y(xk)     |        yk       |       e        |      e%      |\n";
  cout << "------------------------------------------------------------------------------\n";
  for (int l = 0; l <= 2; l++) {
   k1 = h3 * (x_k * x_k * x_k * y_k * y_k * y_k - x_k * y_k); // x_k = (x_k + h3/2) y_k = (y_k + k1/2)
   k2 = h3 * ((x_k + h3/2) * (x_k + h3/2) * (x_k + h3/2) * (y_k + k1/2) * (y_k + k1/2) * (y_k + k1/2) - (x_k + h3/2) * (y_k + k1/2));
   k3 = h3 * ((x_k + h3/2) * (x_k + h3/2) * (x_k + h3/2) * (y_k + k2/2) * (y_k + k2/2) * (y_k + k2/2) - (x_k + h3/2) * (y_k + k2/2));// x_k = (x_k + h3/2) yk = (y_k + k2/2)
   k4 = h3 * ((x_k + h3) * (x_k + h3) * (x_k + h3) * (y_k + k3) * (y_k + k3) * (y_k + k3) - (x_k + h3) * (y_k + k3));// x_k = (x_k + h3) y_k = (y_k + k3)
   
   y = y_k + (k1 + 2*k2 + 2*k3 + k4)/6;


   znachennia_y[k] = y;
   znachennia_fx[j] = 1/(sqrt(x_k*x_k + 1 + pow(exp,x_k*x_k)));
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
 
   masf[0] = (x_k * x_k * x_k * znachennia_y[j+2] * znachennia_y[j+2] * znachennia_y[j+2] - x_k * znachennia_y[j+2]);
   masf[1] = (x_k * x_k * x_k * znachennia_y[j+1] * znachennia_y[j+1] * znachennia_y[j+1] - x_k * znachennia_y[j+1]);
   masf[2] = (x_k * x_k * x_k * (znachennia_y[j] + masf[1] - masf[0]) * (znachennia_y[j] + masf[1] - masf[0]) * (znachennia_y[j] + masf[1] - masf[0]) - x_k * (znachennia_y[j] + masf[1] - masf[0]));

   d = 2;
for(int i = 4; i <= 126; i++) {


   y = (znachennia_y[i - 1]*48 - znachennia_y[i - 2]*36 + znachennia_y[i - 3]*16 - znachennia_y[i - 4]*3 + masf[2]*h3*12)/25;
   znachennia_y[i] = y;
   znachennia_fx[d] = 1/(sqrt(x_k*x_k + 1 + pow(exp,x_k*x_k)));
 
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
   masf[2] = (x_k * x_k * x_k * (znachennia_y[j] + masf[1] - masf[0]) * (znachennia_y[j] + masf[1] - masf[0]) * (znachennia_y[j] + masf[1] - masf[0]) - x_k * (znachennia_y[j] + masf[1] - masf[0]));
   x_k += h3;
}

system("pause");
return 0;
}
