/*
	���ܣ��ֻ�����֤(�д�������ȼ����з������ַ� > ���Ȳ��� > ����̫�� > û���������ֻ���)
	���ߣ�wangning
	���ڣ�2013-6-23
*/

#include <stdio.h>
#include <stdlib.h>

#define notDigital 1

int main(void)
{
	char *phoneNumber = NULL;
	short i = 0;
	short flag = 0;
	short j = 0;   //������

	//���ٿռ�
	phoneNumber = (char *) malloc(sizeof(char) * 15);  //����15λ��ֹ�û�����λ������11

	//�����û�����
	printf("�������ֻ��ţ�");
	do
	{
		gets(phoneNumber);
		
		//��ʼ�ж�
		for( i = 0; phoneNumber[i] != 0; i++)
			{
				//��¼�Ƿ��з�����
				if( phoneNumber[i] < '0' || phoneNumber[i] > '9' )
				{
					flag = notDigital;
				}
				//��¼�ַ�������
				if( phoneNumber[i] != 0) j++;
			}
		if( flag == notDigital) printf("\n���ֺ��벻�ܺ��з������ַ���");
			
		else if( j < 11) printf("\n�ֻ����볤��С��11��");   

		else if( j > 11) printf("\n�ֻ����볤�ȴ���11,");  

		//��¼�ֻ����Ƿ���Ч
		else if( phoneNumber[0] != '1' || phoneNumber[1] < '3' || phoneNumber[1] > '5' && phoneNumber[1] != '8' || phoneNumber[2] < '0' || phoneNumber[2] > '9' ) printf("\nû���������ֻ��ţ�");
		//else if( phoneNumber[0] != '1' || phoneNumber[1] != '3' || phoneNumber[1] != '4' || phoneNumber[1] != '5' || phoneNumber[1] != '8' || phoneNumber[2] < '0' || phoneNumber[2] > '9' ) printf("û���������ֻ��ţ�");
		
		//�ж��Ƿ�Ϊ�ƶ��ͻ�
		else if( phoneNumber[1] == '3' && phoneNumber[2] >= '4' && phoneNumber[2] <= '9' || phoneNumber[1] == '4' && phoneNumber[02] == '7' || phoneNumber[1] == '5' && ( phoneNumber[2] >= '0' && phoneNumber[2] <= '2' || phoneNumber[2] >= '7' && phoneNumber[2] <= '9' ) || phoneNumber[1] == '8' && ( phoneNumber[2] == '2' || phoneNumber[2] == '7' || phoneNumber[2] == '8') ) 
		{
			printf("������ѯ��Ϊ�ƶ����롣\n");
			break;
		}
	
		//�ж��Ƿ�Ϊ��ͨ�ͻ�
		else if( phoneNumber[1] == '3' && phoneNumber[2] >= '0' && phoneNumber[2] <= '2' || phoneNumber[1] == '5' && ( phoneNumber[2] == '5' || phoneNumber[2] == '6') || phoneNumber[1] == '8' && ( phoneNumber[2] == '5' || phoneNumber[2] == '6') )
		{
			printf("������ѯ��Ϊ��ͨ���롣\n");
			break;
		}

		//�ж��Ƿ�Ϊ���ſͻ�
		else if( phoneNumber[1] == '3' && phoneNumber[2] == '3' || phoneNumber[1] == '5' && phoneNumber[2] == '3' || phoneNumber[1] == '8' && ( phoneNumber[2] == '0' || phoneNumber[2] == '9' ) )
		{
			printf("������ѯ��Ϊ���ź��롣\n");
			break;
		}
		
			//��ʾ�û��ٴ�����
		flag = 0;
		j = 0;
		printf("���������룺");
	}while(1);

	//�ͷſռ�
	free(phoneNumber);

	system("pause");
	return 0;
}