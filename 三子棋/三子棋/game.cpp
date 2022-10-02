#define _CRT_SECURE_NO_WARNINGS
#include"game.h"//�����Ǹ�����3
#include<stdio.h>
#include<Windows.h>
//������ʵ��:
void game() {
	char board[ROW][COL];//�ȷ�һ��
	//��ʼ�����̣�
	InitBoard(board, ROW, COL);//����ȥ�������������������鱾�����Բ���[]
	PrintBoard(board, ROW, COL);//��ӡ����
	while (1) {
		printf("���ߣ�>\n");
		PlayerMove(board, ROW, COL);//�������
		//ע������������Ժ��ܾ���ô���ˣ���ֻ�Ǵ��������ݵ����ǿ�����
		//����ٴ�ӡһ�£���������ҿ������
		PrintBoard(board, ROW, COL);
		char ret = IsWin(board, ROW, COL);
		if (ret == '*') {
			printf("��ϲ���ɱ����,��̫ţb��\n");
			break;//Ӯ�˾���
		}
		if (ret == 'P') {
			printf("ƽ��\n");
			break;
		}
		//�������壺
		Sleep(800);
		printf("\n");
		printf("�����ߣ�>\n");
		ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		char ret2 = IsWin(board, ROW, COL);
		if (ret2 == '#') {
			printf("�ܱ�Ǹ������Ӯ�ˣ����fw\n");
			break;
		}
		if (ret2 == 'P') {
			printf("ƽ��\n");
			break;
		}
	}
	
}
void menu() {
	printf("***************************\n");
	printf("********   1.play   *******\n");
	printf("********   0.exit   *******\n");
	printf("***************************\n");

}
void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {//��
		for (j = 0; j < col; j++) {//��
			board[i][j] = ' ';//�ַ��õ�����
		}
	}
}
void PrintBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			int j = 0;
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");//����һ��Ҫ����
		}
	}
}
void  PlayerMove(char board[][COL], int row, int rol) {
	//�����������
	int x = 0;
	int y = 0;
	while (1) {
		printf("����������\n");
		scanf_s("%d%d", &x, &y);//Ҫ������Ҽ�������������
		if (x >= 1 && x <= row && y >= 1 && y <= rol) {
			//Ҫ���ǵ���Ϸ�ľ����淨����Ҫ�ظ������Ѿ��¹��˵���
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("����������걻ռ�ã�����������");
		}
		else
			printf("���������Ƿ�������������\n");
	}
}
void ComputerMove(char board[][COL], int row, int rol) {
	while (1) {
		int x = rand() % 3;//Ҫ����0��2�������
		int y = rand() % 3;
		//���ж���������û�����ˣ�������
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;//�������Ҫ����ȥ
		}//�����Ǹ�ѭ��
	}
}
char IsWin(char board[][COL], int row, int col) {
	//Լ���������Ӯ���򷵻�*
	//      ������Ӯ���򷵻�#
  //        ��ƽ�֣��򷵻�P
	//		˭ҲûӮҲûƽ�֣�������һ��

	//�Ⱥ�����,һ���п���Ӧ����ѭ��
	for (int i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return board[i][1];//�ǳ������һ���㣬*�ͷ���*,#�ͷ���#
		}
	}
	//�������У�һ���п�
	for (int i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			return board[1][i];
		}
	}
	//�Խ��ߣ������Խ��߱Ƚϼ򵥣�ֱ��д��
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
		return board[1][1];
	}
	//�ж��Ƿ�ƽ��
	//����������Ԫ�ض�����һ�飬ֻ��if�Ļ������ã�Ӧ���ü�¼��
	//Լ���� ����ƽ���򷵻�1
		  // ������ƽ���򷵻�0
	int ret = IsBalance(board, ROW, COL);
	if (ret == 1) {
		return 'P';//P���ַ���Ҫ�õ�����������
	}
}
int IsBalance(char board[][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}