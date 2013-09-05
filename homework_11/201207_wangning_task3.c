/*	
	功能：矩阵元素对角线之和(可自定义矩阵大小)
	作者：wangning
	日期：2013-6-19
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	short i,j;         //下标计数器
	short row,col;
	float **p = NULL; 
	float sum_zhu = 0;
	float sum_fu = 0;


	printf("请输入矩阵行列数(以空格隔开):");
	scanf("%hd %hd",&row,&col);

	//开辟空间
	p = (float **)malloc(sizeof(p) * row);   //开辟行数
	if(p == NULL) 
	{
		printf("没有足够的内存空间!");
		exit(0);
	}
	for(i = 0; i <= row - 1; i++)			//开辟列数
	{
		p[i] = (float *)malloc(sizeof(float) * col);
		if(p[i] == NULL)
		{
			printf("没有足够的内存空间!");
			exit(0);
		}
	}

	//接受用户输入
	for(i = 0,j = col-1; i <= row - 1; i++)
		for(j = 0; j <= col - 1; j++)
		{
			printf("请输入第%d行第%d列的数：",i+1,j+1);
			scanf("%f",&p[i][j]);
		}

	/*开始计算*/	
		//求主对角线之和
	for(i = 0; i <= row - 1; i++)
	{
		if( i == 0) j = col - 1;    //j初始化
		for( j = j; j >= 0;)
		{
			sum_zhu += p[i][i];
			sum_fu += p[i][j--];
			break;
		}
	}

		//输出主对角线之和
	printf("主对角线之和为：%g\n",sum_zhu);
		//输出副对角线之和
	printf("副对角线之和为：%g\n",sum_fu);
		




	

	

	//输出原矩阵
	printf("矩阵如下：\n");
	for(i = 0; i <= row - 1; i++)
	{
		for(j = 0; j <= col - 1; j++)
		{
			if(j != 0) printf("\t%g",p[i][j]);
			else printf("%g",p[i][j]);		
		}
		printf("\n");
	}


	for(i = 0; i <= row - 1; i++)
		free(p[i]);
	free(p);
	system("pause");
	return 0;
}