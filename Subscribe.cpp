#include <iostream>
#include <stdio.h>
#include <sstream>
#include <cstring>
#include "link.h"
using namespace std;

sub *Create()
{
	sub *head, *p, *q;
	head = (sub *)malloc(sizeof(sub)); 
	head->next = NULL;
	q = head;
	p = head->next;
	
	int num;
	cout << "�����붩����Ϣ����0����" << endl;
	cout << "������Ҫ���ĵ���־���" << endl;
	cin >> num;
	
	while (num != 0)
	{
		p = (sub *)malloc(sizeof(sub));
		p->id = num;
		cout << "�������������" << endl;
		cin >> p->username;
		cout << "��������־���� " << endl;
		cin >> p->count;
		cout << "�����붩���ܽ��" << endl;
		cin >> p->total_cost;
			
		p->next = NULL;   //���
		q->next = p;
		q = p;
		cout << "���ĳɹ���" << endl;
		maga.len--;
		cout << "�Ƿ��������? ����������־��ţ�����0" << endl;
		cin >> num;

	}
	return head;
}


void sub_Delete(sub *head)
{
	sub *p, *q;
	p = head;
	q = head->next;
	printf("��������Ҫɾ������־��ţ�");
	int num;
	cin >> num;
	while (q != NULL)
	{
		if (q->id = num)
		{
			p->next = q->next;
			free(q);
			q = NULL;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
	if (p == NULL)
	{
		cout << "�Ҳ����ö�����Ϣ��" << endl;
	}

}

/*������Ϣ��ѯ*/
void name_Search(sub *head)
{
	sub *p;
	char user[100];
	cout << "����������û���:" << endl;
	scanf("%s",&user);
	p = head->next;
	while (p != NULL)
	{
	
		if(strcpy(p->username, user))
			break;
		else
			p = p->next;
	}
	if (p == NULL)
	{
		cout << "û�и��û�" << endl;
	}
	else
	{

		printf("�û���\t��־���\t��־������\t�ܽ��\n");
		printf("%-15s %-15d %-15d %-15f\n", p->username, p->id, p->count, p->total_cost);
	}
}





