/*
	功能:字符串连接(可接受用户自定义的多个字符串)
	作者:Wangning
	日期:2013-6-12
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	short count;
	short length;
	short linkLength;
	short i,j;
	char **p = NULL;
	char *q = NULL;
	int k;

	
	printf("请输入要连接的字符串个数：");
	scanf("%hd",&count);
	printf("请输入最大字符串长度：");
	scanf("%hd",&length);
	
	//连接后的长度
	linkLength = count * (length + 1) + count;

	//开辟空间
	p = (char **)malloc(sizeof(p) * count);
	if(p == NULL) exit(0);
	for (i = 0; i <= count - 1 ; i++)
	{
		p[i] = (char *)malloc( sizeof(char) * (length + 1) );		//最后一位补0
		if(p[i] == NULL) exit(0);
	}
	q = (char *)malloc(sizeof(char) * linkLength );		//中间补空格,最后补0
	if( q == NULL) exit(0);
	
	//初始化								//不用初始化
	//for(i = 0; i <= count - 1 ; i++)
	//	for(j = 0; j <= length; j++)
	//		p[i][j] = 0;	

		//	strcpy(p[i][j],0);			//strcpy怎么不能用？
	//}
	//for(i = 0; i <= linkLength - 1; i++)
	//{
	//	q[i]= 0;
	//}

	//接受用户输入
	getchar();
	for ( i = 0; i <= count - 1; i++)
	{
		printf("请输入第%d个字符串：",i);
		//scanf("%s",p[i]);				//problem?
		gets(p[i]);
	}

	//开始连接
	k = 0;
	for(i = 0; i <= count - 1; i++)
		for(j = 0; j <= length; j++)   //p[i][length]为非收入位，接受输入后，系统会自动补零！
		{
			if( p[i][j] == 0)
			{
				
				if( i != count - 1 )  //如果不是最后一行，则把 '/0'换成空格，break换下一行
				{
					q[k] = ' ';
					k++;	
					break;
				}
				else					//如果是最后一行，则补零结束
				{
					q[k] = 0;
					break;
				}
			}
			else 
				q[k] = p[i][j];			
			
			k++;	
					//strcpy(*(q++),p[i][j]);   都是用的直接赋值，strcpy反而不行？
		}

	//输出连接后的字符串
	printf("\n依次连接得： %s\n\n",q);
	
	//释放空间
	for (i = 0; i < count - 1 ; i++)
	{
		free(p[i]);	
	}
	free(p);
	free(q);

	system("pause");
	return 0;
}