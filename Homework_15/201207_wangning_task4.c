/*
	功能：数组计算(没有接受用户自定义的数组功能,若改成用户自定义数组,则还不能判断处于特殊边缘的0的周围有几个1。时间允许有待提高)
	作者：wangning
	日期：2013-6-28
*/
#include <stdio.h>
#include <stdlib.h>

#define row 8
#define col 8

//递归处理函数
void Process(int *q,int *start,int *end)
{	
	int sum = 0;

	if( q > end) //递归函数结束条件
	{
		printf("%d",sum);
		system("pause");
		exit(0);
	}
	else if( !*q )      
	{
		sum += *(q-10) + *(q-9) + *(q-8) + *(q-2) + *q + *(q+6) + *(q+7) + *(q+8);
		printf("a[%d][%d] 周围有 %d 个1\n",(q-start)/col,(q-start)%col,sum);
	}
	
	Process(++q,start,end);	 //递归
}

int main(void)
{
	int a[row][col] = { {1,1,1,1,1,1,1,1},{1,1,0,0,1,0,0,1}, {1,0,0,1,0,0,1,1}, {1,1,1,0,0,1,0,1}, {1,0,1,1,1,0,0,1}, {1,1,0,0,0,1,1,1}, {1,1,1,1,0,0,0,1}, {1,1,1,1,1,1,1,1} };
	int *q = &a[0][0];
	int i,j;    
	
	//输出二维数组原型
	printf("原数组 int a[%d][%d] = \n{\n",row,col);
	for(i = 0; i < row; i++ )
	{
		printf(" {");
		for(j = 0; j < col; j++)
		{
			if(j < col - 1)	printf("%d,",*q++);
			else printf("%d",*q++);
		}
		if( i < row - 1)	printf("},\n");
		else printf("}\n",*q++);	
	}
	printf("}\n");

	//调用递归函数
	q = &a[0][0];
	Process(q,q,q+row * col-1);
}