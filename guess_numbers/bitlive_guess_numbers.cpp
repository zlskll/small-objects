#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//������ȷʵ�ֵ�Ŀ�ģ�
//�����Զ�����һ��1��100���������Ȼ����Ҳ£���С�´��˶�����ʾ��
//ֱ���¶Խ�����
//ϣ����Ϸ���Է����棬����������˳�

//ʱ�������1970�굽����������������
//C������time�������Է���ʱ�����time_t(64λint) time(ָ������)��ͷ�ļ���time.h
//�����Ϳ�����srand���洫һ��һֱ�ڱ������
//������Ҳ���и��׶ˣ��������̫�죬srand()�����������һ���ˣ�����̫��
//������һ����
//����srand����ֻ����һ�ξͿ����ˣ���Ӧ�ý�ȥһ�ε���һ��
//**������**�о�srand���������
void menu() {
	printf("******************\n");
	printf("******1.play******\n");
	printf("******0.exit******\n");
	printf("******************\n");
}
void game() {
	int num = 0;
	int ret = rand() % 100 + 1;//����1����100������
	while (1) {
		scanf("%d", &num);
		if (num > ret) {
			printf("------\n");
			printf("�´���\n");
			printf("------\n");
		}
		if (num < ret) {
			printf("------\n");
			printf("��С��\n");
			printf("------\n");
		}
		if (num == ret) {
			printf("------\n");
			printf("��ϲ�㣬�¶���\n");
			printf("------\n");
			break;
		}
	}
}
int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		//��ӡ�˵�
		menu();
		printf("��ѡ��>\n");
		scanf("%d", &input);
		switch (input) {
		case 1://������
			printf("���������֣�<\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������\n");
			break;
		}
	} while (input);
	//Ҫдһ������һ��
	return 0;
}




//goto��䣺
//C�����ṩ�˿������õ�goto������ת�ı��flag
//ֻ����ͬһ�������ڲ���ת�����ܿ纯����ת
//������goto�����û�б�Ҫ�ģ����Ծ�������
// ����������Ӧ�ó��������磺
//     1.��ĳЩ���Ƕ�׵Ľṹ�Ĵ�����̡�(�кö��ѭ����д�ܶ�break������)
//     2.ĳЩ���峡������������Ĺػ�����
//�ػ�����
//����Ŀ�ġ�������ִ�������͵���ʱ�ػ���������롰����������ȡ���ػ�
//�漰cmdָ��shutdown  -s(�ػ�)  -t(����ʱ��)  60  60��λ����
// shutdown   -a ȡ���˹ػ�
//shutdown�ٶȰٿ�
//#include<string.h>
//int main() {
//	system("shutdown -s -t 120");
//	char input[20] = { 0 };//�����һ���ַ�
//	printf("��ĵ��Խ�����60���ػ�����������������͸���ȡ���ػ�\n");
//again:
//	scanf("%s", input);
//	if (strcmp(input, "������") == 0) {
//		printf("��ͷ����͸���ȡ���ػ�\n");
//		system("shutdown -a");
//	}
//	else {
//		printf("���������ǲ��ǲ������������Ҿ͸����\n");
//		goto again;
//	}
//
//	return 0;
//}




//char��Ȼ���ַ����ͣ����ַ��Ĵ洢��ASCII��ֵ��������������charҲ�����μ���ġ�
//����switch˵������ȷ���ǣ��� C ��
//A.switch����е�default�Ӿ���Է�������λ��
//B.switch�����case��ı��ʽֻ�������γ������ʽ
//C.switch�����case�Ӿ������default�Ӿ�֮ǰ
//D.switch�����case���ʽ��Ҫ��˳��
//    Cû�й涨˵caseһ��Ҫ��default֮ǰ��ֻ�������ô����
//    Dȷʵ�ǲ�Ҫ��һ�㻹�ǰ�˳��������û˵һ����˭��ǰ˭�ں�




//�ж�������ע�⣬��������Ż���
//#include<math.h>
//int main() {
//	int i = 0;
//	int n = 0;
//	bool flag = true;//�ж������bool�ͣ�һĿ��Ȼ
//	scanf("%d", &n);
//	2�������������������
//	if (n == 1) {
//		flag = false;
//	}
//	for (i = 2; i < sqrt(n); i++) {
//		if (n % i == 0) {//��������
//			flag = false;
//			break;
//		}
//	}
//	if (flag) {
//		printf("������\n");
//	}
//	else
//		printf("��������\n");
//
//
//	return 0;
//}