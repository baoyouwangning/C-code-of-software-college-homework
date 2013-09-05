/*
	功能：定义结构体类型及几个函数原型
	作者：wangning
	日期：2013-7-5
*/

//点(x轴，y轴)
typedef struct Point
{
	float x;
	float y;
}Point;

//线(斜截式) 便于计算点到线的距离
typedef struct Line
{
	float A;   //x系数
	float B;   //y系数
	float C;   //常数
}Line;

//圆
typedef struct Circle
{
	Point centerCircle;   //圆心
	float R;             //半径
}Circle;

//矩形
typedef struct Rect      //C语言如何快速表示任意矩形
{
	Point topLeft;		//左上角
	Point lowerRight;		//右下角
}Rect;


//task1:计算两点之间的距离
double Process_1(Point point_1,Point point_2);

//task2:计算一个点到一条直线的距离
float Process_2(Point point,Line line);

//task3:计算一个点是否在圆之内
short Process_3(Point point,Circle circle);

//task4:判断一个点是否在矩形内部
short Process_4(Point point,Rect rect);

//task4:判断两个圆是否相交
short Process_5(Circle circe_1,Circle circle_2);