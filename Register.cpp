#include "link.h"
#include <iostream>
#include <fstream>
#include <cstring>
ifstream fin;  //��ȡ�ļ�
ofstream fout; //д���ļ�

int Register()
{
	char username[50];
	char password[50];
	string temp;
	int i = 0, flag = 0;

	fin.open("./Register.txt", ios::in); //�����ļ����ڸ�·�������ļ�����ѯ��     //�����Ų��ܴ����ַ�
	fout.open("./Register.txt", ios::app); //д���ļ�

		cout << " �������û��������룺" << endl;
		cin >> username;
		cin >> password;

		while (getline(fin, temp)) //�Ѷ���һ�е���Ϣ�浽������
		{
			i++;
			if (i % 2 == 0)continue;//���������û���������
			if (strcmp(username, temp.c_str()) == 0) //�洢������ĺ��������ͬ
				flag = 1; //�ѱ�ע��
		}
		fin.close();
		if (flag)
		{
			cout << "�ѱ�ע�ᣡ" << endl;
			Register();
			return 0;
		}
		else
		{
			fout << username << endl;
			fout << password << endl;
			while (!fin.eof())
			{
				strcpy(info.UserName, username); //��������û�������ṹ��
				strcpy(info.PassWord, password);
			}
			cout << "ע��ɹ���" << endl;
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
	
		cout << "�������û��������룺" << endl;
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
			cout << "��¼�ɹ���" << endl;
			return 1;
			

		}
		else
		{
			cout << "�û������������,���������룡" << endl;
			Login();
			return 0;
		}
	}



