#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu() {
	printf("**************************\n");
	printf("********  1.play  ********\n");
	printf("********  0.exit  ********\n");
	printf("**************************\n");
}
int main() {
	srand((unsigned int)time(NULL));//����ŵ�main��������
	int input = 0;
	do {
		menu();
		printf("��ѡ��:>\n");
		scanf_s("%d", &input);
		switch (input) {
		case 1:
			printf("ɨ����Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("��Ϸ�˳�\n");
			break;
		default:
			printf("�������������");
			break;
		}
	} while (input);
	return 0;
}
