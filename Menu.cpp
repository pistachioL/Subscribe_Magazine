#include "link.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
using namespace std;
MAGA maga;
UserInfo info;
sub *head;
void Admin()
{
	int flag;
		while (1)
		{
			cout << "\t*********** 请选择你的操作：*****************" << endl;
			cout << "\t\t0.退出	" << "\t\t1.浏览所有杂志 " << endl;
			cout << "\t\t2.更新杂志" << "\t\t3.按杂志名查询" << endl;
			cout << "\t\t4.新增杂志 " << "\t\t5.删除杂志" << endl;
			cout << "\t\t6.修改订户信息" << "\t\t7.删除订户信息" << endl;
			cout << "\t\t8.返回菜单 " << endl;
			cout << "\t*********************************************" << endl;
			cin >> flag;
			switch (flag)
			{
			case 0:
				exit(0);
			case 1:
				import();
				Search_All_Maga();
				break;
			case 2:
				Update();
				break;
				
			case 3:
				import();
				Search_By_Name();
				break;
			case 4:
				Insert();
				break;
			case 5:
				Delete();
				break;
			case 7:
				sub_Delete(head);
				break;
			case 8:
				menu();
				break;
			

			}

		}

	

}


void Subscriber()
{
				cout << "\t*********** 请选择你的操作：*****************" << endl;
				cout << "\t\t0.退出	" << "\t\t1.浏览所有杂志" << left << setw(13) << endl;
				cout << "\t\t2.按杂志名查询" << "\t\t3.增加订阅信息" << endl;
				cout << "\t\t4.查看我的订阅信息" << "\t\t5.返回菜单" << endl;
				cout << "\t*********************************************" << endl;

				int flag;
				cin >> flag;
				switch (flag)
				{
				case 0:
					exit(1);
				case 1:
					import();
					Search_All_Maga();
					break;
				case 2:
					import();
					Search_By_Name();
					break;
				case 3:
					head = Create();
					break;
				case 4:
					name_Search(head);
					break;
				case 5:
					menu();
					break;
			

				}
}


void Tourist()
{
	cout << "请输入你浏览杂志的方式：1.浏览全部杂志；2.通过名字查看杂志;3.返回菜单" << endl;
	int flag;
	cin >> flag;
	switch (flag)
	{
	case 1:
		import();
		Search_All_Maga();
		break;
	case 2:
		import();
		Search_By_Name();
		break;
	case 3:
		menu();
		break;
	case 4:
		void maga_num();
		break;

	}

	return;
}