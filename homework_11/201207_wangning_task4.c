/*
	���ܣ����ݼ���
	���ߣ�wangning
	���ڣ�2013-6-19
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	short i,j;  //�±�
	int Data[4];
	int swap;		//�����ռ�

	//�����û�����
	printf("������һ�����(�ĸ�)��");
	scanf_s("%d %d %d %d",&Data[0],&Data[1],&Data[2],&Data[3]);

	//��ʼ����
	for(i = 0; i <= 3; i++)
		Data[i] = (Data[i] + 5) % 10;
	
	swap = Data[0];
	Data[0] = Data[3];
	Data[3] = swap;
	swap = Data[1];
	Data[1] = Data[2];
	Data[2] = swap;
	
	

	//������ܺ�ĺ���
	printf("��ī��ĺ���Ϊ��");
	for(i = 0; i <= 3; i++)
		printf("%d ",Data[i]);
	printf("\n");
	
	system("pause");
	return 0;
}