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
			cout << "\t*********** ��ѡ����Ĳ�����*****************" << endl;
			cout << "\t\t0.�˳�	" << "\t\t1.���������־ " << endl;
			cout << "\t\t2.������־" << "\t\t3.����־����ѯ" << endl;
			cout << "\t\t4.������־ " << "\t\t5.ɾ����־" << endl;
			cout << "\t\t6.�޸Ķ�����Ϣ" << "\t\t7.ɾ��������Ϣ" << endl;
			cout << "\t\t8.���ز˵� " << endl;
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
				cout << "\t*********** ��ѡ����Ĳ�����*****************" << endl;
				cout << "\t\t0.�˳�	" << "\t\t1.���������־" << left << setw(13) << endl;
				cout << "\t\t2.����־����ѯ" << "\t\t3.���Ӷ�����Ϣ" << endl;
				cout << "\t\t4.�鿴�ҵĶ�����Ϣ" << "\t\t5.���ز˵�" << endl;
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
	cout << "�������������־�ķ�ʽ��1.���ȫ����־��2.ͨ�����ֲ鿴��־;3.���ز˵�" << endl;
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