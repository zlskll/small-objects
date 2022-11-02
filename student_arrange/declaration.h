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

//菜单：
void menu();
//表头
void PrintChart();
//创造一个链表
Stu* Create();
//打印当前链表
void PrintChain(Stu* p);
//删除链表
void DeleteChain(Stu* head, int delete_number);
//
int get_min(Stu* head);
//插入学生信息
void Insert(Stu* head,int min);
//打印要修改的学生信息
void Print_One_Student(Stu* head, int modify_number);
//修改的时候确不确定
int is_modify(Stu* head);
//修改信息
void modify(Stu* head,int modify_number);