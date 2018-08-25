#include <iostream>
#include <cstdlib>
#include <math.h>
#include <iomanip>

using namespace std;
int main()
{
	/*ініціалізація змінних:
	a - для піднесення 2 у степінь
	mult - результат обчислення виразу
	dob - частина виразу з змінною величиною
	dod - частина виразу без змін у циклі*/
	double a = 1, x, eps, mult = 1, dob = 1, dod;
	//цикли вводу з перевіркою коректності
	for (;;)
	{
		cout << "Vvedit` zminnu x: ";
		cin >> x;
		if ((cin.peek()) != '\n')
		{
			cout << "Input error!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else break;
	}
	for (;;)
	{
		cout << "Vvedit` tochnist`: ";
		cin >> eps;
		if ((cin.peek()) != '\n')
		{
			cout << "Input error!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else break;
	}
	int prec = abs(floor(log10(eps))) + 2; //змінна для кількості знаків після коми
	if (x == 0) dod = 1; //перевірка чи х не є нулем, 1 важлива границя
	else dod = sin(x) / x;
	int i = 1; //керуюча змінна циклу
	cout << left << setw(5) << setfill(' ') << setprecision(0) << "n" << setw(prec + 9) << setfill(' ') << setprecision(prec) << "Znachenna" << left << setw(prec+3) << setfill(' ') << setprecision(0) << "2^n" << setprecision(prec) << "sin(x)/x" << "\n";
	for (; abs(mult) > eps; ++i)
	{
		a *= 2; //піднесення 2 до натуральних степенів
		dob *= cos(x / a);
		mult = dod - dob;
		cout << fixed;
		//вивід результатів обчислень
		cout << left << setw(5) << setfill(' ') << setprecision(0) << i << setw(prec + 9) << setfill(' ') << setprecision(prec) << mult << left << setw(prec+3) << setfill(' ') << setprecision(0) << a << setprecision(prec) << dod << "\n";
	}
	//обчислення через інші цикли
	/*while (abs(mult) > eps)
	{
		dob *= cos(x / a);
		mult = dod - dob;
		cout << fixed;
		cout << left << setw(5) << setfill(' ') << setprecision(0) << i << setw(prec + 9) << setfill(' ') << setprecision(prec) << mult << left << setw(prec+3) << setfill(' ') << setprecision(0) << a << setprecision(prec) << dod << "\n";
		++i;
	}
	do
	{
		dob *= cos(x / a);
		mult = dod - dob;
		cout << fixed;
		cout << left << setw(5) << setfill(' ') << setprecision(0) << i << setw(prec + 9) << setfill(' ') << setprecision(prec) << mult << left << setw(prec+3) << setfill(' ') << setprecision(0) << a << setprecision(prec) << dod << "\n";
		++i;
	} while (abs(mult) > eps);*/
	cout << "Pry n=" << i-1 << " nerivnist vykonuet`sia\n";
	system("pause");
	return 0;
}