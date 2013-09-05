/*
	功能：计算三角形面积
	作者：wangning
	日期：2013-6-23
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Process(float a,float b,float c)
{
	if( (a+b) > c && (a+c) > b && (b+c) > a )
	{
		float C;
		C = (a+b+c) / 2;
		return sqrt(C * (C-a) * (C-b) * (C-c));
	}
	else return -1;
}

int main(void)
{
	float x,y,z;

	//接受三边
	printf("请输入三条边(以空格隔开)：");
	scanf("%f %f %f",&x,&y,&z);
	
	//传递并处理,返回结果
	printf("三边围成的面积为： S = %g\n",Process(x,y,z));

	system("pause");
	return 0;
}