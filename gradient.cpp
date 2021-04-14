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
int main()
{
	setlocale(0, "");
	double x1 = 3, x2 = 4, t = 0.01;
	cout << "Метод градиентного спуска:" << endl;
	const double E = 0.01;
	int i = 0;
	do
	{
		i++;
		x1 = x1 - t * diff_f1(x1);
		x2 = x2 - t * diff_f2(x2);
		cout << x1 << " = x1 Номер итерации " << i << endl;
		cout << x2 << " = x2 Номер итерации " << i << endl;
	} while ((abs(diff_f1(x1)) >= E) || (abs(diff_f2(x2)) >= E));
	cout << "Минимум был получен за " << i << " итераций" << endl;
	double min1[2] = { x1,x2 };
	cout << "Минимум = ( " << min1[0] << " ; " << min1[1] << " )" << endl;
	return 0;
}
