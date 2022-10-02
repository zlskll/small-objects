#pragma once
//头文件包含
#include<stdio.h>
#include<time.h>//time的库函数引头文件
#include<stdlib.h>//rand的库函数引头文件
constexpr auto ROW = 3;//行，自定义的就改一遍就行了 比较方便;;
constexpr auto COL = 3;//列;
//函数声明
void menu();
void InitBoard(char board[][COL], int row, int col);
void game();          //只能省略行，不能省略列
void PrintBoard(char board[][COL], int row, int col);
void  PlayerMove(char board[][COL], int row, int rol);
void ComputerMove(char board[][COL],int row,int rol);
char IsWin(char board[][COL], int row, int col);
int IsBalance(char board[][COL], int row, int col);

