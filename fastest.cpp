#include <iostream> 
#include <math.h> 
#include <stdio.h> 

using namespace std;
double function(double x1, double x2)
{
	double f = 3 * (x1 - 5) * (x1 - 5) + 70 * (x2 - 6) * (x2 - 6) + 87;
	return f;
}
double diff_f1(double x1)
{
	return 6 * x1 - 30;
}
double diff_f2(double x2)
{
	return 140 * x2 - 840;
}
double zolotoe_sechenie(double x1, double x2)
{
	double a = 0, b = 1;
	double fi = (1 + sqrt(5)) / 2;
	const double E = 0.01;
	do
	{
		double t1 = b - (b - a) / fi;
		double t2 = a + (b - a) / fi;
		double f1 = function(x1 - t1 * diff_f1(x1), x2 - t1 * diff_f2(x2));
		double f2 = function(x1 - t2 * diff_f1(x1), x2 - t2 * diff_f2(x2));

		if (f1 >= f2)
		{
			a = t1;
		}
		else
		{
			b = t2;
		}
	
	} while (abs(a - b) > E);
	return (a + b) / 2;
}
int main()
{
	setlocale(0, "");
	cout << "Метод наискорейшего спуска:" << endl;
	int i = 0;
	double x1 = 3;
	double x2 = 4;
	const double E = 0.01;
	do
	{
		i++;
		double t2 = zolotoe_sechenie(x1, x2);
		x1 = x1 - t2 * diff_f1(x1);
		x2 = x2 - t2 * diff_f2(x2);
		cout << x1 << " = x1 Номер итерации " << i << endl;
		cout << x2 << " = x2 Номер итерации " << i << endl;
	} while ((abs(diff_f1(x1)) >= E) || (abs(diff_f2(x2)) >= E));
	cout << "Минимум был получен за " << i << " итераций" << endl;
	double min2[2] = { x1,x2 };
	cout << "Минимум = ( " << min2[0] << ";" << min2[1] << ")" << endl;
	return 0;
}
