/*
	���ܣ���������ʵ��
	���ߣ�wangning
	���ڣ�2013-7-9
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "homework17.h"

//task1.����
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

//task2.����
STU *find(STU *aStu,int n,char *aName)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if( strcmp(aStu[i].name,aName) == 0)	return &aStu[i];
	}
	return 0;
}

//task3.���Ҳ��޸�
int findAndEdit(STU *aStu,int n,char *aName,int aScore)
{
	STU *finded = 0;
	
	//�������еĲ��Һ���
	finded = find(aStu,n,aName);

	printf("%d",finded->score);
	//��ʼ�޸�
	if(finded)
	{
		finded->score = aScore;
		printf("%d",finded->score);
		return 1;
	}
	else return 0;
}
