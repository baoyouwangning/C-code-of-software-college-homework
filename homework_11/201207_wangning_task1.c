/*
	功能：矩阵乘法(可接受用户自定义的矩阵行列数)
	作者：Wangning
	日期：2013-6-11
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	short row,common,col;		//矩阵A,B的行列,common=矩阵A的列=矩阵B的行
	short i,j,k;				  //下标计数器
	float **a = NULL;
	float **b = NULL;
	float **c = NULL;

	//提示用户自定义矩阵行列数
	printf("请输入矩阵A的行列数：");
	scanf("%hd %hd",&row,&common);
	printf("请输入矩阵B的列数：");
	scanf("%hd",&col);

	//再堆区开辟空间
		//矩阵A
	a = (float **)malloc(sizeof(a) * row);  //row个二重指针(矩阵A的行数)
	for ( i = 0; i <= row - 1; i++)
	{
		a[i] = (float *)malloc(sizeof(float) * common);		//common个一重指针(矩阵A的列数)
	}
		//矩阵B
	b = (float **)malloc(sizeof(b) * common);  //common个二重指针(矩阵B的行数)
	for ( i = 0; i <= common - 1; i++)
	{
		b[i] = (float *)malloc(sizeof(float) * col);		//common个一重指针(矩阵A的列数)
	}

	c = (float **)malloc(sizeof(c) * row);     //row个二重指针(矩阵C的行数)
	for (i = 0; i <= row - 1; i++)
	{
		c[i] = (float *)malloc(sizeof(float) * col);	 //col个一重指针(矩阵C的列数)
	}
	//对矩阵C进行初始化
	for (i = 0; i <= row - 1; i++)
		for (j = 0; j <= col - 1; j++)
			c[i][j] = 0;


	//接受用户输入
		//矩阵A
	printf("\n矩阵A：\n");
	for (i = 0; i <= row - 1; i++)
	{
		printf("请输入第%d行：\n",i + 1);
		for (j = 0; j <= common - 1; j++)
		{
			printf("第%d个数：",j + 1);
			scanf("%f",&a[i][j]);
		}
	}
		//矩阵B
	printf("\n矩阵B：\n");
	for(i = 0; i <= common - 1; i++)
	{
		printf("请输入第%d行：\n",i + 1);
		for( j = 0; j <= col - 1; j++)
		{
			printf("第%d个数：",j + 1);
			scanf("%f",&b[i][j]);
		}
	}

	//打印两个相乘的矩阵
		//矩阵A
	printf("\n\n");
	for (i = 0; i <= row - 1; i++)
	{
		if( i == row/2 )
			printf("矩阵A=");
		printf("\t|");
		for(j = 0; j <= common - 1; j++)
		{
					
			printf("%g ",a[i][j]);		
		}
		printf("\b|\n");
	}
	printf("\n\n");
	for (i = 0 ; i <= common - 1; i++)
	{
		if( i == common/2 )
			printf("矩阵B=");
		printf("\t|");
		for(j = 0; j <= col - 1; j++)
		{
					
			printf("%g ",b[i][j]);		
		}
		printf("\b|\n");
	}

	/*开始计算:
	思路：
		1.开辟空间后初始化C[row][col] = {0}
		2.先将矩阵A的第一行的第一个数依次乘上矩阵B的第一行的每个数,并放入矩阵C的对应位置
		3.然后再将矩阵A的第一行的第二个数依次乘上矩阵B的第二行的每个数,并放入矩阵C的对应位置
		4.矩阵A的第一行的第n个数同理
		4.然后再将矩阵A的第二行的第一个数依次乘上矩阵B的第一行的每个数,并加上矩阵C对应位置的现有值
		5.以下同理(重复2,3,4)
	*/
	for(i=0;i<=row - 1;i++)			//矩阵A的行,即矩阵C的行
		for(j=0;j<=common - 1;j++)    //矩阵A的列
			for(k=0;k<col;k++)		//矩阵B的列,即矩阵C的列
				c[i][k] += a[i][j] * b[j][k];		//矩阵C的每个位置累加

	
	//输出乘积矩阵C
	printf("\n\n");
	for (i = 0 ; i <= row - 1; i++)
	{
		if( i == row/2 )
			printf("乘积矩阵C=\t|");
		else
		{
			printf("\t\t|");
		}	
		for(j = 0; j <= col - 1; j++)
		{			
			printf("%g ",c[i][j]);		
		}
		printf("\b|\n");
	}
	
	//释放内存空间
	for ( i = 0; i <= row - 1; i++)
		free(a[i]);
	free(a);
	for ( i = 0; i <= common - 1; i++)
		free(b[i]);
	free(b);
	for ( i = 0; i <= row - 1; i++)
		free(c[i]);
	free(c);

	system("pause");
	return 0;	
}