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
        case 1://�½�һ������
            PrintChart();
            cout << "������ѧ����Ϣ(tips:�����ɺ����롮#��+�س����˳����)\n";
            cout << "���뷶��:  2202 ����� �� 100\n";
            head = Create();
            PrintChain(head);
            system("pause");
            break;
        case 2://ɾ����Ϣ
            cout << "������ɾ��ѧ����ѧ��:>\n";
            cin >> delete_number;
            DeleteChain(head,delete_number);
            PrintChain(head);
            system("pause");
            break;
        case 3://������Ϣ
            cout << "���������ѧ������Ϣ\n";
            Insert(head, get_min(head));
            cout << "ɾ���ɹ�\n";
            PrintChart();
            PrintChain(head);
            system("pause");
            break;
        case 4://�޸���Ϣ
            PrintChart();
            PrintChain(head);
            is_input_modify = is_modify(head);
            switch (is_input_modify) {
            case 0://�˳��޸�
                cout << "�˳��޸ĳɹ�\n";
                break;
            default://ȷ���޸�
                modify(head, is_input_modify);
                cout << "�޸ĳɹ����޸ĺ����ϢΪ��\n";
                PrintChart();
                PrintChain(head);
                system("pause");
                break;
            }
            break;
        case 0:
            cout << "�˳��ɹ�\n";
            break;
        default:
            cout << "�����������������\n";
            break;
        }
    } while (input);
    return 0;
}