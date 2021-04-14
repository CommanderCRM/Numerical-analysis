#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;


double func(const double& x)
{
	return log(x);
}


double trapezoid(const int& n, const double& a, const double& b)
{
	double sum = 0;
	double step = (b - a) / n;
	for (int i = 1; i < n; ++i) {
		sum += func(a + i * step);
	}
	sum += (func(a) + func(b)) / 2;
	sum *= step;
	return sum;
}


int main()
{
	setlocale(LC_ALL, "rus");
	double a, b;
	int n;
	cout << "Введите нижний предел интегрирования" << endl;
	cin >> a;
	cout << "Введите верхний предел интегрирования" << endl;
	cin >> b;
	cout << "Введите шаг" << endl;
	cin >> n;
	cout << "Интеграл равен " << trapezoid(n, a, b) << endl;
	return 0;
}
