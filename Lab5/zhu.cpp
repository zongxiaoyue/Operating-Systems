#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h> 
#include <locale.h> 
#include "f.h.cpp"

main()
{
    do
    {
        char c;
        struct scan_info s1;
        FILE* tf = NULL;
        setlocale(LC_ALL, "RUS");
        while (1)
        {
            puts("  1 �C �ߧ�ӧ�� ��ѧۧ�");
            puts("  2 �C �����ާ��� ��ѧۧݧ�");
            puts("  3 �C �է�ҧѧӧݧ֧ߧڧ� �� ��ѧۧ�");
            puts("  4 �C �����ڧ��ӧܧ� ��� ��էߧ�ާ� �ڧ� ��ѧ�ѧާ֧����");
            puts("  0 - �ӧ����");
            c = getch();
            switch (c)
            {
            case '1':input(tf); break;
            case '2':print(tf); break;
            case '3':app(tf); break;
            case '4':zapros(tf); break;
            case '0':; return 0;
            default: puts(" �ߧ֧ӧ֧�ߧ�� ��֧اڧ�");
            }
        }
    } while (getch() != 27);
}