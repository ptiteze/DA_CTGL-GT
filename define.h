//khai báo thu vien
#include<iostream>
#include<fstream>
#include <string>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <iomanip>

//
#include<windows.h>
#define khungdoc 219
#define khungngang 223
#define xMenu 1
#define yMenu1 2
#define wMenu 27
#define hMenu 2
#define mauchu 2
#define distance 4
#define maubg  7
#define maubgs 110
#define DOWN -80
#define UP -72
#define LEFT -75
#define RIGHT -77
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define SPACE 32
#define F1 -59
#define F2 -60
#define F3 -61
#define F5 -63
//
using namespace std;
//
void boxmenu(int x,int y, int w,int h,int c_text,int c_bg,char t[]);
void chaymenu(char menu[][25]);
void GhiChu(char c[], int x, int y, int color, int sleep);
void chaymenumh();
void chaymenultc();
void chaymenusv();
 void chaymenudiem();


