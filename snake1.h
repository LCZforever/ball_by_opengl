
#ifndef SNAKE1_H
#define	SNAKE1_H
#include <windows.h>		// 生成窗口。VS须已安装 Windows SDK（部分VC Express不带）
#include <stdio.h>				// 标准输入输出
#include<iostream>
#include <vector>				// std数组
#include<time.h>
#include<stdlib.h>
#include <gl/freeglut.h>		// FreeGLUT（实际使用freeGLUT）
using namespace std;
 void Pos(int x,int y);
 typedef struct node {
	 GLdouble x, y, z;
	 GLdouble red, blue, green;
	 GLdouble radius;
	 struct node *next;
 }NODE;
class snake
{
private:
	NODE * head;	
public:
	snake()
{	
	head=NULL;
}   
	snake(GLdouble X, GLdouble Y,GLdouble Z);
	snake(NODE*b);
	~snake();
void InsertOnein(int i, GLdouble X, GLdouble Y, GLdouble Z, GLdouble BLUE, GLdouble GREEN, GLdouble RED,GLdouble R);
void InsertOnein(int i, GLdouble X, GLdouble Y, GLdouble Z);
int search(int X, int Y);//用坐标来查找链表中的某个坐标信息，并返回它的位置，若找不到则返回-1.
int GetX(int i);
int GetY(int i);
void GetNODE(NODE*b);
void CopyNODEin(NODE*b);
void CopyNODEin(int i, NODE*b);
void CopyNODEout(NODE*b);
void LinkAllin(NODE*b);
void PrintInfofsanke();
void DeleteOne(int i);
void DeleteOne(int i, NODE*e);
int TakeOnePlace(int i,int X,int Y);
void TakeAllPlace(NODE*in);
void BeNullhead();
void DeleteNODE();
int Lenthofsnake();

};
double Rand(double L, double R);
double LiangDianJuLi(double x1, double y1, double z1, double x2, double y2, double z2);
#endif 
