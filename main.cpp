#include "link.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

void menu()
{
	int role;
	maga.len = 0;
	cout << "\t\t\t**************************\t\t" << endl;
	cout << "\t\t\t ��ӭ������־���Ĺ���ϵͳ\t\t\t" << endl;
	cout << "\t\t\t**************************\t\t" << endl;

	cout << "\t������������ݣ�1.����Ա     2.����     3.�ο�	 " << endl;
	cin >> role;
	if (role == 1)  //����Ա
	{

		maga.len = 0;
		string user, password;
		cout << "�������û��������룺" << endl;
		cin >> user >> password;
		if (user == "root" && password == "root")
		{
			cout << "��ӭ������" << endl;
			import();
			Admin();
		}

	}
	else if (role == 2)  //����
	{

		cout << "�װ��Ķ���������ע���¼��" << endl;
		Register();
		Login();
		Subscriber();

		if (Register())
		{
			if (Login())
			{
				while (1)
				{
					Subscriber();
				}
			}
		}
	}
	else
		Tourist();

	return;
}
int main() 
{
	MAGA maga;
	
	menu();
}

