#ifndef MAGAZINE_SYSTEM_H
#define MAGAZINE_SYSTEM_H  //����ͷ�ļ��Ƿ񱻰���
#include<string>
using namespace std;
/*�ṹ�嶨��*/
//�û���Ϣ
struct UserInfo
{
	char UserName[50];
	char PassWord[50];
};
extern UserInfo info;


 //��־��Ϣ
struct Magazine//һ����־�Ķ���
{
	string id;
	string name;
	string varity;  //�������
	double price;
	int flag = 0; //no subscribe
};
typedef struct //���崢����־�ľ�̬����
{
	Magazine magazine[300]; //�����־������  magazine[i]��ʾ��i����־
	int len; //��ǰ��־������
}MAGA;
extern MAGA maga;



//�����Ķ�����Ϣ
typedef struct node
{
	char username[100];//�û���
	int id;  //��־���
	int count; //��־����
	double total_cost; //�ܽ��
	struct node *next;  //ָ����
}sub;



/*��������*/

//ע���¼
int Register();
int Login();
//��ͬ��ɫ�Ĳ˵���ʾ
void Admin();
void Subscriber();
void Tourist();
//����Ա�Ĳ���
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
//�����Ĳ���
sub *Create();//����������Ϣ
void sub_Delete(sub *head);//����Ա
void name_Search(sub *head);//��ѯ������Ϣ


void maga_num();
#endif




