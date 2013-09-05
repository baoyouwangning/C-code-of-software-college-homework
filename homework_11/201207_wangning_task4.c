/*
	功能：数据加密
	作者：wangning
	日期：2013-6-19
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	short i,j;  //下标
	int Data[4];
	int swap;		//交换空间

	//接受用户输入
	printf("请输入一组号码(四个)：");
	scanf_s("%d %d %d %d",&Data[0],&Data[1],&Data[2],&Data[3]);

	//开始加密
	for(i = 0; i <= 3; i++)
		Data[i] = (Data[i] + 5) % 10;
	
	swap = Data[0];
	Data[0] = Data[3];
	Data[3] = swap;
	swap = Data[1];
	Data[1] = Data[2];
	Data[2] = swap;
	
	

	//输出加密后的号码
	printf("加墨后的号码为：");
	for(i = 0; i <= 3; i++)
		printf("%d ",Data[i]);
	printf("\n");
	
	system("pause");
	return 0;
}