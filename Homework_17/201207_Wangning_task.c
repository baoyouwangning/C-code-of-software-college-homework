/*
	功能：测试
	作者：wangning
	日期：2013-7-9
*/
#include <stdio.h>
#include <stdlib.h>
#include "homework17.h"

int main(void)
{
	int count;
	char findStudent[20];
	STU *finded = 0;
	STU *p=NULL;
	int i,j;
	int choose;
	STU reNew;
	
	//自定义学生个数
	printf("请输入学生个数：");
	scanf("%d",&count);

	//开辟空间
	p = (STU *)malloc(sizeof(STU) * count);

	//接受用户输入
	for(i = 0; i <= count - 1; i++)
	{
		printf("请以此输入学生 %d 的姓名和成绩（以空格隔开）： ",i+1);
		scanf("%s %d",p[i].name,&(p[i].score));
	}

	//提示用户选择
	printf("任务列表：\n");
	printf("任务1：排序\n");
	printf("任务2：查找\n");
	printf("任务3：查找并修改\n");
	printf("请选择（1-3）：");
	scanf("%d",&choose);
	
	//开始处理
	switch(choose)
	{
	case 1:

		//调用函数
		sort(p,count);
		break;
	case 2:

		//提示用户输入
		printf("请输入要查询的学生姓名：");
		scanf("%s",&findStudent);
		
		//调用函数
		finded = find(p,count,findStudent);
		
		//打印结果
		if(finded)	printf("%s的成绩为 %d\n",findStudent,finded->score);
		else printf("未找到学生%s\n",findStudent);
		break;
	case 3:
		//接受用户输入
		printf("请输入要查找的学生姓名和新的成绩（以逗号隔开）：");
		scanf("%s%d",reNew.name,&(reNew.score));

		printf("%d\n",reNew.score);
		//调用函数
		if( findAndEdit(p,count,reNew.name,reNew.score == 1) )	printf("修改成功!学生 %s 的新成绩为 %d\n",reNew.name,reNew.score);
		else printf("未找到学生 %s !\n",reNew.name);
		break;
	}

	
	//输出最新的结果
	printf("所有的学生信息为：\n");
	for(i = 0; i <= count - 1;i++)
	{
		printf("%s %d\n",p[i].name,p[i].score);
	}
	system("pause");
	return 0;

}