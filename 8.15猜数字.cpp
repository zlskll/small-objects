#include<stdio.h>//一般打印的头文件 
#include<stdlib.h> //rand那个头文件 
#include<time.h>//时间戳那个time函数的头文件 
void game(){//void是没有返回值 
	int c = 0;
	int ret = rand()%100+1;//取模100为0~99，+1为1~100 
	while(1){//用死循环可以一直重玩 
		scanf("%d",&c);
		if(c < ret){
			printf("猜小了\n");
		}
		else if(c > ret){
			printf("猜大了\n");
		}
		else {//记得加括号，不加括号的话不知道break是在哪的 就直接跳出去了 
		    printf("恭喜你，猜对了\n");
		    break;//猜对了跳出去 括号！！ 
			}
	}
}
void menu(){
	printf("***请选择********\n");
	printf("***1.开始********\n");
	printf("***0.退出********\n");
	printf("*****************\n");
}
int main(){
	int i = 0;
	printf("欢迎进入猜数字游戏\n");
	printf("本游戏规则为：\n");
	printf("猜一个1-100的数字\n"); 
	printf("如果猜对了那么恭喜你猜对啦\n"); 
	printf("如果猜错了会提示猜错情况\n"); 
	do{//上来就玩一次 所以用do while 
		srand((unsigned int)time(NULL));//用时间戳这个一直在变的量搞出随机值 
		int c = 0;//srand要在rand之前 要不然不够随机 
		menu();
		scanf("%d",&i);
		switch(i){
			case 1:
			   printf("请猜数字：\n");
			   game();
			   break;
			case 0:
			   printf("退出程序\n");
			   break; 
			default://这也要有冒号 
			   printf("输入错误，没这个选项\n");
			   break;
			   }
	} 
	while(i);//i为0即为假 就进行不下去循环了，i非0就继续进行 
	return 0;
}
