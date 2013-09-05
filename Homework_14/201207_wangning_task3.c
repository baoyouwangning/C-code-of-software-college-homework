/*
	���ܣ���������
	���ߣ�wangning
	���ڣ�2013-6-26
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// ��Ƶ�����ִ�������±�
int findMxnIndex(int *p,int len)
{
	int i;
	int index = 0;   //Ҫ�����ֵ���±�
	
	for(i = 0; i < len; i++)
	{
		if (p[i] > p[index])
			index = i;
	}
	
	if(p[index] == 0)  //�жϵ�ǰ�±��Ӧ�����Ƶ���Ƿ�Ϊ0���������� ��ͨ�����±��ASCII�����Ƶ��ַ���������û�г���
		return -1;	//���� -1

	p[index] = 0;		 //Ƶ�����㣬��ֹӰ���´��ж�
	return index;
}



/*
	ͳ��Ӣ����ĸ���ֵ�Ƶ��
	˼·���ɴ�д��ĸ��Сд��ĸ��ASCII�� �� ���ÿ���ַ��ĳ���Ƶ�ʵ������±�Ĺ�ϵ�����ۼ�ʵ���ַ�����Ƶ�ʵ�ͳ��
*/
void countFrequency(char *ch,int *frequency)
{
	int i;  //�±�����
	char alphaList[27];   //����26����ĸ���±�����Ƶ����Ӧ
	int maxIndex = 0; 


	//��¼ÿ���ַ����ֵ�Ƶ��
	for(i = 0; ch[i] != 0; i++)
		if( isalpha(ch[i]) )
		{
			if( isupper(ch[i]) ) frequency[ch[i] - 65] += 1;
			if( islower(ch[i]) ) frequency[ch[i] - 97] += 1;
		}

	//�Գ��ֵ�Ƶ����������ÿ�η������ֵ���±꣬ʹalphaList�е��ַ��Ӵ�Сһ�δ��26���ַ�
	for(i = 0; i < 26;i++)
	{
		maxIndex = findMxnIndex(frequency,26);		// ���ò���Ƶ�����ִ�������±�

		//�ж��Ƿ���ֹѭ��(ͨ�����±��ASCII�����Ƶ��ַ���������û�г���)
		if(maxIndex == -1) 
		{
			alphaList[i] = '\0';     //Ϊ��ǰλ�ַ�����ӱ�����������
			break;
		}
		
		//��ʼд���ַ�
		alphaList[i] = maxIndex + 97;				//��Ƶ�������±���ASCII���ϵ�׵�	
	}

	//����������ַ��� ����26ʱ����Ϊԭ������û�г��ֵ��ַ�
	printf("�����ַ�����Ƶ�ʵ��Ⱥ�˳��Ϊ��\n");
	for(i = 0; alphaList[i] != 0; i++)
		printf("%c ",alphaList[i]);
	printf("\n\n");

	/*	
		���������ã� Ӣ����ĸƵ�ʵĴ�С˳��Ϊ��eairtonslcupmdhgbyfvwkxzqj
		����ã�Ӧ�����ĵ�ÿ���ַ�ASCII��ǰ��3λ
	*/

	//��ʼ����
	for(i = 0; ch[i] != 0; i++)
		if( isalpha(ch[i]) )				//�����26��Ӣ����ĸ	
		{
			if( isupper(ch[i]) )			//����Ǵ�д��ĸ
			{
				if( ch[i] <= 'C' && ch[i] >= 'A' )   
				{
					printf("%c",ch[i] + 23);			//��ѭ��
				}
				else
					printf("%c",ch[i] - 3);			//��ASCII��ֱ��ǰ����λ

			}
			if( islower(ch[i]) )			//�����Сд��ĸ
			{
				if( ch[i] <= 'c' && ch[i] >= 'a')
				{
					printf("%c",ch[i] + 23);			//��ѭ��
				}
				else
					printf("%c",ch[i] - 3);			//��ASCII��ֱ��ǰ����λ
			}
		}
		else if(ch[i] == ';' || ch[i] == '.' || ch[i] == ':' || ch[i] == ',')    //����Ǳ�����
		{
			if( isupper(ch[i+1]) || ch[i+1] == '\0' ) printf("%c\n",ch[i]);						//�����һλ�Ǵ�д��ĸ
		}
		else printf("%c",ch[i]);						//�ո���ֱ�����	
	printf("\n\n");

	system("pause");
	exit(0);
}

int main(void)
{
	char *str = "Rqfh pruh lqwr wkh euhdfk,ghdu iulhqgv,rqfh pruh;Ru forvh wkh zdoo xs zlwk rxu Hqjolvk ghdg.Lq shdfh wkhuh'v qrwklqj vr ehfrphv d pdq dv prghvw uwlooqhvv dqg kxplolwb:Exw zkhq wkh eodvw ri zdu eorzv lq rxu hduv,Wkhq lplwdwh wkh dfwlrq ri wkh wljhu;Vwliihq wkh vlqhzv,vxpprq xs wkh eorrg.";
	int frequency[26] = {0};   //���Ƶ��

	//���ú���
	countFrequency(str,frequency);
}
