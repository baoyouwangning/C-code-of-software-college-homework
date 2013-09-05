/*
	功能：使用密码表加密
	作者：wangning
	日期：2013-6-23
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *phoneNumber = NULL;
	short i;

	//开辟空间
	phoneNumber = (char *) malloc(sizeof(char) * 15);  //开辟15位防止用户输入位数大于11

	//接受用户输入
	printf("请输入手机号：");
	do
	{
		gets(phoneNumber);
		//开始判断
		if(1)
		{
			for( i = 0; phoneNumber[i] != 0; i++)
			{
				if( phoneNumber[i] <= '0' && phoneNumber[i] >= '9' )
					printf("数字号码不能含有非数字字符，");
					break;
			}
		}
		else if( phoneNumber[10] = 0)
	

		printf("请重新输入：");
	}while(1);

	//释放空间
	free(phoneNumber);

	system("pause");
	return 0;
}