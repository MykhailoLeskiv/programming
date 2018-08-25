#include <iostream>
using namespace std;
void dimension(int &n)
{
	cout << "Enter a dimension of array: ";
	cin >> n;
	while ((cin.peek()) != '\n' || n < 1)
	{
		cout << "Input error!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a dimension of array: ";
		cin >> n;
	}
}
void input_array(double *Array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter element [" << i + 1 << "]: ";
		cin >> Array[i];
		while ((cin.peek()) != '\n')
		{
			cout << "Input error!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter element [" << i + 1 << "]: ";
			cin >> Array[i];
		}
	}
}
void find_max(double *Array, int n, double max, int &max_elem)
{
	for (int i = 0;i < n;++i)
	{
		if (Array[i] > max) max = Array[i], max_elem = i;
	}
}
void find_firstdod(double *Array, int n, int &max_elem, int &dod)
{
	int i = max_elem - 1;
	for (;i >= 0;i--)
	{
		if (Array[i] > 0) break;
	}
	dod = i;
}
void vykl(double *Array, int n, int &dod)
{
	for (int i = 0;i < n;++i)
	{
		if (i >= dod) Array[i] = Array[i + 1];
	}
}
void output_array(double *Array, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		cout << Array[i] << "\n";
	}
}
int main()
{
	int n = 0, max_elem = 0, dod = 0;
	double max = 0;
	cout << "Additional task: \n";
	dimension(n);
	double *A = new double[n];
	input_array(A, n);
	find_max(A, n, max, max_elem);
	find_firstdod(A, n, max_elem, dod);
	vykl(A, n, dod);
	output_array(A, n);
	delete A;
	system("pause");
	return 0;
}