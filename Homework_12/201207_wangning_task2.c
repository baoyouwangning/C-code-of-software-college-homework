/*
	���ܣ�ʹ����������
	���ߣ�wangning
	���ڣ�2013-6-23
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *phoneNumber = NULL;
	short i;

	//���ٿռ�
	phoneNumber = (char *) malloc(sizeof(char) * 15);  //����15λ��ֹ�û�����λ������11

	//�����û�����
	printf("�������ֻ��ţ�");
	do
	{
		gets(phoneNumber);
		//��ʼ�ж�
		if(1)
		{
			for( i = 0; phoneNumber[i] != 0; i++)
			{
				if( phoneNumber[i] <= '0' && phoneNumber[i] >= '9' )
					printf("���ֺ��벻�ܺ��з������ַ���");
					break;
			}
		}
		else if( phoneNumber[10] = 0)
	

		printf("���������룺");
	}while(1);

	//�ͷſռ�
	free(phoneNumber);

	system("pause");
	return 0;
}