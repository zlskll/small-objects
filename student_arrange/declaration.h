#pragma once
#include<iostream>
using namespace std;
struct Stu
{
    int number;
    char name[10];
    char sex[10];
    double score;
    Stu* next; 
};

//�˵���
void menu();
//��ͷ
void PrintChart();
//����һ������
Stu* Create();
//��ӡ��ǰ����
void PrintChain(Stu* p);
//ɾ������
void DeleteChain(Stu* head, int delete_number);
//
int get_min(Stu* head);
//����ѧ����Ϣ
void Insert(Stu* head,int min);
//��ӡҪ�޸ĵ�ѧ����Ϣ
void Print_One_Student(Stu* head, int modify_number);
//�޸ĵ�ʱ��ȷ��ȷ��
int is_modify(Stu* head);
//�޸���Ϣ
void modify(Stu* head,int modify_number);