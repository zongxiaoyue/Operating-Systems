#include <cstdio>
#ifndef F_H_
#define F_H_
#define SIZE 8
struct scan_info {
    char model[25]; // �ߧѧڧާ֧ߧ�ӧѧߧڧ� �ާ�է֧ݧ� 
    int price;      // ��֧ߧ� 
    float x_size;       // �ԧ��ڧ٧�ߧ�ѧݧ�ߧ�� ��ѧ٧ާ֧� ��ҧݧѧ��� ��ܧѧߧڧ��ӧѧߧڧ�
    float y_size;       // �ӧ֧��ڧܧѧݧ�ߧ�� ��ѧ٧ާ֧� ��ҧݧѧ��� ��ܧѧߧڧ��ӧѧߧڧ�
    int optr;       // ����ڧ�֧�ܧ�� ��ѧ٧�֧�֧ߧڧ� 
    int grey;       // ��ڧ�ݧ� �ԧ�ѧէѧ�ڧ� ��֧��ԧ� 
}s1;

struct scan_info1 {
    struct scan_info;
}s11;

void input(FILE* tf); // ���٧էѧߧڧ� �ߧ�ӧ�ԧ� ��ѧۧݧ�
void print(FILE* tf); // �����ާ��� ��ѧۧݧ�
void app(FILE* tf); // �է�ҧѧӧݧ֧ߧڧ� �� ��ѧۧ�
int zapros(FILE* tf);//�����ڧ��ӧܧ� ��� ��էߧ�ާ� �ڧ� ��ѧ�ѧާ֧����


#endif