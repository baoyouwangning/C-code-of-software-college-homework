/*
	���ܣ������Զ����Թ���ͼ
	���ߣ�wangning
	���ڣ�2013-6-20
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

	//���ٿ��ռ�
	mapArry = (char **) malloc( 4 * 8);
	if( mapArry == NULL) exit(0);
	for(i = 0; i <= 7; i++)
	{
		mapArry[i] = (char *)malloc(sizeof(char) * 9); //mapArry[i][8]����ʱ�Զ�����
		if( mapArry[i] == NULL) exit(0);
	}

	//��ʾ�û�����
	printf("Please input the picture of the wall��");
	scanf("%c",&picOfWall);
	getchar();						   //��û��getchar();ʱ�����⣿
	printf("Please input your map��");

	gets(map);				

	printf("\n");
	for(i = 0; i <= 7; i++)  //�����ͼ����
	{
		//scanf("%s",mapArry[i]);
		gets(mapArry[i]);
	}

	
	//�����ͼ
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



	//�ͷſռ�
	for(i = 0; i <= 7; i++)
		free(mapArry[i]);

	free(mapArry);

	system("pause");
	return 0;
}