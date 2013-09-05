/*
	功能：手机号验证(有错误的优先级：有非数字字符 > 长度不够 > 长度太长 > 没有这样的手机号)
	作者：wangning
	日期：2013-6-23
*/

#include <stdio.h>
#include <stdlib.h>

#define notDigital 1

int main(void)
{
	char *phoneNumber = NULL;
	short i = 0;
	short flag = 0;
	short j = 0;   //计数器

	//开辟空间
	phoneNumber = (char *) malloc(sizeof(char) * 15);  //开辟15位防止用户输入位数大于11

	//接受用户输入
	printf("请输入手机号：");
	do
	{
		gets(phoneNumber);
		
		//开始判断
		for( i = 0; phoneNumber[i] != 0; i++)
			{
				//记录是否有非数字
				if( phoneNumber[i] < '0' || phoneNumber[i] > '9' )
				{
					flag = notDigital;
				}
				//记录字符串长度
				if( phoneNumber[i] != 0) j++;
			}
		if( flag == notDigital) printf("\n数字号码不能含有非数字字符，");
			
		else if( j < 11) printf("\n手机号码长度小于11，");   

		else if( j > 11) printf("\n手机号码长度大于11,");  

		//记录手机号是否有效
		else if( phoneNumber[0] != '1' || phoneNumber[1] < '3' || phoneNumber[1] > '5' && phoneNumber[1] != '8' || phoneNumber[2] < '0' || phoneNumber[2] > '9' ) printf("\n没有这样的手机号，");
		//else if( phoneNumber[0] != '1' || phoneNumber[1] != '3' || phoneNumber[1] != '4' || phoneNumber[1] != '5' || phoneNumber[1] != '8' || phoneNumber[2] < '0' || phoneNumber[2] > '9' ) printf("没有这样的手机号，");
		
		//判断是否为移动客户
		else if( phoneNumber[1] == '3' && phoneNumber[2] >= '4' && phoneNumber[2] <= '9' || phoneNumber[1] == '4' && phoneNumber[02] == '7' || phoneNumber[1] == '5' && ( phoneNumber[2] >= '0' && phoneNumber[2] <= '2' || phoneNumber[2] >= '7' && phoneNumber[2] <= '9' ) || phoneNumber[1] == '8' && ( phoneNumber[2] == '2' || phoneNumber[2] == '7' || phoneNumber[2] == '8') ) 
		{
			printf("您所查询的为移动号码。\n");
			break;
		}
	
		//判断是否为联通客户
		else if( phoneNumber[1] == '3' && phoneNumber[2] >= '0' && phoneNumber[2] <= '2' || phoneNumber[1] == '5' && ( phoneNumber[2] == '5' || phoneNumber[2] == '6') || phoneNumber[1] == '8' && ( phoneNumber[2] == '5' || phoneNumber[2] == '6') )
		{
			printf("您所查询的为联通号码。\n");
			break;
		}

		//判断是否为电信客户
		else if( phoneNumber[1] == '3' && phoneNumber[2] == '3' || phoneNumber[1] == '5' && phoneNumber[2] == '3' || phoneNumber[1] == '8' && ( phoneNumber[2] == '0' || phoneNumber[2] == '9' ) )
		{
			printf("您所查询的为电信号码。\n");
			break;
		}
		
			//提示用户再次输入
		flag = 0;
		j = 0;
		printf("请重新输入：");
	}while(1);

	//释放空间
	free(phoneNumber);

	system("pause");
	return 0;
}