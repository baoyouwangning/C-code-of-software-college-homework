/*
	���ܣ�����ṹ��ͼ�������ԭ��
	���ߣ�wangning
	���ڣ�2013-7-9
*/
typedef struct student
{
	char name[20];
	int score;
}STU;

//task1.����
void sort(STU *aStu, int n);

//task2.����
STU *find(STU *aStu,int n,char *aName);

//task3.���Ҳ��޸�
int findAndEdit(STU *aStu,int n,char *aName,int aScore);