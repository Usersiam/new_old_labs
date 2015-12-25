#include "stdafx.h"
#include<iostream>
#include<map>
#include "time.h"

using namespace std;
class Matrix
{
public:
	int mass[3][3];
	int operator >> (const Matrix &a)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{

				mass[i][j] = rand() % 10;
			}
		return 0;
	}
	void operator << (const Matrix &a)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{

				cout<<mass[i][j] <<"    ";
			}
		cout << endl;
	}
};

class MyMap :public map<char *,Matrix>
{

public:
	
	void Вывод_контейнера()
	{
		for (auto it = begin(); it != end(); it++)
		{
			cout << endl;
			cout << it->first << "    :    ";
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					cout << it->second.mass[i][j] << "  ";
		}
		
	}
	void Erase_between(int n_0, int n)
	{
		auto it = begin();
		

		for (int i = 0; i < n; i++)
		{
			if (i >= n_0-1)
			{ erase(it++); }
			else it++;
		}
	}
	void Swap(MyMap &a, MyMap &b)
	{
		auto it = b.begin();
		auto it2 = b.end();


		a.insert(it, it2);
	}
	
	


};
void main()
{
	srand(time(NULL));
	//создание
	system("chcp 1251");

	MyMap zero;
	Matrix массив_обьектов[7];
	for (int i = 0; i < 7; i++)
	{
		массив_обьектов[i] >> массив_обьектов[i];
	}
	for (int i = 0; i < 7; i++)
	{
		массив_обьектов[i] << массив_обьектов[i];
	}
	//инициализация
	zero.insert(pair<char*, Matrix>("первый   ", массив_обьектов[1]));
	zero.insert(pair<char*, Matrix>("второй   ", массив_обьектов[2]));
	zero.insert(pair<char*, Matrix>("третий   ", массив_обьектов[3]));
	zero.insert(pair<char*, Matrix>("четвертый", массив_обьектов[4]));
	zero.insert(pair<char*, Matrix>("пятый    ", массив_обьектов[5]));

	//просмотр
	cout << endl << endl;
	zero.Вывод_контейнера();
	//изменение
	zero.erase("пятый    ");
	zero.insert(pair<char*, Matrix>("пятый2.0", массив_обьектов[6]));
	zero.at("четвертый") = массив_обьектов[3];
	cout << endl << endl;
	zero.Вывод_контейнера();

	//второй контейнер
	MyMap ноль;
	ноль.insert(pair<char*, Matrix>("первый(2)", массив_обьектов[4]));
	ноль.insert(pair<char*, Matrix>("второй(2)", массив_обьектов[5]));

	//удаление
	cout << endl << endl << "введите номер заданного элемента" << endl;
	int n_0;
	cin >> n_0;
	cout << endl<<endl << "введите количество удаляемых элементов" << endl;
	int n;
	cin >> n;
	cout << endl;
	zero.Erase_between(n_0,n);
	zero.Вывод_контейнера();
	cout << endl << endl;
	ноль.Вывод_контейнера();
	cout << endl << endl;
	zero.Swap(zero, ноль);
	zero.Вывод_контейнера();
	cout << endl << endl;
	ноль.Вывод_контейнера();
	cout << endl << endl;
	

}




