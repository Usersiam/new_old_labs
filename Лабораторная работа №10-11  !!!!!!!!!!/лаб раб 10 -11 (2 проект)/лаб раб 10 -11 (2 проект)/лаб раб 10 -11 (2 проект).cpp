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
	
	void �����_����������()
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
	//��������
	system("chcp 1251");

	MyMap zero;
	Matrix ������_��������[7];
	for (int i = 0; i < 7; i++)
	{
		������_��������[i] >> ������_��������[i];
	}
	for (int i = 0; i < 7; i++)
	{
		������_��������[i] << ������_��������[i];
	}
	//�������������
	zero.insert(pair<char*, Matrix>("������   ", ������_��������[1]));
	zero.insert(pair<char*, Matrix>("������   ", ������_��������[2]));
	zero.insert(pair<char*, Matrix>("������   ", ������_��������[3]));
	zero.insert(pair<char*, Matrix>("���������", ������_��������[4]));
	zero.insert(pair<char*, Matrix>("�����    ", ������_��������[5]));

	//��������
	cout << endl << endl;
	zero.�����_����������();
	//���������
	zero.erase("�����    ");
	zero.insert(pair<char*, Matrix>("�����2.0", ������_��������[6]));
	zero.at("���������") = ������_��������[3];
	cout << endl << endl;
	zero.�����_����������();

	//������ ���������
	MyMap ����;
	����.insert(pair<char*, Matrix>("������(2)", ������_��������[4]));
	����.insert(pair<char*, Matrix>("������(2)", ������_��������[5]));

	//��������
	cout << endl << endl << "������� ����� ��������� ��������" << endl;
	int n_0;
	cin >> n_0;
	cout << endl<<endl << "������� ���������� ��������� ���������" << endl;
	int n;
	cin >> n;
	cout << endl;
	zero.Erase_between(n_0,n);
	zero.�����_����������();
	cout << endl << endl;
	����.�����_����������();
	cout << endl << endl;
	zero.Swap(zero, ����);
	zero.�����_����������();
	cout << endl << endl;
	����.�����_����������();
	cout << endl << endl;
	

}




