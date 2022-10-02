#pragma once
//函数的定义
#include<stdlib.h>//rand()的库函数的头文件
#include<stdio.h>
#include<string.h>
#include<time.h>
constexpr int  ROW = 9;
constexpr int  COL = 9;
constexpr int  ROWS = (9 + 2);
constexpr int  COLS = (9 + 2);
void game();
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void PrintBoard(char board[ROWS][COLS], int row, int col);
void colorhead(int i);
void MineBoard(char board[ROWS][COLS], int row, int col);
void InspectBoard(char board[ROWS][COLS], char showboard[ROWS][COLS], int row, int col);
//int count = 0;//没踩到雷，得出了周围有多少颗雷
//int flag = 1;//中途没有踩到雷
int GetMineAmount(char board[ROWS][COLS], int x, int y);
