/*
	功能：日期判断
	作者：wangning
	日期：2013-6-23
*/
#include <stdio.h>
#include <stdlib.h>

//判断一个年份是否为闰年
int isLeapYear(int iYear)
{
	return !(iYear%4)&&(iYear%100) || !(iYear%400);
}

//判断某个日期为一周中的星期几  
int dayofWeek(int iYear,int iMonth,int iDay)
{
	int week = -1;
	
	//备用
	/*if(iMonth == 2)					//如果是二月
	{
		int leapYear = isLeapYear(iYear);   //判断是否为闰年
		if(leapYear == 0 && (iDay < 1 || iDay > 29) ) return week;		 //如果是平年则要求，  1 <= iDay <= 29 ,否则结束函数
		if(leapYear == 1 && (iDay < 1 || iDay > 28) ) return week;		 //如果是闰年则要求，  1 <= iDay <= 28 ,否则结束函数
	}

	if( (iMonth == 4 || iMonth == 6 || iMonth == 9 || iMonth == 11) && iDay > 30 ) return week;   //判断为30天的月份输入是否出错
	*/

	//该函数体以下来自百度百科
	if(iMonth == 1 || iMonth == 2)		//判断是否为1或2月,是则把它当做上一年的13或14月计算	
	{
		iMonth += 12;
		iYear--;
	}
	//基姆拉尔森计算公式，来自百度百科
	week = (iDay + 2 * iMonth + 3 * (iMonth + 1) / 5 + iYear + iYear/ 4 - iYear / 100 + iYear / 400) % 7 + 1;
	
	return week; // 输出-1为年月日无效,结束
}

//判断一个日期是这一年中的第几个星期
int weekofYear(int iYear,int iMonth,int iDay)
{
	int firstDayWeek;  //当年的第一天是星期几
	int leapYear;		//是否为闰年
	int days;		//当前日期是这一年的第多少天

	//判断月数是否符合标准,月数是否符合最大标准
	if(iYear < 1 || iMonth > 12 || iMonth < 1 || iDay < 1 || iDay > 31)  
	{
		printf("\n您输入的日期无法识别，请正确输入！\n\n");
		system("pause");
		exit(0);
	}

	//判断是否为闰年
	leapYear = isLeapYear(iYear);  

	//如果是二月
	if(iMonth == 2)	
	{
		
		if(leapYear == 0 && (iDay < 1 || iDay > 29) ) 		 //如果是平年则要求，  1 <= iDay <= 29 ,否则结束函数
		{
			printf("\n平年二月没有第 %d 天\n\n",iDay);
			system("pause");
			exit(0);
		}
		if(leapYear == 1 && (iDay < 1 || iDay > 28) ) 		 //如果是闰年则要求，  1 <= iDay <= 28 ,否则结束函数
		{
			printf("\n闰年二月没有第 %d 天\n\n",iDay);
			system("pause");
			exit(0);
		}
	}

	//判断为30天的月份输入是否出错
	if( (iMonth == 4 || iMonth == 6 || iMonth == 9 || iMonth == 11) && iDay > 30 )
	{
		printf("\n%d 月没有第 %d 天！\n\n",iMonth,iDay);
		system("pause");
		exit(0);
	}
	
	//判断当年的第一天是星期几
	firstDayWeek = dayofWeek(iYear,1,1);

	//获得当当前日期是这一年的第多少天
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

	//返回某一日期是这一年的第几个星期
	return ((int)((days-firstDayWeek+6.3)/7)+1);
}

int main(void)
{
	int year;
	int month;
	int day;

	//提示用户输入年月日
	printf("请输入一个日期（“年-月-日” 形式）：");
	scanf("%d-%d-%d",&year,&month,&day);

	//判断一个日期是这一年中的第几个星期
	printf("\n%d年%d月%d日属于%d年的第 %d 个星期的",year,month,day,year,weekofYear(year,month,day));

	//判断某个日期为一周中的星期几  
	printf("星期 %d \n\n",dayofWeek(year,month,day));

	system("pause");
	return 0;
}
