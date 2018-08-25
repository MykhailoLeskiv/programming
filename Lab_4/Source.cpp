#include <iostream>

using namespace std;

//функція виводу одного слова, до пробілу
void wordOutput(char *Array, int n, int &i)
{
	while (Array[i] != ' '&&Array[i] != '\0')
	{
		cout << Array[i];
		i++;
	}
	cout << "\n";
}
//функція пошуку початку наступного слова
void findBegin_nextWord(char *Array, int n, int &i)
{
	while (Array[i] != ' ')
		i++;
	while (Array[i] == ' ')
		i++;
}
int main()
{
	system("color F0");  //білий колір тла консолі
	int n;
	cout << "Enter a string: ";
	char s = getchar(); //зчитуєм один символ з потоку
	if (s == '\n') return 0;  //перевіряємо, чи не порожня стрічка
	n = cin.rdbuf()->in_avail();  //дізнаємося кількість символів в потоці
	char *Array = new char[n+1];  //оголошуємо масив відповідної розмірності та зчитуємо його
	cin.getline(Array+1, n+1);
	Array[0] = s;  //привоюємо значення першого символа з потоку першому елементу масиву
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