#include "stdafx.h"
#include <iostream>
#include <map>
#include <stack>
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

				cout << mass[i][j] << "    ";
			}
			cout << endl;
	}
};

class MyMap :public map<int, Matrix>
{

public:

	void �����_����������()
	{
		auto it_buf = end();
		auto it_buf_2 = begin();

		it_buf--;
		it_buf_2--;

		for (auto it = it_buf; it != it_buf_2; it--)
		{
		
			
		cout << endl;
			cout << it->first << "    :    ";
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					cout << it->second.mass[i][j] << "  ";
			
		}

	}
	void �������(char *n, int kolvo)
	{
		int *number = new int[kolvo];
		int counter = 0;
		for (int i = 0; i != kolvo; i++)
		{
			number[i] = (int)n[i]-48;
			
		}
		cout << endl;
		for (auto it2 = begin(); it2 != end(); it2++)
		{
			for (int z = 0; z != kolvo; z++)
			{
				if (counter == number[z])
				{
					cout << it2->first<<" : ";
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++)
						{
							cout << it2->second.mass[i][j] << "  ";
						
						}
					cout << endl;
				}
								
			}
		counter++;}
				
	}
	void Sort()
	{
		

		for (auto it_buf=begin(); it_buf != end(); it_buf++)
		{


			cout << endl;
			cout << it_buf->first << "    :    ";
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					cout << it_buf->second.mass[i][j] << "  ";

		}

	}
};

class MyStack : public stack <Matrix>
{
public :
	
	
	
};
void cppout(MyStack &a, MyStack &b)
{
	int counter = 0;
	while (!a.empty())
	{
		
		auto it = a.top();
		b.push(a.top());
		cout << counter << " : ";
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << it.mass[i][j] << "  ";

			}
			cout << endl;
		}
		counter++;
		a.pop();
		cout << endl;
		



	}
	while (!b.empty())
	{
		auto it = b.top();
		a.push(b.top());
		
		b.pop();

	}



}


void Sortirovka(MyStack &a, MyMap &buf)
{
	
	while (!a.empty())
	{
		auto it = a.top();
		int sum = 0; 
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				sum = sum + it.mass[i][j];
			}
		buf.insert(pair<int,Matrix>(sum, it));
		a.pop();
		
	}
	auto it2 = buf.end();
	it2--;
	auto it3 = buf.begin();
	it3--;
	for (it2; it2 != it3; it2--)
	{
		cout << "*"<<it2->first<<"*";
		a.push(it2->second);
	}

}
void Swap(MyMap &swap_map_stack, MyMap &zero, MyStack &new_zero)
{
	int new_counter = 100;
	while (!new_zero.empty())
	{
			auto it = new_zero.top();
			swap_map_stack.insert(pair<int, Matrix>(new_counter, it));
			new_zero.pop();
			new_counter++;

	}

	for (auto it2 = zero.begin(); it2 != zero.end(); it2++)
	{
	
			swap_map_stack.insert(pair<int, Matrix>(it2->first, it2->second));
	}
}

int last_task(int variant, MyMap &swap_map_stack, int task)
{
	int new_new_counter = 0;
	for (auto it2 = swap_map_stack.begin(); it2 != swap_map_stack.end(); it2++)
	{
		int sum = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				sum = sum + it2->second.mass[i][j];
				
			}
		if (variant == 1)
		{
			cout << endl << "� "<<it2->first<<"-��� ����� ��������� �����" << sum << "\n";
		}
		if (sum > task)
		{
			new_new_counter++;
			if (variant == 2)
			{
				for (int i = 0; i < 3; i++)
					for (int j = 0; j < 3; j++)
					{
						cout<<it2->second.mass[i][j]<<" ";

					}
				cout << endl;
			}
		}
	}
	return new_new_counter;
}
void main()
{
	srand(time(NULL));
	system("chcp 1251");

	MyMap zero;
	Matrix ������_��������[4];
	for (int i = 0; i < 4; i++)
	{
		������_��������[i] >> ������_��������[i];
	}
	for (int i = 0; i < 4; i++)
	{
		������_��������[i] << ������_��������[i];
	}
	


	zero.insert(pair<int, Matrix>(1, ������_��������[1]));
	zero.insert(pair<int, Matrix>(0, ������_��������[0]));
	zero.insert(pair<int, Matrix>(3, ������_��������[2]));
	zero.insert(pair<int, Matrix>(2, ������_��������[3]));

	zero.�����_����������();    // ����� �� ��������
	cout << "\n ������� ��������� �� �����? \n";
	int kolvo;
	cin >> kolvo;
	if (kolvo > 0)
	{
		cout << "\n ����� ������� �� �����? \n";
		char *vib = new char[kolvo];
		for (int i = 0; i != kolvo; i++)
		{
			cin >> vib[i];
		}

		cout << "\n/////////////////////////////////////\n";

		cout << "��������� ��������:\n";
		zero.�������(vib, kolvo);  //����� �� �����

		MyStack new_zero;
		MyStack new_hero;
		MyMap buf;

		int *number = new int[kolvo];
		int counter = 0;
		for (int i = 0; i != kolvo+1; i++)
		{
			number[i] = (int)vib[i] - 48;

		}
		cout << endl;
		for (auto it2 = zero.begin(); it2 != zero.end(); it2++)
		{
			for (int z = 0; z != kolvo; z++)
			{
				if (counter == number[z])
				{
					new_zero.push(it2->second);
				}

			}
			counter++;
		}
		
		
		cout << endl << endl;
		cout << "\n/////////////////////////////////////\n";
		cout << "���������� �����:\n";
		cppout(new_zero, new_hero);

		cout << "\n/////////////////////////////////////\n";
		cout << "\n������������:\n";
		cout << "\n������������� map:\n";
		zero.Sort();

		cout << "\n/////////////////////////////////////\n";

		cout << "\n������������� stack:\n";
		Sortirovka(new_zero, buf);
		cout << endl;
		cppout(new_zero, new_hero);


		MyMap swap_map_stack;
		Swap(swap_map_stack, zero, new_zero);
		cout << "\n/////////////////////////////////////\n";
		cout << endl << "������ ��������� (100++ - �������� �����, 0 - 99  - �������� map) : \n";
		swap_map_stack.�����_����������();

		cout << "\n/////////////////////////////////////\n";
		cout << "������� �������� ������ ����� ( ��� ������ � ������, ������� ��������, ����� ��������: \n";
		int task;
		cin >> task;
		cout << "\n ������� " << last_task(1, swap_map_stack, task) << " ��������� �� ������ ����� �����!!!\n";
		last_task(2, swap_map_stack, task);
	}
	
	
}




