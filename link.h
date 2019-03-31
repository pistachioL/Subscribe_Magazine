#ifndef MAGAZINE_SYSTEM_H
#define MAGAZINE_SYSTEM_H  //用于头文件是否被包含
#include<string>
using namespace std;
/*结构体定义*/
//用户信息
struct UserInfo
{
	char UserName[50];
	char PassWord[50];
};
extern UserInfo info;


 //杂志信息
struct Magazine//一本杂志的定义
{
	string id;
	string name;
	string varity;  //书的种类
	double price;
	int flag = 0; //no subscribe
};
typedef struct //定义储存杂志的静态链表
{
	Magazine magazine[300]; //存放杂志的数组  magazine[i]表示第i本杂志
	int len; //当前杂志的数量
}MAGA;
extern MAGA maga;



//订户的订阅信息
typedef struct node
{
	char username[100];//用户名
	int id;  //杂志编号
	int count; //杂志数量
	double total_cost; //总金额
	struct node *next;  //指针域
}sub;



/*函数声明*/

//注册登录
int Register();
int Login();
//不同角色的菜单显示
void Admin();
void Subscriber();
void Tourist();
//管理员的操作
void Insert();
int Delete();
int Update();
int Search_By_Name();
void Search_All_Maga();
void import();
void menu();
void Sort_price();
void Sort_id();
int CountLines();
//订户的操作
sub *Create();//新增订阅信息
void sub_Delete(sub *head);//管理员
void name_Search(sub *head);//查询订阅信息


void maga_num();
#endif




