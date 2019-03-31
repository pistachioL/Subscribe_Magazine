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




void ClearNextLine(char *s) //清除换行符
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


void import()  //杂志信息(txt)导入结构体数组
{
	fstream in;
	//maga.len = 0;
	string s;
	//in.open("./Magazine_info.txt", ios::in);  //文件数据输入到内存 in读取文件内容
	FILE *fp;
	char filename[100] = "./Magazine_info.txt";

	if ((fp = fopen(filename, "r")) == NULL)
	{
		cout << "没有录入信息，可能文件不存在。" << endl;
	}
	else
	{
		while (!feof(fp))
		{
			char temp[300];
			fgets(temp, sizeof(temp) - 1, fp);//读取文件到temp字符数组中
			ClearNextLine(temp);
			maga.len++;
			const char *blank = " ";
			char* id_str = strtok(temp, " ");
			char* name_str = strtok(NULL, " ");// name_str用来存储姓名
			char* varity_str = strtok(NULL, " ");
			char* price_str = strtok(NULL, " ");
			if (id_str != NULL && name_str != NULL && varity_str != NULL && price_str != NULL)
			{
				//char转string (通过调用string构造函数)
				string Id(id_str);	
				maga.magazine[maga.len].id = Id;
				//char转string
				maga.magazine[maga.len].name = name_str;
				string Varity(varity_str);
				maga.magazine[maga.len].varity = Varity;
				//char转double
				maga.magazine[maga.len].price = CharConvertDouble(price_str);
			}


		}
		cout << "信息已录入！" << endl;
		cout << endl;
	}
	fclose(fp);


}

void Search_All_Maga()//浏览全部杂志(从结构体)
{
	int i;
	cout << endl;
	cout << "请选择查询方式：1.按价格降序排列 2.按杂志编号升序排列" << endl;
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
	cout << left << setw(15) << "杂志编号" << left << setw(22) << "杂志名字"
		<< left << setw(15) << "杂志种类" << left << setw(15) << "杂志价格" << endl;
	for (int i = 1;i <= maga.len;i++)
	{
		cout << left << setw(15) << StringConverInt(maga.magazine[i].id) << left << setw(22) << maga.magazine[i].name
			<< left << setw(15) << maga.magazine[i].varity << left << setw(15)  << maga.magazine[i].price << endl;
	}
}


int Search_By_Name()  //按某一字段查找杂志
{
	int i, j;
	cout << "请输入要查询杂志的名字：" << endl;
	string names;
	cin >> names;
	for (i = 1;i <= maga.len;i++)
	{
		if (maga.magazine[i].name == names)
			break;
	}
	if (i > maga.len)
	{
		cout << "找不到该杂志！" << endl;
		return 0;
	}
	else
	{
		cout << names << "的编号是：" << StringConverInt(maga.magazine[i].id) << endl;
		cout << "种类是：" << maga.magazine[i].varity << endl;
		cout << "价格是：" << maga.magazine[i].price << endl;
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
	int n = CountLines(); //文本行数
	
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
		cout << "文件打开失败" << endl;
		return;
	}
		do {
			write << '\n';
			n++;
			maga.len = n;
			maga.magazine[maga.len].id = IntConverString(n);
			write << n << '\t';

			cout << "请输入增加的杂志名字" << endl;
			cin >> names;
			maga.magazine[maga.len].name = names;
			write << names << '\t';

			cout << "请输入增加的杂志种类" << endl;
			cin >> varities;
			maga.magazine[maga.len].varity = varities;
			write << varities << '\t';

			cout << "请输入增加的杂志价格：" << endl;
			cin >> prices;
			maga.magazine[maga.len].price = prices;
			write << prices << '\t';

		
			cout << "添加成功！" << endl;
			cout << "杂志有" << n << "本" << endl;
			cout << "是否继续添加？（Y/N）" << endl;
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
	cout << "请输入要删除杂志的名字：" << endl;
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
		cout << "查无此杂志" << endl;
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
		cout << "删除成功！" << endl;   //有bug
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
	cout << "请输入你要更新的杂志名字：" << endl;
	cin >> name;
	for (i = 1;i <= maga.len;i++)
	{
		if (maga.magazine[i].name == name)
			break;
	}
	if (i > maga.len)
	{
		cout << "找不到该杂志。" << endl;
		return 0;
	}
	else
	{
		cout << "1. 修改杂志名字" << endl;
		cout << "2. 修改杂志种类" << endl;
		cout << "3. 修改杂志价格" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "请输入新杂志的名字" << endl;
			cin >> name; 
			maga.magazine[i].name = name;
			fout << name;
			break;

		case 2:
			cout << "请输入杂志的新种类：" << endl;
			cin >> varities;
			maga.magazine[i].varity = varities;
			fout << varities;
			break;

		case 3: cout << "请输入新杂志的价格：" << endl;
			cin >> prices;
			maga.magazine[i].price = prices;
			fout << prices;
			break;
		}
		cout << "更新成功！" << endl;
	}

	return 1;


}
void maga_num()
{
	int n = CountLines();
	cout << "现在杂志数量为" << n << endl;
	
}




