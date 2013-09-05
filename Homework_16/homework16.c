/*
	���ܣ�5����Ŀ�ĺ���ʵ��
	���ߣ�wangning
	���ڣ�2013-7-6
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "homework16.h"

//task1:��������֮��ľ���
double Process_1(Point point_1,Point point_2)
{
	return sqrt( pow((point_1.x-point_2.x),2) + pow((point_1.y-point_2.y),2) );
}

//task2:����һ���㵽һ��ֱ�ߵľ���
float Process_2(Point point,Line line)
{
	return fabs(line.A*point.x+line.B*point.y+line.C)/sqrt(pow(line.A,2)+pow(line.B,2));
}

//task3:����һ�����Ƿ���Բ֮��
short Process_3(Point point,Circle circle)
{
	float judge =  sqrt( pow(point.x-circle.centerCircle.x,2) + pow(point.y-circle.centerCircle.y,2) );	//�õ㵽Բ�ĵľ���
	if( judge > circle.R ) return 0;		//����Բ��
	else if( judge < circle.R)	return 1;	//����Բ��
	else return -1;           //����Բ��
	
}

//task4:�ж�һ�����Ƿ��ھ����ڲ�
short Process_4(Point point,Rect rect)
{
	if(point.x < rect.lowerRight.x && point.x > rect.topLeft.x && point.y > rect.lowerRight.y && point.y < rect.topLeft.y ) return 1;
	else if( ((point.x == rect.lowerRight.x || point.x == rect.topLeft.x) && point.y > rect.lowerRight.y && point.y < rect.topLeft.y) || ( (point.y == rect.lowerRight.y || point.y == rect.topLeft.y) && point.x < rect.lowerRight.x && point.x > rect.topLeft.x) )	return -1;
	else return 0;
}

//task4:�ж�����Բ�Ƿ��ཻ
short Process_5(Circle circle_1,Circle circle_2)
{
	float distance = sqrt(pow(circle_1.centerCircle.x-circle_2.centerCircle.x,2)+pow(circle_1.centerCircle.y-circle_2.centerCircle.y,2));
	if(distance < circle_1.R+circle_2.R)	return 1;
	else	return 0;
}