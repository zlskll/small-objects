#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu() {
	printf("**************************\n");
	printf("********  1.play  ********\n");
	printf("********  0.exit  ********\n");
	printf("**************************\n");
}
int main() {
	srand((unsigned int)time(NULL));//这个放到main函数里面
	int input = 0;
	do {
		menu();
		printf("请选择:>\n");
		scanf_s("%d", &input);
		switch (input) {
		case 1:
			printf("扫雷游戏开始\n");
			game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			printf("输入错误，请重试");
			break;
		}
	} while (input);
	return 0;
}
