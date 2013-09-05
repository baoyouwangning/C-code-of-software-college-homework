/*
	功能：接收用户自定义的数组，然后按题目要求排序
	作者：wangning
	日期：2013-6-26
*/
#include <stdio.h>
#include <stdlib.h>

//查找最小元素的下标
int findMinIndex(int p[],const int len)
{
	int i;

	int min_i = 0;
	
	//遍历查找最小值的下标  
	/*思路：跳跃查找最小值的下标，当发现有比当前的标准值小的则跳到小值下标处继续查找*/
	for(i = 0,min_i = 0; min_i < len && i < len; )
	{
		for(i = min_i; i < len ; i++)
		{
			if(p[i] < p[min_i])
			{
				min_i = i;
				break;
			}
		}
	}

	return min_i;
}

//排序函数
void sort(int p[],const int len)
{
	int i;
	int temp;
	int min;

	//接收用户输入
	for( i = 0; i < len; i++)
	{
		printf("请输入第%d个元素：",i+1);
		scanf("%d",&p[i]);
	}
	
	//输出原始状态的数组
	printf("数组的初始状态是：");
	for(i = 0; i < len; i++)
		printf("%d ",p[i]);
	printf("\n");

	//按要求排序
	for(i = len; i >= 2; i--)
	{	
		min = findMinIndex(p,i);   //调用找最小值下标的函数
		temp = p[i-1];
		p[i-1] = p[min];
		p[min] = temp;
	}

	//输出排序后的结果
	printf("排序后数组的状态是：");
	for(i = 0; i < len; i++)
		printf("%d ",p[i]);
	printf("\n");

	system("pause");
	exit(0);
}

int main(void)
{
	int *originalArray = NULL;
	int count;

	//提示用户输入元素个数
	printf("请输入原始数组元素个数");
	scanf("%d",&count);

	//开辟空间
	originalArray = (int *)malloc(sizeof(int) * count);

	//调用排序函数
	sort(originalArray,count);
}

