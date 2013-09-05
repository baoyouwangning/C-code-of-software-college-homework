/*
	功能：计算最大公约数最小公倍数
	作者：wangning
	日期：2013-6-24
*/
#include <stdio.h>
#include <stdlib.h>

//定义最大公约数函数
int  greatestCommonDivisor(int x,int y)
{
	if(y == 0) return x;
	else return greatestCommonDivisor(y,x%y);
}

//定义最小公倍数函数
int leastCommonMultiple(int x,int y)
{
	return x * y / greatestCommonDivisor(x,y);
}

int main(void)
{
	int a,b;

	//提示用户输入
	printf("请输入两个正整数(以空格隔开)：");
	scanf("%d %d",&a,&b);

	//调用函数
	printf("两个数的最大公约数是：%d\n",greatestCommonDivisor(a,b));
	printf("两个数的最小公倍数是：%d\n",leastCommonMultiple(a,b));

	system("pause");
	return 0;
}