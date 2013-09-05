/*
	功能：定义结构体和几个函数原型
	作者：wangning
	日期：2013-7-9
*/
typedef struct student
{
	char name[20];
	int score;
}STU;

//task1.排序
void sort(STU *aStu, int n);

//task2.查找
STU *find(STU *aStu,int n,char *aName);

//task3.查找并修改
int findAndEdit(STU *aStu,int n,char *aName,int aScore);