#include "link.h"
#include <iostream>
#include <fstream>
#include <cstring>
ifstream fin;  //读取文件
ofstream fout; //写入文件

int Register()
{
	char username[50];
	char password[50];
	string temp;
	int i = 0, flag = 0;

	fin.open("./Register.txt", ios::in); //关联文件；在该路径读入文件（查询）     //单引号不能存多个字符
	fout.open("./Register.txt", ios::app); //写入文件

		cout << " 请输入用户名和密码：" << endl;
		cin >> username;
		cin >> password;

		while (getline(fin, temp)) //把读入一行的信息存到数组中
		{
			i++;
			if (i % 2 == 0)continue;//限制输入用户名和密码
			if (strcmp(username, temp.c_str()) == 0) //存储在数组的和输入的相同
				flag = 1; //已被注册
		}
		fin.close();
		if (flag)
		{
			cout << "已被注册！" << endl;
			Register();
			return 0;
		}
		else
		{
			fout << username << endl;
			fout << password << endl;
			while (!fin.eof())
			{
				strcpy(info.UserName, username); //把输入的用户名传入结构体
				strcpy(info.PassWord, password);
			}
			cout << "注册成功！" << endl;
			fout.close();
			return 1;


		}
	
	return 1;
}


int Login()
{
	char username[20];
	char password[20];
	string temp1, temp2;
	int nameExist = 0, passwordExist = 0;
	fin.open("./Register.txt", ios::in);
	
		cout << "请输入用户名和密码：" << endl;
		cin >> username;
		cin >> password;
		while (getline(fin, temp1))
		{
			getline(fin, temp2);
			if (strcmp(username, temp1.c_str()) == 0)
			{
				nameExist = 1;
				if (strcmp(password, temp2.c_str()) == 0)
				{
					passwordExist = 1;
					break;
				}
			}
		}
		fin.close();
		if (nameExist == 1 && passwordExist == 1)
		{
			cout << "登录成功！" << endl;
			return 1;
			

		}
		else
		{
			cout << "用户名或密码错误,请重新输入！" << endl;
			Login();
			return 0;
		}
	}



