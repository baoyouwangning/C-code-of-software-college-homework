/*
	功能：短信分割
	作者：wangning
	日期：2013-6-22
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *message = NULL;
	short i;            
	char (*p) [70] = NULL;

	//开辟空间
	message = (char *)malloc(sizeof(char) * 141); 

	//接受用户输入

	printf("Please input your message:\n");

	gets(message);

	(*p)[70] =  message[0];
	printf("%s\n",message);

	printf("%s\n",p);

	system("pause");
	return 0;
}

