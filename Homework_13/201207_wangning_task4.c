/*
	���ܣ��������Լ����С������
	���ߣ�wangning
	���ڣ�2013-6-24
*/
#include <stdio.h>
#include <stdlib.h>

//�������Լ������
int  greatestCommonDivisor(int x,int y)
{
	if(y == 0) return x;
	else return greatestCommonDivisor(y,x%y);
}

//������С����������
int leastCommonMultiple(int x,int y)
{
	return x * y / greatestCommonDivisor(x,y);
}

int main(void)
{
	int a,b;

	//��ʾ�û�����
	printf("����������������(�Կո����)��");
	scanf("%d %d",&a,&b);

	//���ú���
	printf("�����������Լ���ǣ�%d\n",greatestCommonDivisor(a,b));
	printf("����������С�������ǣ�%d\n",leastCommonMultiple(a,b));

	system("pause");
	return 0;
}