/*
	���ܣ��������
	������wangning
	���ڣ�2013-6-27
*/
#include <stdio.h>
#include <stdlib.h>

#define len 5

//�ݹ�������亯��
int Process(int *person,int i)
{
	
	if(i == 0) return person[i] = 10;				  //�ݹ��������
	return person[i] =  Process(person,i - 1) + 2;	//����Ϊ2
}

int main(void)
{
	int p[len];    //���ڴ��5���˵�����

	//���ú���
	Process(p,len-1);

	printf("������˵�����Ϊ��%d\n",p[4]);
	
	system("pause");
	return 0;
}