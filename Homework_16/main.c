/*
	���ܣ�����5����Ŀ
	���ߣ�wangning
	���ڣ�2013-7-6
*/
#include <stdio.h>
#include <stdlib.h>
#include "homework16.h"

int main(void)
{
	short choose;

	//���շ���ֵ
	double result;

	//����һ����
	Point point;
	
	//������һ���㣨task1:��������֮��ľ��룩
	Point point2;

	//����һ��ֱ�ߣ�task2:����һ���㵽һ��ֱ�ߵľ��룩
	Line line;

	//����һ��Բ��task3:����һ�����Ƿ���Բ֮�ڣ�
	Circle circle;

	//����һ�����Σ�task4:�ж�һ�����Ƿ��ھ����ڲ���
	Rect rect;  

	//������һ��Բ
	Circle circle2;

	//��ʾ�û�ѡ������
	printf("�����б�\n");
	printf("����1����������֮��ľ���\n");
	printf("����2������һ���㵽һ��ֱ�ߵľ���\n");
	printf("����3������һ�����Ƿ���һ��Բ֮��\n");
	printf("����4���ж�һ�����Ƿ���һ�������ڲ�\n");
	printf("����5���ж�����Բ�Ƿ����ཻ\n");
	printf("��ѡ��1-5����");
	
	//����ѡ��
	scanf("%hd",&choose);

	switch(choose)
	{
	case 1:
		//�����û�����
		printf("�������A�ĺ������꣨�Կո��������");
		scanf("%f %f",&point.x,&point.y);
		printf("�������B�ĺ������꣨�Կո��������");
		scanf("%f %f",&point2.x,&point2.y);
		//���ú���
		result = Process_1(point,point2);
		//��ӡ���
		printf("��A��%g,%g�����B��%g,%g���ľ���Ϊ %g\n",point.x,point.y,point2.x,point2.y,result);
		break;
	
	case 2:
		//�����û�����
		printf("������õ�ĺ������꣨�Կո��������");
		scanf("%f %f",&point.x,&point.y);
		printf("�������ֱ��һ��ʽ����X��ϵ��A,Y��ϵ��B,�ͳ���C���Կո��������");
		scanf("%f %f %f",&line.A,&line.B,&line.C);
		//���ú���
		result = Process_2(point,line);
		//��ӡ���
		printf("��A��%g,%g����ֱ�� (%g)x+(%g)y+(%g)=0 �ľ���Ϊ %g\n",point.x,point.y,line.A,line.B,line.C,result);
		break;

	case 3:
		//�����û�����
		printf("�������Բ��Բ�ĵĺ�������Ͱ뾶���Կո��������");
		scanf("%f %f %f",&circle.centerCircle.x,&circle.centerCircle.y,&circle.R);
		printf("�������жϵ�A�ĺ������꣨�Կո��������");
		scanf("%f %f",&point.x,&point.y);
		//���ú���
		result = Process_3(point,circle);
		//��ӡ���
		if(result == 0) printf("��A��%g,%g�����ԣ�%g,%g��ΪԲ��R=%g��Բ�⡣\n",point.x,point.y,circle.centerCircle.x,circle.centerCircle.y,circle.R);
		else if(result == 1) printf("��A��%g,%g�����ԣ�%g,%g��ΪԲ��R=%g��Բ�ڡ�\n",point.x,point.y,circle.centerCircle.x,circle.centerCircle.y,circle.R);
		else  printf("��A��%g,%g�����ԣ�%g,%g��ΪԲ��R=%g��Բ�ϡ�\n",point.x,point.y,circle.centerCircle.x,circle.centerCircle.y,circle.R);
		break;
	case 4:
		//�����û�����
		printf("����������þ������ϽǺ����½ǵĺ������꣨�Կո��������");
		scanf("%f %f %f %f",&rect.topLeft.x,&rect.topLeft.y,&rect.lowerRight.x,&rect.lowerRight.y);
		printf("������ĵ�A�ĺ������꣨�Կո��������");
		scanf("%f %f",&point.x,&point.y);
		//���ú���
		result = Process_4(point,rect);
		if(result == 0)	printf("��A��%g,%g�����ԣ�%g,%g��Ϊ���϶��㣨%g,%g��Ϊ���¶���ľ����⡣\n",point.x,point.y,rect.topLeft.x,rect.topLeft.y,rect.lowerRight.x,rect.lowerRight.y);
		else if(result == 1)	printf("��A��%g,%g�����ԣ�%g,%g��Ϊ���϶��㣨%g,%g��Ϊ���¶���ľ����ڡ�\n",point.x,point.y,rect.topLeft.x,rect.topLeft.y,rect.lowerRight.x,rect.lowerRight.y);
		else printf("��A��%g,%g�����ԣ�%g,%g��Ϊ���϶��㣨%g,%g��Ϊ���¶���ľ����ϡ�\n",point.x,point.y,rect.topLeft.x,rect.topLeft.y,rect.lowerRight.x,rect.lowerRight.y);
		break;
	case 5:
		//�����û�����
		printf("���Դ���������Բ��Բ�ĺͰ뾶���Կո��������");
		scanf("%f %f %f %f %f %f",&circle.centerCircle.x,&circle.centerCircle.y,&circle.R,&circle2.centerCircle.x,&circle2.centerCircle.y,&circle2.R);
		//���ú���
		result = Process_5(circle,circle2);
		if(result == 1)	printf("Բ1��%g,%g�� R=%g �� Բ2��%g,%g�� R=%g �ཻ\n",circle.centerCircle.x,circle.centerCircle.y,circle.R,circle2.centerCircle.x,circle2.centerCircle.y,circle2.R);
		else	printf("Բ1��%g,%g�� R=%g �� Բ2��%g,%g�� R=%g ���ཻ\n",circle.centerCircle.x,circle.centerCircle.y,circle.R,circle2.centerCircle.x,circle2.centerCircle.y,circle2.R);
		break;
	default:
		printf("�������󣬳��������\n");
	}

	system("pause");
	return 0;
}