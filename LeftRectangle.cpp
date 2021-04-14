#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;


double func(const double& x)
{
	return log(x);
}


double leftRectangle(const int& n, const double& a, const double& b)
{
	double sum = 0;
	double step = (b - a) / n;
	for (double i = a;i < b;i = i + step)
		sum += func(i);
	return sum * step;
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
	cout << "Интеграл равен " << leftRectangle(n, a, b) << endl;
	return 0;
}
