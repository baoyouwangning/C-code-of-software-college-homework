/*
	功能：5个题目的函数实体
	作者：wangning
	日期：2013-7-6
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "homework16.h"

//task1:计算两点之间的距离
double Process_1(Point point_1,Point point_2)
{
	return sqrt( pow((point_1.x-point_2.x),2) + pow((point_1.y-point_2.y),2) );
}

//task2:计算一个点到一条直线的距离
float Process_2(Point point,Line line)
{
	return fabs(line.A*point.x+line.B*point.y+line.C)/sqrt(pow(line.A,2)+pow(line.B,2));
}

//task3:计算一个点是否在圆之内
short Process_3(Point point,Circle circle)
{
	float judge =  sqrt( pow(point.x-circle.centerCircle.x,2) + pow(point.y-circle.centerCircle.y,2) );	//该点到圆心的距离
	if( judge > circle.R ) return 0;		//点在圆外
	else if( judge < circle.R)	return 1;	//点在圆内
	else return -1;           //点在圆上
	
}

//task4:判断一个点是否在矩形内部
short Process_4(Point point,Rect rect)
{
	if(point.x < rect.lowerRight.x && point.x > rect.topLeft.x && point.y > rect.lowerRight.y && point.y < rect.topLeft.y ) return 1;
	else if( ((point.x == rect.lowerRight.x || point.x == rect.topLeft.x) && point.y > rect.lowerRight.y && point.y < rect.topLeft.y) || ( (point.y == rect.lowerRight.y || point.y == rect.topLeft.y) && point.x < rect.lowerRight.x && point.x > rect.topLeft.x) )	return -1;
	else return 0;
}

//task4:判断两个圆是否相交
short Process_5(Circle circle_1,Circle circle_2)
{
	float distance = sqrt(pow(circle_1.centerCircle.x-circle_2.centerCircle.x,2)+pow(circle_1.centerCircle.y-circle_2.centerCircle.y,2));
	if(distance < circle_1.R+circle_2.R)	return 1;
	else	return 0;
}