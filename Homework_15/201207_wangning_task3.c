/*
	���ܣ����Լ��
	���ߣ�wangning
	���ڣ�2013-6-28
*/
#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n)
{
	if( m == n)	return m;
	else if(m > n)	return gcd(m-n,n);
	else	return gcd(n-m,m);
}

int main()
{
	int a,b;

	//�����û�����
	printf("�������������������������Լ�����Զ��Ÿ�������");
	scanf("%d %d",&a,&b);

	//���ݲ��������ú���
	printf("\n%d �� %d�����Լ��Ϊ��%d\n",a,b,gcd(a,b));

	system("pause");
	return 0;
}
