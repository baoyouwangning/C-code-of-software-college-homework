/*
	���ܣ��������(û�н����û��Զ�������鹦��,���ĳ��û��Զ�������,�򻹲����жϴ��������Ե��0����Χ�м���1��ʱ�������д����)
	���ߣ�wangning
	���ڣ�2013-6-28
*/
#include <stdio.h>
#include <stdlib.h>

#define row 8
#define col 8

//�ݹ鴦����
void Process(int *q,int *start,int *end)
{	
	int sum = 0;

	if( q > end) //�ݹ麯����������
	{
		printf("%d",sum);
		system("pause");
		exit(0);
	}
	else if( !*q )      
	{
		sum += *(q-10) + *(q-9) + *(q-8) + *(q-2) + *q + *(q+6) + *(q+7) + *(q+8);
		printf("a[%d][%d] ��Χ�� %d ��1\n",(q-start)/col,(q-start)%col,sum);
	}
	
	Process(++q,start,end);	 //�ݹ�
}

int main(void)
{
	int a[row][col] = { {1,1,1,1,1,1,1,1},{1,1,0,0,1,0,0,1}, {1,0,0,1,0,0,1,1}, {1,1,1,0,0,1,0,1}, {1,0,1,1,1,0,0,1}, {1,1,0,0,0,1,1,1}, {1,1,1,1,0,0,0,1}, {1,1,1,1,1,1,1,1} };
	int *q = &a[0][0];
	int i,j;    
	
	//�����ά����ԭ��
	printf("ԭ���� int a[%d][%d] = \n{\n",row,col);
	for(i = 0; i < row; i++ )
	{
		printf(" {");
		for(j = 0; j < col; j++)
		{
			if(j < col - 1)	printf("%d,",*q++);
			else printf("%d",*q++);
		}
		if( i < row - 1)	printf("},\n");
		else printf("}\n",*q++);	
	}
	printf("}\n");

	//���õݹ麯��
	q = &a[0][0];
	Process(q,q,q+row * col-1);
}