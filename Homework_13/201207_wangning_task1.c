/*
	���ܣ��������������
	���ߣ�wangning
	���ڣ�2013-6-23
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Process(float a,float b,float c)
{
	if( (a+b) > c && (a+c) > b && (b+c) > a )
	{
		float C;
		C = (a+b+c) / 2;
		return sqrt(C * (C-a) * (C-b) * (C-c));
	}
	else return -1;
}

int main(void)
{
	float x,y,z;

	//��������
	printf("������������(�Կո����)��");
	scanf("%f %f %f",&x,&y,&z);
	
	//���ݲ�����,���ؽ��
	printf("����Χ�ɵ����Ϊ�� S = %g\n",Process(x,y,z));

	system("pause");
	return 0;
}