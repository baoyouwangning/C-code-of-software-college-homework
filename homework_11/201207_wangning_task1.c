/*
	���ܣ�����˷�(�ɽ����û��Զ���ľ���������)
	���ߣ�Wangning
	���ڣ�2013-6-11
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	short row,common,col;		//����A,B������,common=����A����=����B����
	short i,j,k;				  //�±������
	float **a = NULL;
	float **b = NULL;
	float **c = NULL;

	//��ʾ�û��Զ������������
	printf("���������A����������");
	scanf("%hd %hd",&row,&common);
	printf("���������B��������");
	scanf("%hd",&col);

	//�ٶ������ٿռ�
		//����A
	a = (float **)malloc(sizeof(a) * row);  //row������ָ��(����A������)
	for ( i = 0; i <= row - 1; i++)
	{
		a[i] = (float *)malloc(sizeof(float) * common);		//common��һ��ָ��(����A������)
	}
		//����B
	b = (float **)malloc(sizeof(b) * common);  //common������ָ��(����B������)
	for ( i = 0; i <= common - 1; i++)
	{
		b[i] = (float *)malloc(sizeof(float) * col);		//common��һ��ָ��(����A������)
	}

	c = (float **)malloc(sizeof(c) * row);     //row������ָ��(����C������)
	for (i = 0; i <= row - 1; i++)
	{
		c[i] = (float *)malloc(sizeof(float) * col);	 //col��һ��ָ��(����C������)
	}
	//�Ծ���C���г�ʼ��
	for (i = 0; i <= row - 1; i++)
		for (j = 0; j <= col - 1; j++)
			c[i][j] = 0;


	//�����û�����
		//����A
	printf("\n����A��\n");
	for (i = 0; i <= row - 1; i++)
	{
		printf("�������%d�У�\n",i + 1);
		for (j = 0; j <= common - 1; j++)
		{
			printf("��%d������",j + 1);
			scanf("%f",&a[i][j]);
		}
	}
		//����B
	printf("\n����B��\n");
	for(i = 0; i <= common - 1; i++)
	{
		printf("�������%d�У�\n",i + 1);
		for( j = 0; j <= col - 1; j++)
		{
			printf("��%d������",j + 1);
			scanf("%f",&b[i][j]);
		}
	}

	//��ӡ������˵ľ���
		//����A
	printf("\n\n");
	for (i = 0; i <= row - 1; i++)
	{
		if( i == row/2 )
			printf("����A=");
		printf("\t|");
		for(j = 0; j <= common - 1; j++)
		{
					
			printf("%g ",a[i][j]);		
		}
		printf("\b|\n");
	}
	printf("\n\n");
	for (i = 0 ; i <= common - 1; i++)
	{
		if( i == common/2 )
			printf("����B=");
		printf("\t|");
		for(j = 0; j <= col - 1; j++)
		{
					
			printf("%g ",b[i][j]);		
		}
		printf("\b|\n");
	}

	/*��ʼ����:
	˼·��
		1.���ٿռ���ʼ��C[row][col] = {0}
		2.�Ƚ�����A�ĵ�һ�еĵ�һ�������γ��Ͼ���B�ĵ�һ�е�ÿ����,���������C�Ķ�Ӧλ��
		3.Ȼ���ٽ�����A�ĵ�һ�еĵڶ��������γ��Ͼ���B�ĵڶ��е�ÿ����,���������C�Ķ�Ӧλ��
		4.����A�ĵ�һ�еĵ�n����ͬ��
		4.Ȼ���ٽ�����A�ĵڶ��еĵ�һ�������γ��Ͼ���B�ĵ�һ�е�ÿ����,�����Ͼ���C��Ӧλ�õ�����ֵ
		5.����ͬ��(�ظ�2,3,4)
	*/
	for(i=0;i<=row - 1;i++)			//����A����,������C����
		for(j=0;j<=common - 1;j++)    //����A����
			for(k=0;k<col;k++)		//����B����,������C����
				c[i][k] += a[i][j] * b[j][k];		//����C��ÿ��λ���ۼ�

	
	//����˻�����C
	printf("\n\n");
	for (i = 0 ; i <= row - 1; i++)
	{
		if( i == row/2 )
			printf("�˻�����C=\t|");
		else
		{
			printf("\t\t|");
		}	
		for(j = 0; j <= col - 1; j++)
		{			
			printf("%g ",c[i][j]);		
		}
		printf("\b|\n");
	}
	
	//�ͷ��ڴ�ռ�
	for ( i = 0; i <= row - 1; i++)
		free(a[i]);
	free(a);
	for ( i = 0; i <= common - 1; i++)
		free(b[i]);
	free(b);
	for ( i = 0; i <= row - 1; i++)
		free(c[i]);
	free(c);

	system("pause");
	return 0;	
}