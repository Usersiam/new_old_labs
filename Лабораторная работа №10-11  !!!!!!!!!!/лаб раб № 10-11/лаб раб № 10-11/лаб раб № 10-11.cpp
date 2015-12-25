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
//��������
	system("chcp 1251");
	
	MyMap zero;
	
	zero.insert(pair<char*, int>("�����",1));
	zero.insert(pair<char*, int>("�����", 2));
	zero.insert(pair<char*, int>("�������", 3));
	zero.insert(pair<char*, int>("������", 4));
	
//��������
	cout << endl;
	cout<< "����� : "<<zero["�����"];
	cout << endl;
	cout << "������ : "<<zero["������"];
	cout << endl << endl;
//����� � ����������
	zero.Draw();
	
//���������
	zero.erase("������");
	zero.insert(pair<char*,int>("������",10));
	zero.at("�����") = 50;
	
//����� � ����������
	
	zero.Draw();
//������ ���������
	

	MyMap ����;

	����.insert(pair<char*, int>("����� 1.0", 420));
	����.insert(pair<char*, int>("����� 1.0", 230));
	����.insert(pair<char*, int>("������ 1.0", 140));
	����.insert(pair<char*, int>("������� 1.0", 350));
	cout<<zero.size();
cout << endl << "������� �������� �������" << endl;
	int n_0;
	cin >> n_0;
	cout << endl;
	cout << endl << "������� ���������� ��������� ���������" << endl;
	int n;
	cin >> n;
	cout << endl;
	zero.Erase_between(n_0,n);
	zero.Swap(zero,����);
	zero.Draw();

	����.Draw();

	

}