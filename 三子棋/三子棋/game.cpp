#define _CRT_SECURE_NO_WARNINGS
#include"game.h"//引了那个常量3
#include<stdio.h>
#include<Windows.h>
//函数的实现:
void game() {
	char board[ROW][COL];//先放一个
	//初始化棋盘：
	InitBoard(board, ROW, COL);//传进去的是数组名，不是数组本身，所以不加[]
	PrintBoard(board, ROW, COL);//打印棋盘
	while (1) {
		printf("你走：>\n");
		PlayerMove(board, ROW, COL);//玩家下棋
		//注意这次下了棋以后不能就这么完了，这只是存入了数据但我们看不见
		//因此再打印一下，才能让玩家看到结果
		PrintBoard(board, ROW, COL);
		char ret = IsWin(board, ROW, COL);
		if (ret == '*') {
			printf("恭喜你绝杀电脑,你太牛b了\n");
			break;//赢了就收
		}
		if (ret == 'P') {
			printf("平局\n");
			break;
		}
		//电脑下棋：
		Sleep(800);
		printf("\n");
		printf("电脑走：>\n");
		ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		char ret2 = IsWin(board, ROW, COL);
		if (ret2 == '#') {
			printf("很抱歉，电脑赢了，你个fw\n");
			break;
		}
		if (ret2 == 'P') {
			printf("平局\n");
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
	for (i = 0; i < row; i++) {//行
		for (j = 0; j < col; j++) {//列
			board[i][j] = ' ';//字符用单引号
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
			printf("\n");//打完一行要换行
		}
	}
}
void  PlayerMove(char board[][COL], int row, int rol) {
	//这是玩家下棋
	int x = 0;
	int y = 0;
	while (1) {
		printf("请输入坐标\n");
		scanf_s("%d%d", &x, &y);//要考虑玩家键盘输入的随机性
		if (x >= 1 && x <= row && y >= 1 && y <= rol) {
			//要考虑到游戏的具体玩法，不要重复输入已经下过了的棋
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("已输入的坐标被占用，请重新输入");
		}
		else
			printf("输入的坐标非法，请重新输入\n");
	}
}
void ComputerMove(char board[][COL], int row, int rol) {
	while (1) {
		int x = rand() % 3;//要生成0—2的随机数
		int y = rand() % 3;
		//得判断棋盘上有没有子了，别吞子
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;//下了棋就要跳出去
		}//发现是个循环
	}
}
char IsWin(char board[][COL], int row, int col) {
	//约定：若玩家赢，则返回*
	//      若电脑赢，则返回#
  //        若平局，则返回P
	//		谁也没赢也没平局，进行下一步

	//先横三行,一行行看，应该用循环
	for (int i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return board[i][1];//非常巧妙的一个点，*就返回*,#就返回#
		}
	}
	//再竖三列，一列列看
	for (int i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			return board[1][i];
		}
	}
	//对角线，两条对角线比较简单，直接写吧
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
		return board[1][1];
	}
	//判断是否平局
	//由于是所有元素都检索一遍，只用if的话不好用，应该用记录版
	//约定： 若是平局则返回1
		  // 若不是平局则返回0
	int ret = IsBalance(board, ROW, COL);
	if (ret == 1) {
		return 'P';//P是字符，要用单引号引起来
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