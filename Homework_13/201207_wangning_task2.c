/*
	���ܣ�����ת��
	���ߣ�wangning
	���ڣ�2013-6-23
*/
#include <stdio.h>
#include <stdlib.h>

void Process(int x)
{
	if( (x/2) != 0) Process(x/2);	
	printf("%d",x % 2);
}


int main(void)
{
	int num;

	//�����û�����
	printf("������һ��ʮ����������");
	scanf("%d",&num);

	//������
	printf("��ʮ���������Ķ����Ʊ�ʾΪ��");
	Process(num);

	printf("\n");
	system("pause");
	return 0;
}