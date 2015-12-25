#include "stdafx.h"
#include<iostream>
#include<map>
using namespace std;

class MyMap :public map<char*, int>
{

public:
	void Draw()
	{
		for (auto it = begin(); it != end(); ++it)
		{
			cout << it->first << " : " << it->second << endl;
		}
		
		cout << endl;
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
//создание
	system("chcp 1251");
	
	MyMap zero;
	
	zero.insert(pair<char*, int>("алмаз",1));
	zero.insert(pair<char*, int>("рубин", 2));
	zero.insert(pair<char*, int>("изумруд", 3));
	zero.insert(pair<char*, int>("сапфир", 4));
	
//просмотр
	cout << endl;
	cout<< "алмаз : "<<zero["алмаз"];
	cout << endl;
	cout << "сапфир : "<<zero["сапфир"];
	cout << endl << endl;
//вывод с итератором
	zero.Draw();
	
//изменение
	zero.erase("сапфир");
	zero.insert(pair<char*,int>("камень",10));
	zero.at("алмаз") = 50;
	
//вывод с итератором
	
	zero.Draw();
//второй контейнер
	

	MyMap ноль;

	ноль.insert(pair<char*, int>("рубин 1.0", 420));
	ноль.insert(pair<char*, int>("алмаз 1.0", 230));
	ноль.insert(pair<char*, int>("сапфир 1.0", 140));
	ноль.insert(pair<char*, int>("изумруд 1.0", 350));
	cout<<zero.size();
cout << endl << "введите заданный элемент" << endl;
	int n_0;
	cin >> n_0;
	cout << endl;
	cout << endl << "введите количество удаляемых элементов" << endl;
	int n;
	cin >> n;
	cout << endl;
	zero.Erase_between(n_0,n);
	zero.Swap(zero,ноль);
	zero.Draw();

	ноль.Draw();

	

}