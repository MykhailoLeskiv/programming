#include <iostream>

using namespace std;

//������� ������ ������ �����, �� ������
void wordOutput(char *Array, int n, int &i)
{
	while (Array[i] != ' '&&Array[i] != '\0')
	{
		cout << Array[i];
		i++;
	}
	cout << "\n";
}
//������� ������ ������� ���������� �����
void findBegin_nextWord(char *Array, int n, int &i)
{
	while (Array[i] != ' ')
		i++;
	while (Array[i] == ' ')
		i++;
}
int main()
{
	system("color F0");  //���� ���� ��� ������
	int n;
	cout << "Enter a string: ";
	char s = getchar(); //������ ���� ������ � ������
	if (s == '\n') return 0;  //����������, �� �� ������� ������
	n = cin.rdbuf()->in_avail();  //�������� ������� ������� � ������
	char *Array = new char[n+1];  //��������� ����� �������� ��������� �� ������� ����
	cin.getline(Array+1, n+1);
	Array[0] = s;  //��������� �������� ������� ������� � ������ ������� �������� ������
	int i = 0;
	while (i < n + 1)
	{
		wordOutput(Array, n + 1, i);
		findBegin_nextWord(Array, n + 1, i);
		findBegin_nextWord(Array, n + 1, i);
	}
	delete[]Array;
	return 0;
}