/*
	����:�ַ�������(�ɽ����û��Զ���Ķ���ַ���)
	����:Wangning
	����:2013-6-12
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	short count;
	short length;
	short linkLength;
	short i,j;
	char **p = NULL;
	char *q = NULL;
	int k;

	
	printf("������Ҫ���ӵ��ַ���������");
	scanf("%hd",&count);
	printf("����������ַ������ȣ�");
	scanf("%hd",&length);
	
	//���Ӻ�ĳ���
	linkLength = count * (length + 1) + count;

	//���ٿռ�
	p = (char **)malloc(sizeof(p) * count);
	if(p == NULL) exit(0);
	for (i = 0; i <= count - 1 ; i++)
	{
		p[i] = (char *)malloc( sizeof(char) * (length + 1) );		//���һλ��0
		if(p[i] == NULL) exit(0);
	}
	q = (char *)malloc(sizeof(char) * linkLength );		//�м䲹�ո�,���0
	if( q == NULL) exit(0);
	
	//��ʼ��								//���ó�ʼ��
	//for(i = 0; i <= count - 1 ; i++)
	//	for(j = 0; j <= length; j++)
	//		p[i][j] = 0;	

		//	strcpy(p[i][j],0);			//strcpy��ô�����ã�
	//}
	//for(i = 0; i <= linkLength - 1; i++)
	//{
	//	q[i]= 0;
	//}

	//�����û�����
	getchar();
	for ( i = 0; i <= count - 1; i++)
	{
		printf("�������%d���ַ�����",i);
		//scanf("%s",p[i]);				//problem?
		gets(p[i]);
	}

	//��ʼ����
	k = 0;
	for(i = 0; i <= count - 1; i++)
		for(j = 0; j <= length; j++)   //p[i][length]Ϊ������λ�����������ϵͳ���Զ����㣡
		{
			if( p[i][j] == 0)
			{
				
				if( i != count - 1 )  //����������һ�У���� '/0'���ɿո�break����һ��
				{
					q[k] = ' ';
					k++;	
					break;
				}
				else					//��������һ�У��������
				{
					q[k] = 0;
					break;
				}
			}
			else 
				q[k] = p[i][j];			
			
			k++;	
					//strcpy(*(q++),p[i][j]);   �����õ�ֱ�Ӹ�ֵ��strcpy�������У�
		}

	//������Ӻ���ַ���
	printf("\n�������ӵã� %s\n\n",q);
	
	//�ͷſռ�
	for (i = 0; i < count - 1 ; i++)
	{
		free(p[i]);	
	}
	free(p);
	free(q);

	system("pause");
	return 0;
}