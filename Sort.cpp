#include "link.h"
#include <iostream>
using namespace std;
Magazine maxn;
void Sort_price() //����־�۸�Ӹߵ�������
{
	for (int i = 1;i <= maga.len;i++)
	{
		for (int j = i + 1;j <= maga.len;j++)
		{
			if (maga.magazine[i].price > maga.magazine[j].price)
			{
				maxn = maga.magazine[i];
				maga.magazine[i] = maga.magazine[j];
				maga.magazine[j] = maxn;
			}
		}
	}
	
}

void Sort_id()
{
	for (int i = 1;i <= maga.len;i++)
	{
		for (int j = i + 1;j <= maga.len;j++)
		{
			if (maga.magazine[i].id > maga.magazine[j].id) //����
			{
				maxn = maga.magazine[i];
				maga.magazine[i] = maga.magazine[j];
				maga.magazine[j] = maxn;
			}
		}
	}
}