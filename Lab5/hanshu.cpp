#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h> 
#include <locale.h> 
#include "f.h.cpp"


void input(FILE* tf)// ���٧էѧߧڧ� �ߧ�ӧ�ԧ� ��ѧۧݧ�
{
    char choice;
    setlocale(LC_ALL, "RUS");
    tf = fopen("C:/file1.dat", "wb"); // ���ܧ���ڧ� �ҧڧߧѧ�ߧ�ԧ� ��ѧۧݧ� �էݧ� �٧ѧ�ڧ��
    printf("\n ���ӧ�� ���ӧѧ���\n");
    do
    {
        printf("\n �ߧѧ٧ӧѧߧڧ�: ");
        scanf("%s", &s1.model);
        printf("\n ��֧ߧ�: ");
        scanf("%d", &s1.price);
        printf("\n �ԧ��ڧ٧�ߧ�ѧݧ�ߧ�� ��ѧ٧ާ֧� ��ҧݧѧ��� ��ܧѧߧڧ��ӧѧߧڧ�: ");
        scanf("%f", &s1.x_size);
        printf("\n �ӧ֧��ڧܧѧݧ�ߧ�� ��ѧ٧ާ֧� ��ҧݧѧ��� ��ܧѧߧڧ��ӧѧߧڧ�: ");
        scanf("%f", &s1.y_size);
        printf("\n ����ڧ�֧�ܧ�� ��ѧ٧�֧�֧ߧڧ�: ");
        scanf("%d", &s1.optr);
        printf("\n ��ڧ�ݧ� �ԧ�ѧէѧ�ڧ� ��֧��ԧ�: ");
        scanf("%d", &s1.grey);
        fwrite(&s1, sizeof(s1), 1, tf); // �٧ѧ�ڧ�� �� ��ѧۧ� ��էߧ�� �����ܧ���� t1
        printf("\n ���ѧܧ�ߧ�ڧ��?  y/n \n\n ");
        choice = getch();
    } while (choice != 'y');
    fclose(tf);
}

void print(FILE* tf)//�����ާ��� ��ѧۧݧ�
{
    int i;
    tf = fopen("C:/file1.dat", "rb"); // ���ܧ���ڧ� �ҧڧߧѧ�ߧ�ԧ� ��ѧۧݧ� �էݧ� ���֧ߧڧ�
    i = 1;
    fread(&s1, sizeof(s1), 1, tf); // ���֧ߧڧ� �ڧ� ��ѧۧݧ� ��էߧ�� �����ܧ���� t1
    while (!feof(tf))
    {
        printf("model %s \n price %d \n x_size %f \n y_size %f \n optr %d \n grey %d \n", s1.model, s1.price, s1.x_size, s1.y_size, s1.optr, s1.grey);
        fread(&s1, sizeof(s1), 1, tf);
        i++;
    }
    getch();
}

void app(FILE* tf)//�է�ҧѧӧݧ֧ߧڧ� �� ��ѧۧ�
{
    char ch;
    setlocale(LC_ALL, "RUS");
    tf = fopen("C:/file1.dat", "ab"); // ���ܧ���ڧ� �ҧڧߧѧ�ߧ�ԧ� ��ѧۧݧ� �էݧ� �է�ҧѧӧݧ֧ߧڧ�
    printf("\n  ���ӧ�� ���ӧѧ��� \n");
    do
    {
        printf("\n �ߧѧ٧ӧѧߧڧ�: ");
        scanf("%s", &s1.model);
        printf("\n ��֧ߧ�: ");
        scanf("%d", &s1.price);
        printf("\n �ԧ��ڧ٧�ߧ�ѧݧ�ߧ�� ��ѧ٧ާ֧� ��ҧݧѧ��� ��ܧѧߧڧ��ӧѧߧڧ�: ");
        scanf("%f", &s1.x_size);
        printf("\n �ӧ֧��ڧܧѧݧ�ߧ�� ��ѧ٧ާ֧� ��ҧݧѧ��� ��ܧѧߧڧ��ӧѧߧڧ�: ");
        scanf("%f", &s1.y_size);
        printf("\n ����ڧ�֧�ܧ�� ��ѧ٧�֧�֧ߧڧ�: ");
        scanf("%d", &s1.optr);
        printf("\n ��ڧ�ݧ� �ԧ�ѧէѧ�ڧ� ��֧��ԧ�: ");
        scanf("%d", &s1.grey);
        fwrite(&s1, sizeof(s1), 1, tf);
        printf(" ���ѧܧ�ߧ�ڧ��?  y/n ");
        ch = getch();
    } while (ch != 'y');
    fclose(tf);
}



int zapros(FILE* tf)
{
    int i, j, k, o;
    long int l;
    struct scan_info* s1;
    struct scan_info* s11;
    struct scan_info1;
    tf = fopen("C:/file1.dat", "wt");
    printf("�����ڧ��ӧܧ� ��� ��֧ߧ� \n");
    for (i = 0; i < k - 1; i++)
    {
        for (j = 0; j < k - i - 1; j++)
        {
            if (s1[j].price > s1[j + 1].price)
            {
                s11[i] = s1[j];
                s1[j] = s1[j + 1];
                s1[j + 1] = s11[i];
            }
        }
    }
    l = sizeof(s11);
    fseek(tf, -i, 1); // �ӧ�٧ӧ�ѧ� �ߧ� sizeof(t1) �ҧѧۧ� �ߧѧ٧ѧ�
    fwrite(&s1, sizeof(s11), 1, tf); // �٧ѧ�ڧ�� �ڧ٧ާ֧ߧקߧߧ�� �����ܧ���� �ߧ� ���֧اߧ֧� �ާ֧���
    fread(&s11, sizeof(s11), 1, tf); // ���֧ߧڧ� �ڧ� ��ѧۧݧ� ��էߧ�� �����ܧ���� t1  
    printf("model %s \n price %d \n x_size %f \n y_size %f \n optr %d \n grey %d \n", s11->model, s11->price, s11->x_size, s11->y_size, s11->optr, s11->grey);
    getch();
    fclose(tf);
    return 0;
}
