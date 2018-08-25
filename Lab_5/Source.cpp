#include <iostream>

using namespace std;

struct Student //���� ��������� �������
{
	char *sirname;
	int age;
	double height;
	double average_mark;
};
Student Input() //������� ����� �������� ��������� � ��������� �����������
{
	Student student;
	bool flag = true;
	for(;;)
	{
		int n;
		if (flag == false) cout << "Enter sirname of a student: ";
		char s = getchar();
		flag = false;
		if (s == '\n') continue;
		n = (int)cin.rdbuf()->in_avail();
		student.sirname = new char[n + 1];
		cin.getline(student.sirname + 1, n + 1);
		student.sirname[0] = s;
		break;
	}
	cout << "Enter age of the student " << student.sirname << ": ";
	cin >> student.age;
	while ((cin.peek()) != '\n' || student.age < 1)
	{
		cout << "Input error!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter age of the student " << student.sirname << ": ";
		cin >> student.age;
	}
	cout << "Enter height of the student " << student.sirname << ": ";
	cin >> student.height;
	while ((cin.peek()) != '\n' || student.height < 1)
	{
		cout << "Input error!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter height of a student " << student.sirname << ": ";
		cin >> student.height;
	}
	cout << "Enter average mark of a student " << student.sirname << ": ";
	cin >> student.average_mark;
	while ((cin.peek()) != '\n' || student.average_mark < 0 || student.average_mark > 100)
	{
		cout << "Input error!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter average mark of a student " << student.sirname << ": ";
		cin >> student.average_mark;
	}
	return student;
}
void Output(Student *Array, int n) //������� ������ ������ ��������
{
	for (int i = 0; i < n; i++)
	{
		cout << "Student " << Array[i].sirname << "\n";
		cout << "Age: " << Array[i].age << "\n";
		cout << "Height: " << Array[i].height << "\n";
		cout << "Average mark: " << Array[i].average_mark << "\n--- --- --- --- --- --- ---\n";
	}
}
double* Average(Student *Array , int n) //������� ������ ������� ������� ���������
{
	double *average = new double [3];
	average[0] = average[1] = average[2] = 0;
	for (int i = 0; i < n; i++)
	{
		average[0] += Array[i].age;
		average[1] += Array[i].height;
		average[2] += Array[i].average_mark;
	}
	average[0] /= n;
	average[1] /= n;
	average[2] /= n;
	return average;
}
double** Ranking(Student *Array, int n, double *arrayOFaverage) //������� ���������� �������� ��������
{
	double **ranking = new double *[n]; //� ������� ����� ������������ ���������� ��� ������ ��������
	for (int i = 0; i < n; i++) 
	{
		ranking[i] = new double[4];
	}
	for (int i = 0; i < n; i++)
	{
		ranking[i][1] = abs(Array[i].age - arrayOFaverage[0]); //������ �������� - ��������� �� ���������� �� ����
		ranking[i][2] = abs(Array[i].height - arrayOFaverage[0]); //�� �������
		ranking[i][3] = abs(Array[i].average_mark - arrayOFaverage[0]); //�� �������
		ranking[i][0] = ranking[i][1] + ranking[i][2] + ranking[i][3]; //�������� ���������
	}
	return ranking;
}
void Aver_Uniq_stud(Student *Array, int n, double **ranking)
{
	int position = 0; //����� �������� ������� ������������� �� ���������� ��������
	double maxMin = ranking[0][0]; //����� ��� ���������/������
	int i = 0;
	for (; i < n; i++) //����� ������������� ��������(�� ������� ������� ������ �������)
	{
		if (ranking[i][0] < maxMin)
		{
			maxMin = ranking[i][0];
			position = i;
		}
	}
	cout << "The most average student is " << Array[position].sirname << "\n";
	i = 0; position = 0;
	maxMin = ranking[0][0];
	for (; i < n; i++) //����� ��������������
	{
		if (ranking[i][0] > maxMin)
		{
			maxMin = ranking[i][0];
			position = i;
		}
	}
	cout << "The most unique student is " << Array[position].sirname << "\n";
	int *students = new int[3]; //����� ��� ����� "�������" �� k-�� ����������
	i = 1;
	for (; i < 4; i++) //���� ������ ������������ �� k-�� ����������
	{
		maxMin = ranking[0][i];
		students[i - 1] = 0;
		for (int j = 0; j < n; j++)
		{
			if (ranking[j][i] < maxMin)
			{
				maxMin = ranking[j][i];
				students[i - 1] = j;
			}
		}
	}
	if (ranking[students[0]][0] > ranking[students[1]][0]) //����� �������������� ����� �������
		if (ranking[students[0]][0] > ranking[students[2]][0])
			cout << "The most unique of averages is " << Array[students[0]].sirname << "\n";
		else cout << "The most unique of averages is " << Array[students[2]].sirname << "\n";
	else if (ranking[students[1]][0] > ranking[students[2]][0])
		cout << "The most unique of averages is " << Array[students[1]].sirname << "\n";
	else cout << "The most unique of averages is " << Array[students[2]].sirname << "\n";
	i = 1;
	for (; i < 4; i++) //���� ������ ������������� �� k-�� ����������
	{
		maxMin = 0;
		students[i - 1] = 0;
		for (int j = 0; j < n; j++)
		{
			if (ranking[j][i] > maxMin)
			{
				maxMin = ranking[j][i];
				students[i] = j;
			}
		}
	}
	if (ranking[students[0]][0] < ranking[students[1]][0])  //����� ������������� ����� ���������
		if (ranking[students[0]][0] < ranking[students[2]][0])
			cout << "The most average of uniques is " << Array[students[0]].sirname << "\n";
		else cout << "The most average of uniques is " << Array[students[2]].sirname << "\n";
	else if (ranking[students[1]][0] < ranking[students[2]][0])
		cout << "The most average of uniques is " << Array[students[1]].sirname << "\n";
	else cout << "The most average of uniques is " << Array[students[2]].sirname << "\n";
}
int main()
{
	system("color F0");
	int n;
	cout << "Enter quantity of students in a group: ";
	cin >> n;
	Student *Array = new Student[n];
	for (int i = 0; i < n; i++)
	{
		Array[i] = Input();
		cout << "- - - - - - - - - - - - - - - - -\n";
	}
	Output(Array, n);
	Aver_Uniq_stud(Array, n, Ranking(Array, n, Average(Array, n)));
	delete[] Array;
	system("pause");
	return 0;
}