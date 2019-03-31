#include "link.h"
#include <iostream>
using namespace std;
Magazine maxn;
void Sort_price() //按杂志价格从高到低排序
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
			if (maga.magazine[i].id > maga.magazine[j].id) //升序
			{
				maxn = maga.magazine[i];
				maga.magazine[i] = maga.magazine[j];
				maga.magazine[j] = maxn;
			}
		}
	}
}