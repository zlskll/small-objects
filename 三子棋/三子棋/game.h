#pragma once
//ͷ�ļ�����
#include<stdio.h>
#include<time.h>//time�Ŀ⺯����ͷ�ļ�
#include<stdlib.h>//rand�Ŀ⺯����ͷ�ļ�
constexpr auto ROW = 3;//�У��Զ���ľ͸�һ������� �ȽϷ���;;
constexpr auto COL = 3;//��;
//��������
void menu();
void InitBoard(char board[][COL], int row, int col);
void game();          //ֻ��ʡ���У�����ʡ����
void PrintBoard(char board[][COL], int row, int col);
void  PlayerMove(char board[][COL], int row, int rol);
void ComputerMove(char board[][COL],int row,int rol);
char IsWin(char board[][COL], int row, int col);
int IsBalance(char board[][COL], int row, int col);

