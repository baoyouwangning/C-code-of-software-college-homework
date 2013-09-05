/*
	功能：测试5个题目
	作者：wangning
	日期：2013-7-6
*/
#include <stdio.h>
#include <stdlib.h>
#include "homework16.h"

int main(void)
{
	short choose;

	//接收返回值
	double result;

	//定义一个点
	Point point;
	
	//定义另一个点（task1:计算两点之间的距离）
	Point point2;

	//定义一条直线（task2:计算一个点到一条直线的距离）
	Line line;

	//定义一个圆（task3:计算一个点是否在圆之内）
	Circle circle;

	//定义一个矩形（task4:判断一个点是否在矩形内部）
	Rect rect;  

	//定义另一个圆
	Circle circle2;

	//提示用户选择任务
	printf("任务列表：\n");
	printf("任务1：计算两点之间的距离\n");
	printf("任务2：计算一个点到一条直线的距离\n");
	printf("任务3：计算一个点是否在一个圆之内\n");
	printf("任务4：判断一个点是否在一个矩形内部\n");
	printf("任务5：判断两个圆是否香相交\n");
	printf("请选择（1-5）：");
	
	//接受选择
	scanf("%hd",&choose);

	switch(choose)
	{
	case 1:
		//接受用户输入
		printf("请输入点A的横纵坐标（以空格隔开）：");
		scanf("%f %f",&point.x,&point.y);
		printf("请输入点B的横纵坐标（以空格隔开）：");
		scanf("%f %f",&point2.x,&point2.y);
		//调用函数
		result = Process_1(point,point2);
		//打印结果
		printf("点A（%g,%g）与点B（%g,%g）的距离为 %g\n",point.x,point.y,point2.x,point2.y,result);
		break;
	
	case 2:
		//接收用户输入
		printf("请输入该点的横纵坐标（以空格隔开）：");
		scanf("%f %f",&point.x,&point.y);
		printf("请输入该直线一般式方程X的系数A,Y的系数B,和常数C（以空格隔开）：");
		scanf("%f %f %f",&line.A,&line.B,&line.C);
		//调用函数
		result = Process_2(point,line);
		//打印结果
		printf("点A（%g,%g）到直线 (%g)x+(%g)y+(%g)=0 的距离为 %g\n",point.x,point.y,line.A,line.B,line.C,result);
		break;

	case 3:
		//接受用户输入
		printf("请输入该圆的圆心的横纵坐标和半径（以空格隔开）：");
		scanf("%f %f %f",&circle.centerCircle.x,&circle.centerCircle.y,&circle.R);
		printf("请输入判断点A的横纵坐标（以空格隔开）：");
		scanf("%f %f",&point.x,&point.y);
		//调用函数
		result = Process_3(point,circle);
		//打印结果
		if(result == 0) printf("点A（%g,%g）在以（%g,%g）为圆心R=%g的圆外。\n",point.x,point.y,circle.centerCircle.x,circle.centerCircle.y,circle.R);
		else if(result == 1) printf("点A（%g,%g）在以（%g,%g）为圆心R=%g的圆内。\n",point.x,point.y,circle.centerCircle.x,circle.centerCircle.y,circle.R);
		else  printf("点A（%g,%g）在以（%g,%g）为圆心R=%g的圆上。\n",point.x,point.y,circle.centerCircle.x,circle.centerCircle.y,circle.R);
		break;
	case 4:
		//接受用户输入
		printf("请依次输入该矩形左上角和右下角的横纵坐标（以空格隔开）：");
		scanf("%f %f %f %f",&rect.topLeft.x,&rect.topLeft.y,&rect.lowerRight.x,&rect.lowerRight.y);
		printf("请输入改点A的横纵坐标（以空格隔开）：");
		scanf("%f %f",&point.x,&point.y);
		//调用函数
		result = Process_4(point,rect);
		if(result == 0)	printf("点A（%g,%g）在以（%g,%g）为左上顶点（%g,%g）为右下顶点的矩形外。\n",point.x,point.y,rect.topLeft.x,rect.topLeft.y,rect.lowerRight.x,rect.lowerRight.y);
		else if(result == 1)	printf("点A（%g,%g）在以（%g,%g）为左上顶点（%g,%g）为右下顶点的矩形内。\n",point.x,point.y,rect.topLeft.x,rect.topLeft.y,rect.lowerRight.x,rect.lowerRight.y);
		else printf("点A（%g,%g）在以（%g,%g）为左上顶点（%g,%g）为右下顶点的矩形上。\n",point.x,point.y,rect.topLeft.x,rect.topLeft.y,rect.lowerRight.x,rect.lowerRight.y);
		break;
	case 5:
		//接受用户输入
		printf("请以此输入两个圆的圆心和半径（以空格隔开）：");
		scanf("%f %f %f %f %f %f",&circle.centerCircle.x,&circle.centerCircle.y,&circle.R,&circle2.centerCircle.x,&circle2.centerCircle.y,&circle2.R);
		//调用函数
		result = Process_5(circle,circle2);
		if(result == 1)	printf("圆1（%g,%g） R=%g 与 圆2（%g,%g） R=%g 相交\n",circle.centerCircle.x,circle.centerCircle.y,circle.R,circle2.centerCircle.x,circle2.centerCircle.y,circle2.R);
		else	printf("圆1（%g,%g） R=%g 与 圆2（%g,%g） R=%g 不相交\n",circle.centerCircle.x,circle.centerCircle.y,circle.R,circle2.centerCircle.x,circle2.centerCircle.y,circle2.R);
		break;
	default:
		printf("输入有误，程序结束！\n");
	}

	system("pause");
	return 0;
}