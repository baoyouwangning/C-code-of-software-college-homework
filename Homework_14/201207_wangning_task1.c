/*
	���ܣ�Ѱ���Ǿ�
	���ߣ�wangning
	���ڣ�2013-6-25
*/
#include <stdio.h>
#include <stdlib.h>

#define length 8

void findSecondMax(int *p,const int len)
{
	/*˼·���������ֵ��Ȼ�����ҵڶ���ֵ���������ֵ���±�������*/
	int i;	//���Ʋ���ѭ������
	int j;   //�±�����
	int max = 0;  //��¼���ֵ�±�
	int max_second = 1;  //��¼�ڶ���ֵС��,��ʼֵΪ 1 ��ֹ����һ�������ʱ��Ӱ��ڶ���ֵ���ж�
	
	//�����ҵڶ���ֵ
	for(i = 0; i <= 1 ; i++)
	{
		for(j = 0; j < len; j++)
		{
			if(i == 0)			//��һ�������ֵ�±�
				if(p[j] > p[max])
					max = j;
			if(i == 1)			//�ڶ��˲��Ҵδ�Ԫ���±�
			{
				if(p[j] == p[max])		//�������ֵ
					continue;
				else if( p[j] >= p[max_second])  
					max_second = j;			//�õ������ִδ�Ԫ�ص��±�
			}
		}
	}

	//�����ҵڶ���ֵ���±�,�ӵ�ǰ�� max_second �±괦��ʼ����
	printf("�δ�Ԫ�أ�%d�����±��ǣ�",p[max_second]);
	for(i = 0; i <= max_second; i++)
	{
		
		if(i == max_second)
			printf("%d",max_second);
		else if(p[i] == p[max_second])
				printf("%d��",i);
	}
	printf("\n");
	
	system("pause");
	exit(0);
}

int main()
{
	int a[length];

	//�����û�����
	printf("һά�����е�Ԫ���ǣ�");
	scanf("%d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7]);

	//���ú���
	findSecondMax(a,length);
}