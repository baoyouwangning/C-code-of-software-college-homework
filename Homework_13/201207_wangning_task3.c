/*
	���ܣ������ж�
	���ߣ�wangning
	���ڣ�2013-6-23
*/
#include <stdio.h>
#include <stdlib.h>

//�ж�һ������Ƿ�Ϊ����
int isLeapYear(int iYear)
{
	return !(iYear%4)&&(iYear%100) || !(iYear%400);
}

//�ж�ĳ������Ϊһ���е����ڼ�  
int dayofWeek(int iYear,int iMonth,int iDay)
{
	int week = -1;
	
	//����
	/*if(iMonth == 2)					//����Ƕ���
	{
		int leapYear = isLeapYear(iYear);   //�ж��Ƿ�Ϊ����
		if(leapYear == 0 && (iDay < 1 || iDay > 29) ) return week;		 //�����ƽ����Ҫ��  1 <= iDay <= 29 ,�����������
		if(leapYear == 1 && (iDay < 1 || iDay > 28) ) return week;		 //�����������Ҫ��  1 <= iDay <= 28 ,�����������
	}

	if( (iMonth == 4 || iMonth == 6 || iMonth == 9 || iMonth == 11) && iDay > 30 ) return week;   //�ж�Ϊ30����·������Ƿ����
	*/

	//�ú������������԰ٶȰٿ�
	if(iMonth == 1 || iMonth == 2)		//�ж��Ƿ�Ϊ1��2��,�������������һ���13��14�¼���	
	{
		iMonth += 12;
		iYear--;
	}
	//��ķ����ɭ���㹫ʽ�����԰ٶȰٿ�
	week = (iDay + 2 * iMonth + 3 * (iMonth + 1) / 5 + iYear + iYear/ 4 - iYear / 100 + iYear / 400) % 7 + 1;
	
	return week; // ���-1Ϊ��������Ч,����
}

//�ж�һ����������һ���еĵڼ�������
int weekofYear(int iYear,int iMonth,int iDay)
{
	int firstDayWeek;  //����ĵ�һ�������ڼ�
	int leapYear;		//�Ƿ�Ϊ����
	int days;		//��ǰ��������һ��ĵڶ�����

	//�ж������Ƿ���ϱ�׼,�����Ƿ��������׼
	if(iYear < 1 || iMonth > 12 || iMonth < 1 || iDay < 1 || iDay > 31)  
	{
		printf("\n������������޷�ʶ������ȷ���룡\n\n");
		system("pause");
		exit(0);
	}

	//�ж��Ƿ�Ϊ����
	leapYear = isLeapYear(iYear);  

	//����Ƕ���
	if(iMonth == 2)	
	{
		
		if(leapYear == 0 && (iDay < 1 || iDay > 29) ) 		 //�����ƽ����Ҫ��  1 <= iDay <= 29 ,�����������
		{
			printf("\nƽ�����û�е� %d ��\n\n",iDay);
			system("pause");
			exit(0);
		}
		if(leapYear == 1 && (iDay < 1 || iDay > 28) ) 		 //�����������Ҫ��  1 <= iDay <= 28 ,�����������
		{
			printf("\n�������û�е� %d ��\n\n",iDay);
			system("pause");
			exit(0);
		}
	}

	//�ж�Ϊ30����·������Ƿ����
	if( (iMonth == 4 || iMonth == 6 || iMonth == 9 || iMonth == 11) && iDay > 30 )
	{
		printf("\n%d ��û�е� %d �죡\n\n",iMonth,iDay);
		system("pause");
		exit(0);
	}
	
	//�жϵ���ĵ�һ�������ڼ�
	firstDayWeek = dayofWeek(iYear,1,1);

	//��õ���ǰ��������һ��ĵڶ�����
	days = iDay;
	switch(iMonth - 1)
	{
		case 11: days += 30;
		case 10: days += 31;
		case  9: days += 30;
		case  8: days += 31;
		case  7: days += 31;
		case  6: days += 30;
		case  5: days += 31;
		case  4: days += 30;
		case  3: days += 31;
		case  2: 
			if(leapYear == 0) days += 29;
			else days += 28;
		case  1: days += 31;
	}

	//����ĳһ��������һ��ĵڼ�������
	return ((int)((days-firstDayWeek+6.3)/7)+1);
}

int main(void)
{
	int year;
	int month;
	int day;

	//��ʾ�û�����������
	printf("������һ�����ڣ�����-��-�ա� ��ʽ����");
	scanf("%d-%d-%d",&year,&month,&day);

	//�ж�һ����������һ���еĵڼ�������
	printf("\n%d��%d��%d������%d��ĵ� %d �����ڵ�",year,month,day,year,weekofYear(year,month,day));

	//�ж�ĳ������Ϊһ���е����ڼ�  
	printf("���� %d \n\n",dayofWeek(year,month,day));

	system("pause");
	return 0;
}
