/*
	���ܣ������û��Զ�������飬Ȼ����ĿҪ������
	���ߣ�wangning
	���ڣ�2013-6-26
*/
#include <stdio.h>
#include <stdlib.h>

//������СԪ�ص��±�
int findMinIndex(int p[],const int len)
{
	int i;

	int min_i = 0;
	
	//����������Сֵ���±�  
	/*˼·����Ծ������Сֵ���±꣬�������бȵ�ǰ�ı�׼ֵС��������Сֵ�±괦��������*/
	for(i = 0,min_i = 0; min_i < len && i < len; )
	{
		for(i = min_i; i < len ; i++)
		{
			if(p[i] < p[min_i])
			{
				min_i = i;
				break;
			}
		}
	}

	return min_i;
}

//������
void sort(int p[],const int len)
{
	int i;
	int temp;
	int min;

	//�����û�����
	for( i = 0; i < len; i++)
	{
		printf("�������%d��Ԫ�أ�",i+1);
		scanf("%d",&p[i]);
	}
	
	//���ԭʼ״̬������
	printf("����ĳ�ʼ״̬�ǣ�");
	for(i = 0; i < len; i++)
		printf("%d ",p[i]);
	printf("\n");

	//��Ҫ������
	for(i = len; i >= 2; i--)
	{	
		min = findMinIndex(p,i);   //��������Сֵ�±�ĺ���
		temp = p[i-1];
		p[i-1] = p[min];
		p[min] = temp;
	}

	//��������Ľ��
	printf("����������״̬�ǣ�");
	for(i = 0; i < len; i++)
		printf("%d ",p[i]);
	printf("\n");

	system("pause");
	exit(0);
}

int main(void)
{
	int *originalArray = NULL;
	int count;

	//��ʾ�û�����Ԫ�ظ���
	printf("������ԭʼ����Ԫ�ظ���");
	scanf("%d",&count);

	//���ٿռ�
	originalArray = (int *)malloc(sizeof(int) * count);

	//����������
	sort(originalArray,count);
}

