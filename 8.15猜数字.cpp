#include<stdio.h>//һ���ӡ��ͷ�ļ� 
#include<stdlib.h> //rand�Ǹ�ͷ�ļ� 
#include<time.h>//ʱ����Ǹ�time������ͷ�ļ� 
void game(){//void��û�з���ֵ 
	int c = 0;
	int ret = rand()%100+1;//ȡģ100Ϊ0~99��+1Ϊ1~100 
	while(1){//����ѭ������һֱ���� 
		scanf("%d",&c);
		if(c < ret){
			printf("��С��\n");
		}
		else if(c > ret){
			printf("�´���\n");
		}
		else {//�ǵü����ţ��������ŵĻ���֪��break�����ĵ� ��ֱ������ȥ�� 
		    printf("��ϲ�㣬�¶���\n");
		    break;//�¶�������ȥ ���ţ��� 
			}
	}
}
void menu(){
	printf("***��ѡ��********\n");
	printf("***1.��ʼ********\n");
	printf("***0.�˳�********\n");
	printf("*****************\n");
}
int main(){
	int i = 0;
	printf("��ӭ�����������Ϸ\n");
	printf("����Ϸ����Ϊ��\n");
	printf("��һ��1-100������\n"); 
	printf("����¶�����ô��ϲ��¶���\n"); 
	printf("����´��˻���ʾ�´����\n"); 
	do{//��������һ�� ������do while 
		srand((unsigned int)time(NULL));//��ʱ������һֱ�ڱ����������ֵ 
		int c = 0;//srandҪ��rand֮ǰ Ҫ��Ȼ������� 
		menu();
		scanf("%d",&i);
		switch(i){
			case 1:
			   printf("������֣�\n");
			   game();
			   break;
			case 0:
			   printf("�˳�����\n");
			   break; 
			default://��ҲҪ��ð�� 
			   printf("�������û���ѡ��\n");
			   break;
			   }
	} 
	while(i);//iΪ0��Ϊ�� �ͽ��в���ȥѭ���ˣ�i��0�ͼ������� 
	return 0;
}
