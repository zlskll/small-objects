#pragma once
//�����Ķ���
#include<stdlib.h>//rand()�Ŀ⺯����ͷ�ļ�
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
//int count = 0;//û�ȵ��ף��ó�����Χ�ж��ٿ���
//int flag = 1;//��;û�вȵ���
int GetMineAmount(char board[ROWS][COLS], int x, int y);
