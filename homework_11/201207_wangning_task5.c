/*
	功能：绘制自定义迷宫地图
	作者：wangning
	日期：2013-6-20
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char picOfWall;
	char map[6] = "\0";
	char **mapArry = NULL;
	short i,j;

	//开辟看空间
	mapArry = (char **) malloc( 4 * 8);
	if( mapArry == NULL) exit(0);
	for(i = 0; i <= 7; i++)
	{
		mapArry[i] = (char *)malloc(sizeof(char) * 9); //mapArry[i][8]输入时自动补零
		if( mapArry[i] == NULL) exit(0);
	}

	//提示用户输入
	printf("Please input the picture of the wall：");
	scanf("%c",&picOfWall);
	getchar();						   //当没有getchar();时有问题？
	printf("Please input your map：");

	gets(map);				

	printf("\n");
	for(i = 0; i <= 7; i++)  //输入地图矩阵
	{
		//scanf("%s",mapArry[i]);
		gets(mapArry[i]);
	}

	
	//输出地图
	printf("\nNow drawing the map:\n");
	for(i = 0; i <= 7; i++)
	{
		for(j = 0; j <= 7; j++)
		{
			if( map[1] == mapArry[i][j])
				printf("%c",picOfWall);
			else if( map[3] == mapArry[i][j]) 
				printf("_");
			else
				printf("undefined ");
		}
		printf("\n");
	}



	//释放空间
	for(i = 0; i <= 7; i++)
		free(mapArry[i]);

	free(mapArry);

	system("pause");
	return 0;
}