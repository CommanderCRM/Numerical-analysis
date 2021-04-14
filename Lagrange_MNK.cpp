#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

double func(double x){
return log(2 * x * x * x); }

double n[12] = { 0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0,2.2,2.4 };

struct coord {
	double y;
};

double a[3][4];
coord tabl[12];

double Lagrange(double x, int i) { return (((x - n[i]) * (x - n[i + 1])) / ((n[i - 1] - n[i]) * (n[i - 1] - n[i + 1]))) * tabl[i - 1].y + (((x - n[i - 1]) * (x - n[i + 1])) / ((n[i] - n[i - 1]) * (n[i] - n[i + 1]))) * tabl[i].y + (((x - n[i - 1]) * (x - n[i])) / ((n[i + 1] - n[i - 1]) * (n[i + 1] - n[i]))) * tabl[i + 1].y; }

int main() {
	cout << "\n" << " Pary (x;y)\n" << endl;
	for (int i = 0; i < 12; i++) {
		tabl[i].y = func(n[i]);
		cout << " (" << n[i] << ";" << "\t" << tabl[i].y << ")" << endl;
	}

	cout << "\n\t" << " Polinom Lagranga " << endl;                                 
	for (int i = 0; i < 12; i++) { cout << " " << Lagrange(n[i], i) << endl; }

	double d, x[3], x0, tempX1, tempX2, tempX3;
	cout << "\n\t" << " Nahogdenie koefficientov: " << endl;                      
	for (int i = 0; i <= 11; i++) {
		a[0][0] += pow(n[i], 0);	//c
		a[0][1] += n[i];			//b
		a[0][2] += pow(n[i], 2);	//a
		a[0][3] += tabl[i].y;     //f(x)

		a[1][0] += n[i];
		a[1][1] += pow(n[i], 2);
		a[1][2] += pow(n[i], 3);
		a[1][3] += tabl[i].y * n[i];

		a[2][0] += pow(n[i], 2);
		a[2][1] += pow(n[i], 3);
		a[2][2] += pow(n[i], 4);
		a[2][3] += tabl[i].y * pow(n[i], 2);
	}

	for (int k = 0; k < 3; k++) {
		for (int i = k + 1; i < 3; i++) {
			d = -(a[i][k] / a[k][k]);
			for (int j = k; j < 4; j++) {
				a[i][j] = a[i][j] + a[k][j] * d;
			}
		}
	}

	x[2] = a[2][3] / a[2][2];
	x[1] = (a[1][3] - x[2] * a[1][2]) / a[1][1];
	x[0] = (a[0][3] - a[0][2] * x[2] - a[0][1] * x[1]) / a[0][0];

	cout << " a = " << x[2] << endl;
	cout << " b = " << x[1] << endl;
	cout << " c = " << x[0] << endl;

	cout << "\n\t" << " Tablitca:" << endl;
	for (int u = 0, h = 0; u < 3; u++) {
		cout << "\n Vvedite x: "; cin >> x0;
		for (h = 0; h < 13; h++) {
			if (x0 == n[0]) { tempX1 = n[0]; tempX2 = n[1]; tempX3 = n[2]; break; }
			if (x0 <= n[h]) { tempX1 = n[h - 1]; tempX2 = n[h]; tempX3 = n[h + 1]; break; }
			if (x0 >= n[11]) { tempX1 = n[9]; tempX2 = n[10]; tempX3 = n[11]; break; }
		}
		cout << " f(" << x0 << ") = " << func(x0) << endl;
		cout << " Polinom Lagranga pri x = " << x0 << ": " << ((((x0 - tempX2) * (x0 - tempX3)) / ((tempX1 - tempX2) * (tempX1 - tempX3))) * func(tempX1) + (((x0 - tempX1) * (x0 - tempX3)) / ((tempX2 - tempX1) * (tempX2 - tempX3))) * func(tempX2) + (((x0 - tempX1) * (x0 - tempX2)) / ((tempX3 - tempX1) * (tempX3 - tempX2))) * func(tempX3)) << endl;
		cout << " Approksimatciya pri x = " << x0 << ": " << x[2] * pow(x0, 2) + x[1] * x0 + x[0] << endl;
	}
	return 0;
}
