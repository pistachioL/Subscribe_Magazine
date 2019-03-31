#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "link.h"
#include <sstream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;




void ClearNextLine(char *s) //������з�
{
	char *find = strchr(s, '\n');
	if (find)
	{
		*find = '\0';
	}
}
	
int StringConverInt(string s)
{
	stringstream stream;
	stream << s;
	int k;
	stream >> k;
	return k;
}

string IntConverString(int s)
{
	stringstream stream;
	stream << s;
	string k;
	stream >> k;
	return k;
}

double CharConvertDouble(string ch)
{
	stringstream stream;
	stream << ch;
	double d;
	stream >> d;
	return d;
}
int CharConvertInt(char *j)
{
	stringstream stream;
	int i;
	stream << j;
	stream >> i;
	return i;
}


void import()  //��־��Ϣ(txt)����ṹ������
{
	fstream in;
	//maga.len = 0;
	string s;
	//in.open("./Magazine_info.txt", ios::in);  //�ļ��������뵽�ڴ� in��ȡ�ļ�����
	FILE *fp;
	char filename[100] = "./Magazine_info.txt";

	if ((fp = fopen(filename, "r")) == NULL)
	{
		cout << "û��¼����Ϣ�������ļ������ڡ�" << endl;
	}
	else
	{
		while (!feof(fp))
		{
			char temp[300];
			fgets(temp, sizeof(temp) - 1, fp);//��ȡ�ļ���temp�ַ�������
			ClearNextLine(temp);
			maga.len++;
			const char *blank = " ";
			char* id_str = strtok(temp, " ");
			char* name_str = strtok(NULL, " ");// name_str�����洢����
			char* varity_str = strtok(NULL, " ");
			char* price_str = strtok(NULL, " ");
			if (id_str != NULL && name_str != NULL && varity_str != NULL && price_str != NULL)
			{
				//charתstring (ͨ������string���캯��)
				string Id(id_str);	
				maga.magazine[maga.len].id = Id;
				//charתstring
				maga.magazine[maga.len].name = name_str;
				string Varity(varity_str);
				maga.magazine[maga.len].varity = Varity;
				//charתdouble
				maga.magazine[maga.len].price = CharConvertDouble(price_str);
			}


		}
		cout << "��Ϣ��¼�룡" << endl;
		cout << endl;
	}
	fclose(fp);


}

void Search_All_Maga()//���ȫ����־(�ӽṹ��)
{
	int i;
	cout << endl;
	cout << "��ѡ���ѯ��ʽ��1.���۸������� 2.����־�����������" << endl;
	int flag;
	cin >> flag;
	switch (flag)
	{
	case 1:
		//Sort_price();
		break;
	case 2:
		//Sort_id();
		break;
	}
	cout << left << setw(15) << "��־���" << left << setw(22) << "��־����"
		<< left << setw(15) << "��־����" << left << setw(15) << "��־�۸�" << endl;
	for (int i = 1;i <= maga.len;i++)
	{
		cout << left << setw(15) << StringConverInt(maga.magazine[i].id) << left << setw(22) << maga.magazine[i].name
			<< left << setw(15) << maga.magazine[i].varity << left << setw(15)  << maga.magazine[i].price << endl;
	}
}


int Search_By_Name()  //��ĳһ�ֶβ�����־
{
	int i, j;
	cout << "������Ҫ��ѯ��־�����֣�" << endl;
	string names;
	cin >> names;
	for (i = 1;i <= maga.len;i++)
	{
		if (maga.magazine[i].name == names)
			break;
	}
	if (i > maga.len)
	{
		cout << "�Ҳ�������־��" << endl;
		return 0;
	}
	else
	{
		cout << names << "�ı���ǣ�" << StringConverInt(maga.magazine[i].id) << endl;
		cout << "�����ǣ�" << maga.magazine[i].varity << endl;
		cout << "�۸��ǣ�" << maga.magazine[i].price << endl;
		return 1;
	}
	
}
int CountLines()
{
	ifstream read;
	int n=0;
	read.open("./Magazine_info.txt", ios::in);
	char file[1000];
	while (!read.eof())
	{
		read.getline(file, sizeof(file) - 1, '\n');
		n++;
	}
	return n;
}

void Insert()
{
	int n = CountLines(); //�ı�����
	
	cout << endl;
	//ifstream read;
	ofstream write;
	string names, varities;
	double prices;
	char temp[300],ch;

//	read.open("./Magazine_info.txt", ios::in);
	write.open("./Magazine_info.txt", ios::app);
	if (write.fail())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
		do {
			write << '\n';
			n++;
			maga.len = n;
			maga.magazine[maga.len].id = IntConverString(n);
			write << n << '\t';

			cout << "���������ӵ���־����" << endl;
			cin >> names;
			maga.magazine[maga.len].name = names;
			write << names << '\t';

			cout << "���������ӵ���־����" << endl;
			cin >> varities;
			maga.magazine[maga.len].varity = varities;
			write << varities << '\t';

			cout << "���������ӵ���־�۸�" << endl;
			cin >> prices;
			maga.magazine[maga.len].price = prices;
			write << prices << '\t';

		
			cout << "��ӳɹ���" << endl;
			cout << "��־��" << n << "��" << endl;
			cout << "�Ƿ������ӣ���Y/N��" << endl;
			cin >> ch;
			if(ch=='N')
			{
				Admin();  
				break;
			}
		} while (ch == 'Y');
		write.close();	
}


int Delete()
{
	ifstream read;
	ofstream write;
	read.open("./Magazine_info.txt");
	int i, j,flag=0;
	string name;
	cout << "������Ҫɾ����־�����֣�" << endl;
	cin >> name;
	for (i = 1;i <= maga.len;i++)
	{
		if (maga.magazine[i].name == name)
		{
			flag = 1;
			break;
		}

	}
	if (i > maga.len)
	{
		cout << "���޴���־" << endl;
		return 0;
	}
		
	else
	{
		for (j = i + 1;j <= maga.len;j++)
		{
			/*maga.magazine[i - 1].name = maga.magazine[i].name;
			maga.magazine[i - 1].varity = maga.magazine[i].varity;
			maga.magazine[i - 1].price = maga.magazine[i].price;*/
			maga.magazine[i - 1] = maga.magazine[i];

		}
		string blank = "";
		if (flag)
		{
			blank += '\n';
			write << blank;
			write.close();
		}
		
		maga.len--;
		cout << "ɾ���ɹ���" << endl;   //��bug
		return 1;
	}
}


int Update()
{
	ifstream fin;
	ofstream fout;
	fin.open("./Magazine_info.txt", ios::in);
	fout.open("./Magazine_info.txt", ios::app);
	int i, j;
	string name;
	string varities;
	double prices;
	cout << "��������Ҫ���µ���־���֣�" << endl;
	cin >> name;
	for (i = 1;i <= maga.len;i++)
	{
		if (maga.magazine[i].name == name)
			break;
	}
	if (i > maga.len)
	{
		cout << "�Ҳ�������־��" << endl;
		return 0;
	}
	else
	{
		cout << "1. �޸���־����" << endl;
		cout << "2. �޸���־����" << endl;
		cout << "3. �޸���־�۸�" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "����������־������" << endl;
			cin >> name; 
			maga.magazine[i].name = name;
			fout << name;
			break;

		case 2:
			cout << "��������־�������ࣺ" << endl;
			cin >> varities;
			maga.magazine[i].varity = varities;
			fout << varities;
			break;

		case 3: cout << "����������־�ļ۸�" << endl;
			cin >> prices;
			maga.magazine[i].price = prices;
			fout << prices;
			break;
		}
		cout << "���³ɹ���" << endl;
	}

	return 1;


}
void maga_num()
{
	int n = CountLines();
	cout << "������־����Ϊ" << n << endl;
	
}




