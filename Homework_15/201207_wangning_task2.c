/*
	���ܣ��ַ���ת��������
	���ߣ�wangning
	���ڣ�2013-6-28
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* ת������ */
void StringToInteger(char *str,int *number)
{
	int i = 0;
	int j = 0;
	*number = 0;			//��ʼ����Ϊ�ۼ���׼��

	//�����û����ַ���
	printf("�������ַ�����");
	gets(str);

	//�ҳ��ַ����е�һλ�����ֵ��±�,���ں���10��n�η���
	while( isdigit(str[i++]) );
	
	//��ʼ�ۼӼ���
	for( i -= 2; i >= 0; i--)
	{
		*number += (str[j++] - '0') * pow( (double) 10, i );
	}

	//�����ֵ
	printf("ת��Ϊ����Ϊ��%d\n",*number);

	//�ͷſռ�
	free(str);
	free(number);

	system("pause");
	exit(0);
}

int main(void)
{
	char *ch = NULL;
	int *num = NULL;
	int len;			//�����û��ַ�������

	//��ʾ�û������ַ�������
	printf("������Ҫת�����ַ������ȣ�");
	scanf("%d",&len);
	fflush(stdin);
	
	//���ٿռ�
	ch = (char *)malloc(sizeof(char) * (len+1));
	num = (int *)malloc(sizeof(int) * 1);

	/*���ݲ������ú���*/
	StringToInteger(ch,num);
}