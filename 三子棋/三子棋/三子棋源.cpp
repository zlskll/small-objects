#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"//引了那个头文件里的声明
int main() {
	int a = 0;
	srand((unsigned int)time(NULL));//生成随机数要有前面的头
	do {
		menu();
		printf("请选择：>\n");
		scanf_s("%d", &a);
		switch (a) {
		case 1:
			printf("三子棋游戏开始\n");
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误，请重试\n");
			break;
		}
	} while (a);
	return 0;
}