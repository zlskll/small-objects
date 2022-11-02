#define _CRT_SECURE_NO_WARNINGS
#include"declaration.h"
//创建一个动态链表，不用静态的(有现成数据的)了
Stu* Create()
{
    Stu* head = new Stu; //生成头结点
    Stu* p1, * p2;
    int n = 0;
    p1 = p2 = new Stu;                        //开辟新单元，p1,p2指针指向它
    cin >> p1->number >> p1->name >> p1->sex>>p1->score; //首元结点
    //其他结点：
    while (1)
    {
        n++;
        if (n == 1) //p1是首元结点
        {
            head->next = p1; //把头结点和首元结点连起来
        }
        //是表结点
        else
        {
            if (getchar() == '#') {
                break;
            }
            p2->next = p1;//把当前的表结点给接到上一个循环开出来的p2的尾巴上，实现结点连接
        }
        p2 = p1;      //把当前的结点存档，就是连上以后准备搞下一个结点
        p1 = new Stu; //搞下一个结点
        cin >> p1->number >> p1->name >> p1->sex >> p1->score;
    }
    p2->next = NULL; //及时置空
    return (head);   //返回整个链表的头指针
}
//菜单
void menu() {
    cout << "欢迎来到zlskll自编的学生管理系统\n";
    cout << "当前版本号0.0.1\n";
    cout << "您希望做什么？\n";
    cout << "*****1.新建学生信息*****\n";
    cout << "*****2.删除学生信息*****\n";
    cout << "*****3.插入学生信息*****\n";
    cout << "*****4.修改学生信息*****\n";
    cout << "*****0.退出管理系统*****\n";
}
//表头
void PrintChart() {
    cout << "-------------------------------------------------\n";
    cout << "学号\t姓名\t性别\t分数\n";
}
//打印当前链表
void PrintChain(Stu *head) {
    system("cls");
    PrintChart();
    Stu* p_tool = head;
    while (p_tool->next != NULL)
    {
        cout << p_tool->next->number << '\t' << p_tool->next->name << '\t' << p_tool->next->sex <<'\t' << p_tool->next->score << endl;
        p_tool = p_tool->next;
    }
}
//查找信息
void Search(Stu* head, int number) {
    Stu* p = head;
    bool flag = false;//判断找到没
    while (p->next != NULL)
    { //保证p指向的不是NULL
        p = p->next;
        if (p->number == number)
        {
            flag = true;//找到了
            break;
        }
    }
}

//删除链表
void DeleteChain(Stu* head, int delete_number) {
    Stu* pre =NULL;
    Stu* p = head;
    while (p->next != NULL) {
        pre = p;
        p = p->next;
        if (p->number == delete_number) {
            pre->next = p->next;
            p = NULL;
            //delete[] (p);
            break;
        }
    }
}
//插入学生信息
void Insert(Stu* head,int min) {
    Stu* s = new Stu;
    cin >> s->number >> s->name >> s->sex >> s->score;
    Stu* p = head;
    Stu* p_pre = head;
    while (p->next != NULL)
    {
        //下面一小段和删除的代码有点相似，因为都是遍历出来的，都要pre指针工具和p指针工具
        p_pre = p;
        p = p->next;
        //如果是开头
        if (s->number < min)//或者写成p3==NULL ???
        {
            head->next = s;
            s->next = p;
            break;
        }
        else if ((p_pre->number < s->number) && (p->number > s->number))
        {
            p_pre->next = s; //尾接头
            s->next = p;     //尾接头，连接成功
            break;
        }
        else //在结尾
        {
            if (p->next == NULL)
            {
                p->next = s;
                s->next = NULL;
            }
        }
    }

}


int get_min(Stu* head) {
    int min = 0;
    Stu* p = head;
    while (p->next != NULL) {
        min = min > p->next->number ? p->next->number : min;
        p = p->next;
    }
    return min;
}
//打印一下要修改的学生信息
void Print_One_Student(Stu* head, int modify_number) {
    PrintChart();
    Stu* p_tool = head;
    while (p_tool->next != NULL)
    {
        if (p_tool->next->number == modify_number) {
            cout << p_tool->next->number << '\t' << p_tool->next->name << '\t' << p_tool->next->sex << '\t' << p_tool->next->score << endl;
        }
        p_tool = p_tool->next;
    }
};
//确不确定修改
int is_modify(Stu* head) {
    int is_input_modify = 0;
    int modify_number = 0;
    while (1) {
        cout << "请输入想修改的学生的学号:>\n";
        cin >> modify_number;
        cout << "此学生的信息为:\n";
        Print_One_Student(head, modify_number);
        cout << "是否确定修改?:\n";
        cout << "1.确定  2.换个人修改 0.退出修改\n";
        cin >> is_input_modify;
        if (is_input_modify != 2 ) {
            if (is_input_modify == 0) {
                modify_number = 0;
            }
            return modify_number;
        }
        
    }
}
//修改
void modify(Stu* head,int modify_number){
    Stu* p = head;
    bool flag = false;
    do {
        while (p->next != NULL) {
            if (p->next->number == modify_number) {
                flag = true;//找到了
                cout << "请输入改后信息:>\n";
                cin >> p->next->number >> p->next->name >> p->next->sex >> p->next->score;
                break;
            }
            p = p->next;
        }
        if (!flag) {//没找到
            cout << "未查询到该学生信息，无法修改，请重新输入:\n";
        }
    } while (!flag);   
}
