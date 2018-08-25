#include <iostream>

using namespace std;

struct List  //опис робочої структури
{
	int key;
	List* next;
};
//функція формування списку
void List_Formation(List** begin, int n)  
{
	List *next = new List;
	(*begin)->key = 3;
	(*begin)->next = next;
	next = (*begin);
	for (int i = 5; i <= 2 * n; i += 2)  //цикл ініціалізації, лише непарними числами
	{
		List *next2 = new List;
		next2->key = i;
		next2->next = NULL;
		next->next = next2;
		next = next2;
	}
}
//функція виводу елементів
void List_Output(List* begin, int n)
{
	while (begin)
	{
		if (begin->key > n)
			cout << begin->key << "\t";
		begin = begin->next;
	}
	cout << "\n";
}
//"решето Ератосфена"
void Sieve(List* begin, int n)
{
	List *temp = new List;
	List *newBegin = new List;
	while (begin)
	{
		newBegin = begin;
		int index = newBegin->key;  //змінна на яку не повинні ділитися прості числа
		while ((newBegin->next))
		{
			if ((newBegin->next)->key % index == 0 && (newBegin->next)->next != NULL) //перевірка подільності
			{
				temp = (newBegin->next);
				(newBegin->next) = (newBegin->next)->next;
				delete temp;
			}
			else if ((newBegin->next)->key % index == 0 && (newBegin->next)->next == NULL)  //перевірка подільності останнього елемента
			{
				temp = newBegin->next;
				newBegin->next = NULL;
				delete temp;
				break;
			}
			newBegin = newBegin->next;
		}
		if (begin->next != NULL)
			begin = begin->next;
		else break;
	}
}
int main()
{
	system("color F0");
	int n;
	cout << "Enter a number (>1000): ";
	cin >> n;
	while ((cin.peek()) != '\n' || n < 1001 || n > 100000)
	{
		cout << "Input error!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a number (>1000): ";
		cin >> n;
	}
	List *begin = new List;
	List_Formation(&begin, n);
	Sieve(begin, n);
	List_Output(begin, n);
	system("pause");
	return 0;
}