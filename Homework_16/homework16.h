/*
	���ܣ�����ṹ�����ͼ���������ԭ��
	���ߣ�wangning
	���ڣ�2013-7-5
*/

//��(x�ᣬy��)
typedef struct Point
{
	float x;
	float y;
}Point;

//��(б��ʽ) ���ڼ���㵽�ߵľ���
typedef struct Line
{
	float A;   //xϵ��
	float B;   //yϵ��
	float C;   //����
}Line;

//Բ
typedef struct Circle
{
	Point centerCircle;   //Բ��
	float R;             //�뾶
}Circle;

//����
typedef struct Rect      //C������ο��ٱ�ʾ�������
{
	Point topLeft;		//���Ͻ�
	Point lowerRight;		//���½�
}Rect;


//task1:��������֮��ľ���
double Process_1(Point point_1,Point point_2);

//task2:����һ���㵽һ��ֱ�ߵľ���
float Process_2(Point point,Line line);

//task3:����һ�����Ƿ���Բ֮��
short Process_3(Point point,Circle circle);

//task4:�ж�һ�����Ƿ��ھ����ڲ�
short Process_4(Point point,Rect rect);

//task4:�ж�����Բ�Ƿ��ཻ
short Process_5(Circle circe_1,Circle circle_2);