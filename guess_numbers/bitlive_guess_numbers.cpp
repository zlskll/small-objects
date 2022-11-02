#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//首先明确实现的目的：
//程序自动生成一个1—100的随机数，然后玩家猜，猜小猜大了都会提示，
//直到猜对结束。
//希望游戏可以反复玩，不想玩可以退出

//时间戳：从1970年到现在所经过的秒数
//C语言中time函数可以返回时间戳，time_t(64位int) time(指针类型)，头文件是time.h
//这样就可以往srand里面传一个一直在变的数了
//但这样也会有个弊端，如果按的太快，srand()里面的数字又一样了，按得太快
//数字又一样了
//所以srand函数只调用一次就可以了，不应该进去一次调用一次
//**？？？**研究srand的起点问题
void menu() {
	printf("******************\n");
	printf("******1.play******\n");
	printf("******0.exit******\n");
	printf("******************\n");
}
void game() {
	int num = 0;
	int ret = rand() % 100 + 1;//生成1——100的数字
	while (1) {
		scanf("%d", &num);
		if (num > ret) {
			printf("------\n");
			printf("猜大了\n");
			printf("------\n");
		}
		if (num < ret) {
			printf("------\n");
			printf("猜小了\n");
			printf("------\n");
		}
		if (num == ret) {
			printf("------\n");
			printf("恭喜你，猜对了\n");
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
		//打印菜单
		menu();
		printf("请选择：>\n");
		scanf("%d", &input);
		switch (input) {
		case 1://猜数字
			printf("请输入数字：<\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重试\n");
			break;
		}
	} while (input);
	//要写一步测试一步
	return 0;
}




//goto语句：
//C语言提供了可以滥用的goto语句和跳转的标记flag
//只能在同一个函数内部跳转，不能跨函数跳转
//理论上goto语句是没有必要的，所以尽量少用
// 但它有它的应用场景，例如：
//     1.在某些深度嵌套的结构的处理过程。(有好多个循环，写很多break不好用)
//     2.某些具体场景，例如下面的关机程序
//关机程序：
//程序目的——程序执行起来就倒计时关机，如果输入“我是猪”可以取消关机
//涉及cmd指令shutdown  -s(关机)  -t(设置时间)  60  60单位是秒
// shutdown   -a 取消了关机
//shutdown百度百科
//#include<string.h>
//int main() {
//	system("shutdown -s -t 120");
//	char input[20] = { 0 };//输入的一串字符
//	printf("你的电脑将会在60秒后关机，如果输入我是猪，就给你取消关机\n");
//again:
//	scanf("%s", input);
//	if (strcmp(input, "我是猪") == 0) {
//		printf("猪头，这就给你取消关机\n");
//		system("shutdown -a");
//	}
//	else {
//		printf("不听话，是不是不听话，不输我就给你关\n");
//		goto again;
//	}
//
//	return 0;
//}




//char虽然叫字符类型，但字符的存储是ASCII码值，是整数，所以char也是整形家族的。
//关于switch说法不正确的是：（ C ）
//A.switch语句中的default子句可以放在任意位置
//B.switch语句中case后的表达式只能是整形常量表达式
//C.switch语句中case子句必须在default子句之前
//D.switch语句中case表达式不要求顺序
//    C没有规定说case一定要在default之前，只是最好那么建议
//    D确实是不要求，一般还是按顺序来，但没说一定是谁在前谁在后




//判断素数：注意，这个是有优化的
//#include<math.h>
//int main() {
//	int i = 0;
//	int n = 0;
//	bool flag = true;//判断最好用bool型，一目了然
//	scanf("%d", &n);
//	2是特殊情况，它是素数
//	if (n == 1) {
//		flag = false;
//	}
//	for (i = 2; i < sqrt(n); i++) {
//		if (n % i == 0) {//不是素数
//			flag = false;
//			break;
//		}
//	}
//	if (flag) {
//		printf("是素数\n");
//	}
//	else
//		printf("不是素数\n");
//
//
//	return 0;
//}