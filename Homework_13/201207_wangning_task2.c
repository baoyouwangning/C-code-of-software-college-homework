/*
	功能：进制转换
	作者：wangning
	日期：2013-6-23
*/
#include <stdio.h>
#include <stdlib.h>

void Process(int x)
{
	if( (x/2) != 0) Process(x/2);	
	printf("%d",x % 2);
}


int main(void)
{
	int num;

	//接受用户输入
	printf("请输入一个十进制整数：");
	scanf("%d",&num);

	//输出结果
	printf("该十进制整数的二进制表示为：");
	Process(num);

	printf("\n");
	system("pause");
	return 0;
}