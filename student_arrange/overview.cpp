#define _CRT_SECURE_NO_WARNINGS
#include"declaration.h"
using namespace std;
int main() {
    int input = 1;
    int delete_number = 0;
    int modify_number = 0;
    int is_input_modify = 0;
    Stu* head = NULL;
    do{
        menu();
        cin.clear();
        cin >> input;
        switch (input)
        {
        case 1://新建一个链表
            PrintChart();
            cout << "请输入学生信息(tips:添加完成后输入‘#’+回车可退出添加)\n";
            cout << "输入范例:  2202 李焱楠 男 100\n";
            head = Create();
            PrintChain(head);
            system("pause");
            break;
        case 2://删除信息
            cout << "请输入删除学生的学号:>\n";
            cin >> delete_number;
            DeleteChain(head,delete_number);
            PrintChain(head);
            system("pause");
            break;
        case 3://插入信息
            cout << "请输入插入学生的信息\n";
            Insert(head, get_min(head));
            cout << "删除成功\n";
            PrintChart();
            PrintChain(head);
            system("pause");
            break;
        case 4://修改信息
            PrintChart();
            PrintChain(head);
            is_input_modify = is_modify(head);
            switch (is_input_modify) {
            case 0://退出修改
                cout << "退出修改成功\n";
                break;
            default://确定修改
                modify(head, is_input_modify);
                cout << "修改成功，修改后的信息为：\n";
                PrintChart();
                PrintChain(head);
                system("pause");
                break;
            }
            break;
        case 0:
            cout << "退出成功\n";
            break;
        default:
            cout << "输入错误，请重新输入\n";
            break;
        }
    } while (input);
    return 0;
}