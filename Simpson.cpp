#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;


double func(const double& x)
{
	return log(x);
}


double simpson(const int& n, const double& a, const double& b)
{
	double h = (b - a) / n;
	double result = func(a) + func(b);

	for (int i = 1; i < n; ++i)
	{
		double factor = i % 2 != 0 ? 4.0 : 2.0;
		result += factor * func(a + h * i);
	}

	return h * result / 3;
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
	cout << "Интеграл равен " << simpson(n, a, b) << endl;
	return 0;
}
