/*
	功能：最大公约数
	作者：wangning
	日期：2013-6-28
*/
#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n)
{
	if( m == n)	return m;
	else if(m > n)	return gcd(m-n,n);
	else	return gcd(n-m,m);
}

int main()
{
	int a,b;

	//接受用户输入
	printf("请输入两个正整数（求其最大公约数，以逗号隔开）：");
	scanf("%d %d",&a,&b);

	//传递参数，调用函数
	printf("\n%d 和 %d的最大公约数为：%d\n",a,b,gcd(a,b));

	system("pause");
	return 0;
}
