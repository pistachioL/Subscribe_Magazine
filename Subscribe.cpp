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
	cout << "请输入订阅信息，按0结束" << endl;
	cout << "请输入要订阅的杂志编号" << endl;
	cin >> num;
	
	while (num != 0)
	{
		p = (sub *)malloc(sizeof(sub));
		p->id = num;
		cout << "请输入你的姓名" << endl;
		cin >> p->username;
		cout << "请输入杂志数量 " << endl;
		cin >> p->count;
		cout << "请输入订阅总金额" << endl;
		cin >> p->total_cost;
			
		p->next = NULL;   //后插
		q->next = p;
		q = p;
		cout << "订阅成功！" << endl;
		maga.len--;
		cout << "是否继续订阅? 是则输入杂志编号，否则按0" << endl;
		cin >> num;

	}
	return head;
}


void sub_Delete(sub *head)
{
	sub *p, *q;
	p = head;
	q = head->next;
	printf("请输入你要删除的杂志编号：");
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
		cout << "找不到该订阅信息。" << endl;
	}

}

/*订阅信息查询*/
void name_Search(sub *head)
{
	sub *p;
	char user[100];
	cout << "请输入你的用户名:" << endl;
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
		cout << "没有该用户" << endl;
	}
	else
	{

		printf("用户名\t杂志编号\t杂志数数量\t总金额\n");
		printf("%-15s %-15d %-15d %-15f\n", p->username, p->id, p->count, p->total_cost);
	}
}





