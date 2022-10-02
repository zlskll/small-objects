#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
//������ʵ��
#include"game.h"
int flag = 1;//��;û�вȵ���
void colorhead(int i) {
	if (i + 1 == 1)
		printf("\033[34m1 \033[0m");
	if (i + 1 == 2)
		printf("\033[34m2 \033[0m");
	if (i + 1 == 3)
		printf("\033[34m3 \033[0m");
	if (i + 1 == 4)
		printf("\033[34m4 \033[0m");
	if (i + 1 == 5)
		printf("\033[34m5 \033[0m");
	if (i + 1 == 6)
		printf("\033[34m6 \033[0m");
	if (i + 1 == 7)
		printf("\033[34m7 \033[0m");
	if (i + 1 == 8)
		printf("\033[34m8 \033[0m");
	if (i + 1 == 9)
		printf("\033[34m9 \033[0m");
}
void game() {
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	InitBoard(mine, ROWS, COLS, '0');//��ʼ�����ݲ�ͬ�����Ǳ��һ�����Ϳ����������
	InitBoard(show, ROWS, COLS, '*');
	MineBoard(mine, ROW, COL);//����
	int win = 0;
	while (1) {
		PrintBoard(mine, ROW, COL);//����ȥ����11�����飬���Ҿʹ�ӡ9�еģ���ֹԽ��
		PrintBoard(show, ROW, COL);
		printf("���������꣺>\n");
		InspectBoard(mine, show, ROW, COL);
		if (flag == 0) {
			break;
		}
		else
			win++;
		if (win >= ROW * COL - 10) {
			PrintBoard(mine, ROW, COL);
			printf("��ϲ�㣬���׳ɹ�\n");
			break;
		}
	}
}
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}
void PrintBoard(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	printf("---------ɨ����Ϸ----------\n");
	printf("\033[34m0 1 2 3 4 5 6 7 8 9\n\033[0m");
	for (i = 0; i < row; i++) {
		colorhead(i);
		for (j = 0; j < col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");//����һ�мǵû���
	}
	printf("---------ɨ����Ϸ----------\n");
}
void MineBoard(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	for (i = 0; i < 10; i++) {//����ʮ����
		while (1) {
			int x = rand() % 9;//�������0-8������
			int y = rand() % 9;
			if (board[x][y] == '0') {//��ֹ���ɵ������һ���ˣ��Ͳ���ʮ������
				board[x][y] = '1';
				break;
			}
		}
	}
}
//һ�������ǿ��Դ����������
void InspectBoard(char board[ROWS][COLS], char showboard[ROWS][COLS], int row, int col) {
	//û�ȵ��ף��ó�����Χ�ж��ٿ���,��Ҫ�ų�ȫ�ֱ�����������ۻ�����
	int x = 0;
	int y = 0;
	while (1) {
	    scanf_s("%d%d", &x, &y);//ע��������������������
		if (x <= row && x >= 1 && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == '1') {//ע������Ҳ����ν�Ķ�����Ҫ��Ȼ��д��������Ч��
				printf("��ȵ��������Ѿ���ը��������Ϸ����\n");
				printf("\033[31m���������Ŀ���������� \033[0m");
				PrintBoard(board, row, col);
				flag = 0; //�ȵ�����
					break; //�ȵ�������ѭ��
			}
			else if (board[x - 1][y - 1] == '0') {
				
				int count = GetMineAmount(board, x, y);
				//Ȼ���������Ϣ��countֵ�����ڶ���show����
				//������������Щ��Ϣ����,����
				showboard[x-1][y-1] = count + '0';//����48����'0'����ת��,��Ϊ'0'��Ӧ��ASCII�����48
				break;
			}
		}
		else
			printf("���������������������\n");
	}
}
int GetMineAmount(char board[ROWS][COLS], int x, int y) {
	//1.��ͨѭ������
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			if (board[x - 1 + i][y - 1 + j] == '1') {
				count++;
			}
		}
	}
	return count;
	//2.����0  1����Խ�ԵĴ���
	//return board[x - 1][y - 1] +
	//	board[x - 1][y] +
	//	board[x - 1][y + 1] +
	//	board[x][y - 1] +
	//	board[x][y + 1] +
	//	board[x + 1][y - 1] +
	//	board[x + 1][y] +
	//	board[x + 1][y + 1] - (8 * '0');//return������������
}
