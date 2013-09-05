/*
	功能：几个函数实体
	作者：wangning
	日期：2013-7-9
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "homework17.h"

//task1.排序
void sort(STU *aStu, int n)
{
	STU temp;
	int i,j;

	for(i = 0; i <= n - 2; i++)
		for(j = 0; j <= n - 2 - i; j++)
		{
			if(aStu[j].score < aStu[j+1].score)
			{
				strcpy(temp.name,aStu[j+1].name);
				temp.score = aStu[j+1].score;

				strcpy(aStu[j+1].name,aStu[j].name);
				aStu[j+1].score = aStu[j].score;

				strcpy(aStu[j].name,temp.name);
				aStu[j].score = temp.score;
			}
		}
}

//task2.查找
STU *find(STU *aStu,int n,char *aName)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if( strcmp(aStu[i].name,aName) == 0)	return &aStu[i];
	}
	return 0;
}

//task3.查找并修改
int findAndEdit(STU *aStu,int n,char *aName,int aScore)
{
	STU *finded = 0;
	
	//调用已有的查找函数
	finded = find(aStu,n,aName);

	printf("%d",finded->score);
	//开始修改
	if(finded)
	{
		finded->score = aScore;
		printf("%d",finded->score);
		return 1;
	}
	else return 0;
}
