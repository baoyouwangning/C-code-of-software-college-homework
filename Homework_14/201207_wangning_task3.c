/*
	功能：凯撒密码
	作者：wangning
	日期：2013-6-26
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// 找频数出现次数大的下标
int findMxnIndex(int *p,int len)
{
	int i;
	int index = 0;   //要求最大值的下标
	
	for(i = 0; i < len; i++)
	{
		if (p[i] > p[index])
			index = i;
	}
	
	if(p[index] == 0)  //判断当前下标对应的最大频数是否为0，若等于零 则通过该下标和ASCII码类推的字符在密文中没有出现
		return -1;	//返回 -1

	p[index] = 0;		 //频数归零，防止影响下次判断
	return index;
}



/*
	统计英文字母出现的频率
	思路：由大写字母或小写字母的ASCII码 与 存放每个字符的出现频率的数组下标的关系进行累加实现字符出现频率的统计
*/
void countFrequency(char *ch,int *frequency)
{
	int i;  //下标索引
	char alphaList[27];   //定义26个字母表，下标与存放频数对应
	int maxIndex = 0; 


	//记录每个字符出现的频数
	for(i = 0; ch[i] != 0; i++)
		if( isalpha(ch[i]) )
		{
			if( isupper(ch[i]) ) frequency[ch[i] - 65] += 1;
			if( islower(ch[i]) ) frequency[ch[i] - 97] += 1;
		}

	//对出现的频数进行排序，每次返回最大值的下标，使alphaList中的字符从大到小一次存放26个字符
	for(i = 0; i < 26;i++)
	{
		maxIndex = findMxnIndex(frequency,26);		// 调用查找频数出现次数大的下标

		//判断是否终止循环(通过该下标和ASCII码类推的字符在密文中没有出现)
		if(maxIndex == -1) 
		{
			alphaList[i] = '\0';     //为当前位字符数组加遍历结束条件
			break;
		}
		
		//开始写入字符
		alphaList[i] = maxIndex + 97;				//由频数数组下标与ASCII码关系易得	
	}

	//输出排序后的字符， 不够26时则因为原密文中没有出现的字符
	printf("密文字符出现频率的先后顺序为：\n");
	for(i = 0; alphaList[i] != 0; i++)
		printf("%c ",alphaList[i]);
	printf("\n\n");

	/*	
		网上搜索得： 英文字母频率的大小顺序为：eairtonslcupmdhgbyfvwkxzqj
		推理得：应对密文的每个字符ASCII码前移3位
	*/

	//开始解密
	for(i = 0; ch[i] != 0; i++)
		if( isalpha(ch[i]) )				//如果是26个英文字母	
		{
			if( isupper(ch[i]) )			//如果是大写字母
			{
				if( ch[i] <= 'C' && ch[i] >= 'A' )   
				{
					printf("%c",ch[i] + 23);			//则循环
				}
				else
					printf("%c",ch[i] - 3);			//则ASCII码直接前移三位

			}
			if( islower(ch[i]) )			//如果是小写字母
			{
				if( ch[i] <= 'c' && ch[i] >= 'a')
				{
					printf("%c",ch[i] + 23);			//则循环
				}
				else
					printf("%c",ch[i] - 3);			//则ASCII码直接前移三位
			}
		}
		else if(ch[i] == ';' || ch[i] == '.' || ch[i] == ':' || ch[i] == ',')    //如果是标点符号
		{
			if( isupper(ch[i+1]) || ch[i+1] == '\0' ) printf("%c\n",ch[i]);						//如果下一位是大写字母
		}
		else printf("%c",ch[i]);						//空格则直接输出	
	printf("\n\n");

	system("pause");
	exit(0);
}

int main(void)
{
	char *str = "Rqfh pruh lqwr wkh euhdfk,ghdu iulhqgv,rqfh pruh;Ru forvh wkh zdoo xs zlwk rxu Hqjolvk ghdg.Lq shdfh wkhuh'v qrwklqj vr ehfrphv d pdq dv prghvw uwlooqhvv dqg kxplolwb:Exw zkhq wkh eodvw ri zdu eorzv lq rxu hduv,Wkhq lplwdwh wkh dfwlrq ri wkh wljhu;Vwliihq wkh vlqhzv,vxpprq xs wkh eorrg.";
	int frequency[26] = {0};   //存放频数

	//调用函数
	countFrequency(str,frequency);
}
