/*
	功能：寻找亚军
	作者：wangning
	日期：2013-6-25
*/
#include <stdio.h>
#include <stdlib.h>

#define length 8

void findSecondMax(int *p,const int len)
{
	/*思路：先找最大值，然后再找第二大值，遇到最大值的下标则跳过*/
	int i;	//控制查找循环次数
	int j;   //下标索引
	int max = 0;  //记录最大值下标
	int max_second = 1;  //记录第二大值小标,初始值为 1 防止当第一个数最大时，影响第二大值的判断
	
	//遍历找第二大值
	for(i = 0; i <= 1 ; i++)
	{
		for(j = 0; j < len; j++)
		{
			if(i == 0)			//第一趟找最大值下标
				if(p[j] > p[max])
					max = j;
			if(i == 1)			//第二趟才找次大元素下标
			{
				if(p[j] == p[max])		//跳过最大值
					continue;
				else if( p[j] >= p[max_second])  
					max_second = j;			//得到最后出现次大元素的下标
			}
		}
	}

	//遍历找第二大值的下标,从当前的 max_second 下标处开始即可
	printf("次大元素（%d）的下标是：",p[max_second]);
	for(i = 0; i <= max_second; i++)
	{
		
		if(i == max_second)
			printf("%d",max_second);
		else if(p[i] == p[max_second])
				printf("%d，",i);
	}
	printf("\n");
	
	system("pause");
	exit(0);
}

int main()
{
	int a[length];

	//接收用户输入
	printf("一维数组中的元素是：");
	scanf("%d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7]);

	//调用函数
	findSecondMax(a,length);
}