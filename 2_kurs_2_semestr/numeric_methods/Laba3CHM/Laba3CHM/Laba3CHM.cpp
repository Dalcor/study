#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
  double a[13]; //piddiagonal
  double b[12]; //diagonal
  double c[12]; //naddiagonal
  double d[12]; //prava chastyna
  double T[12]; //rishennnia
  double masResult[12];
  double masC[12];
  //*********************_Zapovnennia masyviv_*********************************
  int i;
  double c_c = 1.0;
 a[2] = 0.4;
 b[1] = -5.5;
 c[1] = 0.5;
  for(i = 1; i < 10; i++) {
     a[i + 2] = a[i + 1] + 0.1;
   //  cout  << "a["<< i + 1 << "] = " << a[i + 1] << "\n";

  }
//  cout << "\n";
    for(i = 1; i <= 10; i++) {
     b[i+1] = (b[i] - 0.1) * c_c;
     //cout  << "b["<< i << "] = " << b[i] << "\n";
  }
 //   cout << "\n";
     for(i = 1; i < 10; i++) {
     c[i+1] = (c[i] + 0.2) * c_c;
    // cout  << "c["<< i << "] = " << c[i] << endl;
  }
     d[1] = 1.95;
     d[2] = 2.22;
     d[3] = 2.54;
     d[4] = 2.82;
     d[5] = 3.06;
     d[6] = 3.26;
     d[7] = 3.42;
     d[8] = 3.54;
     d[9] = 3.62;
     d[10] = 6.88;

     masResult[1] = -0.4;
     masResult[2] = -0.5;
     masResult[3] = -0.6;
     masResult[4] = -0.7;
     masResult[5] = -0.8;
     masResult[6] = -0.9;
     masResult[7] = -1.0;
     masResult[8] = -1.1;
     masResult[9] = -1.2;
     masResult[10] = -1.3;
//*****************************************************************
 // cout << endl;
  //perezapys diagonali i pravoi chactyny
  for(int j = 2; j <= 10; j++){
  b[j] = b[j] - a[j]*c[j-1]/b[j-1];
//  cout  << "b["<< j - 1 << "] = " << b[j - 1]  << "\t"  << "\t";
  d[j] = d[j] - a[j] * d[j-1] / b[j - 1];
 // cout  << "d["<< j - 1 << "] = " << d[j - 1] << endl;
  }
 cout << "FOR c = 1.0\n";
 cout << "----------------------------\n" ;
 cout << "|       T[N]         |  X  |\n";
 cout << "----------------------------\n";
 //  cout  << "b["<< "10" << "] = " << b[10]  << "\t";
 //  cout  << "d["<< "10" << "] = " << d[10]  << "\n";
      //vyznachennia õ(10)
  T[10] = d[10]/b[10];
  cout.fixed;
  
  cout  << "|" << setprecision(18) << setw(20) <<  T[10] << "|" << setprecision(2) << setw(5) << masResult[10] << "|"<< endl;
     //vyznachennia inshyh znachen' õ
  for(int k = 9; k >= 1; k--) {
   T[k] = (d[k] - c[k] * T[k+1])/b[k];
   cout  << "|" << setprecision(18) << setw(20) << T[k] << "|" << setprecision(2) << setw(5) << masResult[k] << "|" <<  endl;
  }
   cout << "----------------------------\n" ;
  cout << endl;
  
  //*******************************************TASK_2*****************************************
 c_c = 0.1;
 a[2] = 0.4;
 b[0] = -5.5;
 c[1] = 0.5;
 masC[1] = -5.5;
  for(int j = 1; j <= 10; j++) {
     masC[j+1] = masC[j] - 0.1;
     }

  for(i = 1; i < 10; i++) {
     a[i + 2] = a[i + 1] + 0.1;
  }

  cout << "\n";

  for(i = 1; i <= 10; i++) {
     b[i] = masC[i] * c_c;
  }

  for(i = 1; i < 10; i++) {
     c[i+1] = (c[i] + 0.2);
  }
     d[1] = -0.030;
     d[2] = -0.300;
     d[3] = -0.538;
     d[4] = -0.834;
     d[5] = -1.188;
     d[6] = -1.600;
     d[7] = -2.070;
     d[8] = -2.598;
     d[9] = -3.184;
     d[10] = -0.608;


//*****************************************************************
 // cout << endl;
  
  for(int j = 2; j <= 10; j++){
  b[j] = b[j] - a[j]*c[j-1]/b[j-1];
  d[j] = d[j] - a[j] * d[j-1] / b[j - 1];
  }
 cout << "FOR c = 0.1\n";
 cout << "----------------------------\n" ;
 cout << "|       T[N]         |  X  |\n";
 cout << "----------------------------\n";

  T[10] = d[10]/b[10];
  cout.fixed;
  cout  << "|" << setprecision(18) << setw(20) <<  T[10] << "|"  << setprecision(2) << setw(5)<< masResult[10] << "|"<< endl;
  for(int k = 9; k >= 1; k--) {
   T[k] = (d[k] - c[k] * T[k+1])/b[k];
   cout  << "|" << setprecision(18) << setw(20) << T[k] << "|" << setprecision(2) << setw(5) << masResult[k] << "|" <<  endl;
  }
  cout << "----------------------------\n" ;
  cout << endl;


  //*******************************************TASK_3*****************************************
  
  
  c_c = 0.001;
 a[2] = 0.4;
 b[0] = -5.5;
 c[1] = 0.5;
 masC[1] = -5.5;
     for(int j = 1; j <= 10; j++) {
     masC[j+1] = masC[j] - 0.1;
     }

  for(i = 1; i < 10; i++) {
     a[i + 2] = a[i + 1] + 0.1;
  }

  cout << "\n";

  for(i = 1; i <= 10; i++) {
     b[i] = masC[i] * c_c;
  }

  for(i = 1; i < 10; i++) {
     c[i+1] = (c[i] + 0.2);
  }
     d[1] = -0.24780;
     d[2] = -0.57720;
     d[3] = -0.87658;
     d[4] = -1.23594;
     d[5] = -1.65528;
     d[6] = -2.13460;
     d[7] = -2.67390;
     d[8] = -3.27318;
     d[9] = -3.93244;
     d[10] = -1.43168;


//*****************************************************************

  for(int j = 2; j <= 10; j++){
  b[j] = b[j] - a[j]*c[j-1]/b[j-1];

  d[j] = d[j] - a[j] * d[j-1] / b[j - 1];

  }
 cout << "FOR c = 0.001\n";
 cout << "----------------------------\n" ;
 cout << "|       T[N]         |  X  |\n";
 cout << "----------------------------\n";

  T[10] = d[10]/b[10];
  cout.fixed;
  cout  << "|" << setprecision(18) << setw(20) <<  T[10] << "|"  << setprecision(2) << setw(5)<< masResult[10] << "|"<< endl;
  for(int k = 9; k >= 1; k--) {
   T[k] = (d[k] - c[k] * T[k+1])/b[k];
   cout  << "|" << setprecision(18) << setw(20) << T[k] << "|" << setprecision(2) <<  setw(5) << masResult[k] << "|" <<  endl;
  }
  cout << "----------------------------\n" ;
  cout << endl;
}
