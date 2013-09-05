/*
	功能：字符串转换成整数
	作者：wangning
	日期：2013-6-28
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* 转换函数 */
void StringToInteger(char *str,int *number)
{
	int i = 0;
	int j = 0;
	*number = 0;			//初始化，为累加做准备

	//接受用户的字符串
	printf("请输入字符串：");
	gets(str);

	//找出字符串中第一位非数字的下标,用于后续10的n次方用
	while( isdigit(str[i++]) );
	
	//开始累加计算
	for( i -= 2; i >= 0; i--)
	{
		*number += (str[j++] - '0') * pow( (double) 10, i );
	}

	//输出数值
	printf("转换为整数为：%d\n",*number);

	//释放空间
	free(str);
	free(number);

	system("pause");
	exit(0);
}

int main(void)
{
	char *ch = NULL;
	int *num = NULL;
	int len;			//接受用户字符串长度

	//提示用户输入字符串长度
	printf("请输入要转换的字符串长度：");
	scanf("%d",&len);
	fflush(stdin);
	
	//开辟空间
	ch = (char *)malloc(sizeof(char) * (len+1));
	num = (int *)malloc(sizeof(int) * 1);

	/*传递参数调用函数*/
	StringToInteger(ch,num);
}