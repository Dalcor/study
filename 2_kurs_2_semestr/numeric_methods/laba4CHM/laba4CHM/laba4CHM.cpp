
#include<iostream>
#include<iomanip>

using namespace std;

int N = 50;
double Ra = 0.2;
double Rb = 1;
int g = 1.5e5;
int Tb = 20;
int Qa = 2500;
int k = 50;
int p = 2;
double delta = (Rb - Ra) / N;
int coun1 = N;

void Thomas(double *a, double *b, double *c, double *d, double *t, int N) {
  for (int i = 1; i<N; i++) {
    b[i] = b[i] - (a[i] * c[i - 1]) / b[i - 1];
    d[i] = d[i] - (a[i] * d[i - 1]) / b[i - 1];
  }

  t[N - 1] = d[N - 1] / b[N - 1];
  for (int i = N - 2; i >= 0; i--)
    t[i] = (d[i] - c[i] * t[i + 1]) / b[i];
}

int main(int argc, char** argv) {
  double *mas_a = new double[N + 1];
  double *mas_b = new double[N + 1];
  double *mas_c = new double[N + 1];
  double *mas_d = new double[N + 1];
  double *mas_T = new double[N + 1];

  for (int i = 1; i < N; i++) {
    mas_a[i] = (1 - (p*delta / 2.) / (Ra + i * delta));
    mas_b[i] = -2;
    mas_c[i] = (1 + (p*delta / 2.) / (Ra + i * delta));
    mas_d[i] = -g * pow(delta, 2.) / k;
  }

  mas_c[0] = 2;
  mas_b[0] = -2;
  mas_d[0] = -g * delta * delta / k - 2 * Qa * delta / k * (1 - (p * delta / 2) / Ra);

  mas_b[N] = 0;
  mas_a[N] = 1;
  mas_d[N] = Tb;

  Thomas(mas_a, mas_b, mas_c, mas_d, mas_T, N + 1);
  double krok = 0;

  cout << fixed;
  cout.precision(3);
  cout << "|  r    |    T    |" << endl;
  for (int i = 0; i <= N; i++) {
    cout << "| " << Ra + krok << " | " << setw(7) << mas_T[i] << " |" << endl;
    krok += delta;
  }
  system("pause");
  return 0;
}