/*	
	���ܣ�����Ԫ�ضԽ���֮��(���Զ�������С)
	���ߣ�wangning
	���ڣ�2013-6-19
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	short i,j;         //�±������
	short row,col;
	float **p = NULL; 
	float sum_zhu = 0;
	float sum_fu = 0;


	printf("���������������(�Կո����):");
	scanf("%hd %hd",&row,&col);

	//���ٿռ�
	p = (float **)malloc(sizeof(p) * row);   //��������
	if(p == NULL) 
	{
		printf("û���㹻���ڴ�ռ�!");
		exit(0);
	}
	for(i = 0; i <= row - 1; i++)			//��������
	{
		p[i] = (float *)malloc(sizeof(float) * col);
		if(p[i] == NULL)
		{
			printf("û���㹻���ڴ�ռ�!");
			exit(0);
		}
	}

	//�����û�����
	for(i = 0,j = col-1; i <= row - 1; i++)
		for(j = 0; j <= col - 1; j++)
		{
			printf("�������%d�е�%d�е�����",i+1,j+1);
			scanf("%f",&p[i][j]);
		}

	/*��ʼ����*/	
		//�����Խ���֮��
	for(i = 0; i <= row - 1; i++)
	{
		if( i == 0) j = col - 1;    //j��ʼ��
		for( j = j; j >= 0;)
		{
			sum_zhu += p[i][i];
			sum_fu += p[i][j--];
			break;
		}
	}

		//������Խ���֮��
	printf("���Խ���֮��Ϊ��%g\n",sum_zhu);
		//������Խ���֮��
	printf("���Խ���֮��Ϊ��%g\n",sum_fu);
		




	

	

	//���ԭ����
	printf("�������£�\n");
	for(i = 0; i <= row - 1; i++)
	{
		for(j = 0; j <= col - 1; j++)
		{
			if(j != 0) printf("\t%g",p[i][j]);
			else printf("%g",p[i][j]);		
		}
		printf("\n");
	}


	for(i = 0; i <= row - 1; i++)
		free(p[i]);
	free(p);
	system("pause");
	return 0;
}