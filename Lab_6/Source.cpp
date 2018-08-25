#include <iostream>
#include <fstream>
using namespace std;
//перетворення текстового файлу з цілими цислами у бінарний
void IntsToBin(ifstream& in, fstream& out) 
{
	in.seekg(0, ios::beg);
	out.seekg(0, ios::beg);
	int temp;
	while (!in.eof()) 
	{
		in >> temp;
		out.write((char *)&temp, sizeof(int));
	}
	out.flush();
}
//перетворення бінарного файлу в текстовий
void BinToInts(fstream& in, ofstream& out)
{
	in.seekg(0, ios::beg);
	int temp;
	while (true)
	{
		in.read((char *)&temp, sizeof(int));
		if (in.eof()) break;
		out << temp << "\n";
	}
	in.flush();
}
void Write(fstream &fin, fstream &fout)
{
	fin.seekg(0, ios::beg);
	while (true)  //цикл перевірки чисел на задані властивості
	{
		int elem;
		fin.read((char*)&elem, sizeof (int));
		if (fin.eof()) break;
		if (elem % 2 == 0 || (elem % 3 == 0 && elem % 7 != 0) || sqrt(elem) - (int)sqrt(elem) == 0)  //перевірка заданих умов
		{
			fout.write((char*)&elem, sizeof(int));
		}
	}
}
int main()
{
	ifstream fin;  //відкриття потрібних файлів
	fin.open("fin.txt", ios_base::in);
	fstream fout;
	fout.open("fout.bin", ios_base::out | ios_base::in | ios_base::binary | ios_base::trunc);
	ofstream foutInt;
	foutInt.open("fout.txt", ios_base::out);
	fstream finBin;
	finBin.open("finBin.bin", ios_base::out | ios_base::in | ios_base::binary | ios_base::trunc);
	IntsToBin(fin, finBin);
	Write(finBin, fout);
	BinToInts(fout, foutInt);
	fin.close();  //закриття усіх файлів
	fout.close();
	finBin.close();
	foutInt.close();
	return 0;
}