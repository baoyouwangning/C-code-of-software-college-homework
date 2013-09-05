/*
	功能：年龄计算
	姓名：wangning
	日期：2013-6-27
*/
#include <stdio.h>
#include <stdlib.h>

#define len 5

//递归计算年龄函数
int Process(int *person,int i)
{
	
	if(i == 0) return person[i] = 10;				  //递归结束条件
	return person[i] =  Process(person,i - 1) + 2;	//步长为2
}

int main(void)
{
	int p[len];    //用于存放5个人的年龄

	//调用函数
	Process(p,len-1);

	printf("第五个人的年龄为：%d\n",p[4]);
	
	system("pause");
	return 0;
}