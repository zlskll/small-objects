#define _CRT_SECURE_NO_WARNINGS
#include"declaration.h"
//����һ����̬�������þ�̬��(���ֳ����ݵ�)��
Stu* Create()
{
    Stu* head = new Stu; //����ͷ���
    Stu* p1, * p2;
    int n = 0;
    p1 = p2 = new Stu;                        //�����µ�Ԫ��p1,p2ָ��ָ����
    cin >> p1->number >> p1->name >> p1->sex>>p1->score; //��Ԫ���
    //������㣺
    while (1)
    {
        n++;
        if (n == 1) //p1����Ԫ���
        {
            head->next = p1; //��ͷ������Ԫ���������
        }
        //�Ǳ���
        else
        {
            if (getchar() == '#') {
                break;
            }
            p2->next = p1;//�ѵ�ǰ�ı�����ӵ���һ��ѭ����������p2��β���ϣ�ʵ�ֽ������
        }
        p2 = p1;      //�ѵ�ǰ�Ľ��浵�����������Ժ�׼������һ�����
        p1 = new Stu; //����һ�����
        cin >> p1->number >> p1->name >> p1->sex >> p1->score;
    }
    p2->next = NULL; //��ʱ�ÿ�
    return (head);   //�������������ͷָ��
}
//�˵�
void menu() {
    cout << "��ӭ����zlskll�Ա��ѧ������ϵͳ\n";
    cout << "��ǰ�汾��0.0.1\n";
    cout << "��ϣ����ʲô��\n";
    cout << "*****1.�½�ѧ����Ϣ*****\n";
    cout << "*****2.ɾ��ѧ����Ϣ*****\n";
    cout << "*****3.����ѧ����Ϣ*****\n";
    cout << "*****4.�޸�ѧ����Ϣ*****\n";
    cout << "*****0.�˳�����ϵͳ*****\n";
}
//��ͷ
void PrintChart() {
    cout << "-------------------------------------------------\n";
    cout << "ѧ��\t����\t�Ա�\t����\n";
}
//��ӡ��ǰ����
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
//������Ϣ
void Search(Stu* head, int number) {
    Stu* p = head;
    bool flag = false;//�ж��ҵ�û
    while (p->next != NULL)
    { //��֤pָ��Ĳ���NULL
        p = p->next;
        if (p->number == number)
        {
            flag = true;//�ҵ���
            break;
        }
    }
}

//ɾ������
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
//����ѧ����Ϣ
void Insert(Stu* head,int min) {
    Stu* s = new Stu;
    cin >> s->number >> s->name >> s->sex >> s->score;
    Stu* p = head;
    Stu* p_pre = head;
    while (p->next != NULL)
    {
        //����һС�κ�ɾ���Ĵ����е����ƣ���Ϊ���Ǳ��������ģ���Ҫpreָ�빤�ߺ�pָ�빤��
        p_pre = p;
        p = p->next;
        //����ǿ�ͷ
        if (s->number < min)//����д��p3==NULL ???
        {
            head->next = s;
            s->next = p;
            break;
        }
        else if ((p_pre->number < s->number) && (p->number > s->number))
        {
            p_pre->next = s; //β��ͷ
            s->next = p;     //β��ͷ�����ӳɹ�
            break;
        }
        else //�ڽ�β
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
//��ӡһ��Ҫ�޸ĵ�ѧ����Ϣ
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
//ȷ��ȷ���޸�
int is_modify(Stu* head) {
    int is_input_modify = 0;
    int modify_number = 0;
    while (1) {
        cout << "���������޸ĵ�ѧ����ѧ��:>\n";
        cin >> modify_number;
        cout << "��ѧ������ϢΪ:\n";
        Print_One_Student(head, modify_number);
        cout << "�Ƿ�ȷ���޸�?:\n";
        cout << "1.ȷ��  2.�������޸� 0.�˳��޸�\n";
        cin >> is_input_modify;
        if (is_input_modify != 2 ) {
            if (is_input_modify == 0) {
                modify_number = 0;
            }
            return modify_number;
        }
        
    }
}
//�޸�
void modify(Stu* head,int modify_number){
    Stu* p = head;
    bool flag = false;
    do {
        while (p->next != NULL) {
            if (p->next->number == modify_number) {
                flag = true;//�ҵ���
                cout << "������ĺ���Ϣ:>\n";
                cin >> p->next->number >> p->next->name >> p->next->sex >> p->next->score;
                break;
            }
            p = p->next;
        }
        if (!flag) {//û�ҵ�
            cout << "δ��ѯ����ѧ����Ϣ���޷��޸ģ�����������:\n";
        }
    } while (!flag);   
}
