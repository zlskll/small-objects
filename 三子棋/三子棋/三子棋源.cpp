#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"//�����Ǹ�ͷ�ļ��������
int main() {
	int a = 0;
	srand((unsigned int)time(NULL));//���������Ҫ��ǰ���ͷ
	do {
		menu();
		printf("��ѡ��>\n");
		scanf_s("%d", &a);
		switch (a) {
		case 1:
			printf("��������Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("�������������\n");
			break;
		}
	} while (a);
	return 0;
}