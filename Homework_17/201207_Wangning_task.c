/*
	���ܣ�����
	���ߣ�wangning
	���ڣ�2013-7-9
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
	
	//�Զ���ѧ������
	printf("������ѧ��������");
	scanf("%d",&count);

	//���ٿռ�
	p = (STU *)malloc(sizeof(STU) * count);

	//�����û�����
	for(i = 0; i <= count - 1; i++)
	{
		printf("���Դ�����ѧ�� %d �������ͳɼ����Կո�������� ",i+1);
		scanf("%s %d",p[i].name,&(p[i].score));
	}

	//��ʾ�û�ѡ��
	printf("�����б�\n");
	printf("����1������\n");
	printf("����2������\n");
	printf("����3�����Ҳ��޸�\n");
	printf("��ѡ��1-3����");
	scanf("%d",&choose);
	
	//��ʼ����
	switch(choose)
	{
	case 1:

		//���ú���
		sort(p,count);
		break;
	case 2:

		//��ʾ�û�����
		printf("������Ҫ��ѯ��ѧ��������");
		scanf("%s",&findStudent);
		
		//���ú���
		finded = find(p,count,findStudent);
		
		//��ӡ���
		if(finded)	printf("%s�ĳɼ�Ϊ %d\n",findStudent,finded->score);
		else printf("δ�ҵ�ѧ��%s\n",findStudent);
		break;
	case 3:
		//�����û�����
		printf("������Ҫ���ҵ�ѧ���������µĳɼ����Զ��Ÿ�������");
		scanf("%s%d",reNew.name,&(reNew.score));

		printf("%d\n",reNew.score);
		//���ú���
		if( findAndEdit(p,count,reNew.name,reNew.score == 1) )	printf("�޸ĳɹ�!ѧ�� %s ���³ɼ�Ϊ %d\n",reNew.name,reNew.score);
		else printf("δ�ҵ�ѧ�� %s !\n",reNew.name);
		break;
	}

	
	//������µĽ��
	printf("���е�ѧ����ϢΪ��\n");
	for(i = 0; i <= count - 1;i++)
	{
		printf("%s %d\n",p[i].name,p[i].score);
	}
	system("pause");
	return 0;

}