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
	cout << "\t\t\t 欢迎来到杂志订阅管理系统\t\t\t" << endl;
	cout << "\t\t\t**************************\t\t" << endl;

	cout << "\t请输入您的身份：1.管理员     2.订户     3.游客	 " << endl;
	cin >> role;
	if (role == 1)  //管理员
	{

		maga.len = 0;
		string user, password;
		cout << "请输入用户名和密码：" << endl;
		cin >> user >> password;
		if (user == "root" && password == "root")
		{
			cout << "欢迎回来！" << endl;
			import();
			Admin();
		}

	}
	else if (role == 2)  //订户
	{

		cout << "亲爱的订户，请先注册登录：" << endl;
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

