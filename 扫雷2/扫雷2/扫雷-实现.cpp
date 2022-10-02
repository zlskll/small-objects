#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
//函数的实现
#include"game.h"
int flag = 1;//中途没有踩到雷
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
	InitBoard(mine, ROWS, COLS, '0');//初始化内容不同，但是别的一样，就可以巧妙传个参
	InitBoard(show, ROWS, COLS, '*');
	MineBoard(mine, ROW, COL);//布雷
	int win = 0;
	while (1) {
		PrintBoard(mine, ROW, COL);//传进去的是11行数组，但我就打印9行的，防止越界
		PrintBoard(show, ROW, COL);
		printf("请输入坐标：>\n");
		InspectBoard(mine, show, ROW, COL);
		if (flag == 0) {
			break;
		}
		else
			win++;
		if (win >= ROW * COL - 10) {
			PrintBoard(mine, ROW, COL);
			printf("恭喜你，排雷成功\n");
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
	printf("---------扫雷游戏----------\n");
	printf("\033[34m0 1 2 3 4 5 6 7 8 9\n\033[0m");
	for (i = 0; i < row; i++) {
		colorhead(i);
		for (j = 0; j < col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");//打完一行记得换行
	}
	printf("---------扫雷游戏----------\n");
}
void MineBoard(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	for (i = 0; i < 10; i++) {//生成十个雷
		while (1) {
			int x = rand() % 9;//生成随机0-8的数字
			int y = rand() % 9;
			if (board[x][y] == '0') {//防止生成的随机数一样了，就不够十个雷了
				board[x][y] = '1';
				break;
			}
		}
	}
}
//一个函数是可以传两个数组的
void InspectBoard(char board[ROWS][COLS], char showboard[ROWS][COLS], int row, int col) {
	//没踩到雷，得出了周围有多少颗雷,不要放成全局变量，否则会累积计数
	int x = 0;
	int y = 0;
	while (1) {
	    scanf_s("%d%d", &x, &y);//注意输入的数字是人输入的
		if (x <= row && x >= 1 && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == '1') {//注意数组也有所谓的定义域，要不然读写的数据无效了
				printf("你踩到雷辣，已经被炸死辣，游戏结束\n");
				printf("\033[31m让你死个瞑目，上雷区！ \033[0m");
				PrintBoard(board, row, col);
				flag = 0; //踩到雷了
					break; //踩到雷跳出循环
			}
			else if (board[x - 1][y - 1] == '0') {
				
				int count = GetMineAmount(board, x, y);
				//然后把坐标信息和count值传给第二个show数组
				//在这个函数里，这些信息都在,完美
				showboard[x-1][y-1] = count + '0';//加上48或者'0'都能转化,因为'0'对应的ASCII码就是48
				break;
			}
		}
		else
			printf("输入错误，请重新输入坐标\n");
	}
}
int GetMineAmount(char board[ROWS][COLS], int x, int y) {
	//1.普通循环算数
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
	//2.体现0  1的优越性的代码
	//return board[x - 1][y - 1] +
	//	board[x - 1][y] +
	//	board[x - 1][y + 1] +
	//	board[x][y - 1] +
	//	board[x][y + 1] +
	//	board[x + 1][y - 1] +
	//	board[x + 1][y] +
	//	board[x + 1][y + 1] - (8 * '0');//return出来的是数字
}
