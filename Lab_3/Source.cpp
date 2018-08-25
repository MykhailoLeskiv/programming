#include <iostream>

using namespace std;

void dimension(int &n)
{
	cout << "Enter a dimension of square matrix: ";
	cin >> n;
	while ((cin.peek()) != '\n' || n < 1)
	{
		cout << "Input error!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a dimension of square matrix: ";
		cin >> n;
	}
}
void input_matrix(double **Matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
			cin >> Matrix[i][j];
			while ((cin.peek()) != '\n')
			{
				cout << "Input error!\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
				cin >> Matrix[i][j];
			}
		}
	}
}
void transponate_matrix(double **Matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double temp = Matrix[i][j];
			Matrix[i][j] = Matrix[j][i];
			Matrix[j][i] = temp;
		}
	}
}
void summarize_rows(double temp_sum, double& max_sum, int& row, double **Matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp_sum += Matrix[i][j];
			if (temp_sum>max_sum) max_sum = temp_sum, row = i;
		}
		temp_sum = 0;
	}
}
void output_matrix(double **Matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			cout << Matrix[i][j] << "\t";
		}
		cout << Matrix[i][n - 1] << "\n";
	}
}
int main()
{
	int n = 0, row = 0;
	double temp_sum = 0, max_sum = 0;
	char a;
	dimension(n);
	double **A;
	A = new double *[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
	}
	input_matrix(A, n);
	summarize_rows(temp_sum, max_sum, row, A, n);
	output_matrix(A, n);
	cout << row + 1 << " row has the biggest sum: " << max_sum << "\n";
	cout << "Would you like to calculate the biggest row in transponate matrix?\nPress 'y' to calculate ";
	cin >> a;
	if (a == 'y')
	{
		temp_sum = 0, max_sum = 0, row = 0;
		transponate_matrix(A, n);
		summarize_rows(temp_sum, max_sum, row, A, n);
		output_matrix(A, n);
		cout << row + 1 << " row has the biggest sum: " << max_sum << "\n";
	}
	system("pause");
	delete A;
	return 0;
	//функцію vvid_elem_z_obr забрати, зробити з неї дві окремі
	//додати функцію транспонування "Не бажаєте?:)" і переробити на англійську мову
}