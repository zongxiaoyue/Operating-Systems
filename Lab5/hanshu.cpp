#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h> 
#include <locale.h> 
#include "f.h.cpp"


void input(FILE* tf)// §ã§à§Ù§Õ§Ñ§ß§Ú§Ö §ß§à§Ó§à§Ô§à §æ§Ñ§Û§Ý§Ñ
{
    char choice;
    setlocale(LC_ALL, "RUS");
    tf = fopen("C:/file1.dat", "wb"); // §à§ä§Ü§â§í§ä§Ú§Ö §Ò§Ú§ß§Ñ§â§ß§à§Ô§à §æ§Ñ§Û§Ý§Ñ §Õ§Ý§ñ §Ù§Ñ§á§Ú§ã§Ú
    printf("\n §£§Ó§à§Õ §ä§à§Ó§Ñ§â§à§Ó\n");
    do
    {
        printf("\n §ß§Ñ§Ù§Ó§Ñ§ß§Ú§Ö: ");
        scanf("%s", &s1.model);
        printf("\n §è§Ö§ß§Ñ: ");
        scanf("%d", &s1.price);
        printf("\n §Ô§à§â§Ú§Ù§à§ß§ä§Ñ§Ý§î§ß§í§Û §â§Ñ§Ù§Þ§Ö§â §à§Ò§Ý§Ñ§ã§ä§Ú §ã§Ü§Ñ§ß§Ú§â§à§Ó§Ñ§ß§Ú§ñ: ");
        scanf("%f", &s1.x_size);
        printf("\n §Ó§Ö§â§ä§Ú§Ü§Ñ§Ý§î§ß§í§Û §â§Ñ§Ù§Þ§Ö§â §à§Ò§Ý§Ñ§ã§ä§Ú §ã§Ü§Ñ§ß§Ú§â§à§Ó§Ñ§ß§Ú§ñ: ");
        scanf("%f", &s1.y_size);
        printf("\n §à§á§ä§Ú§é§Ö§ã§Ü§à§Ö §â§Ñ§Ù§â§Ö§ê§Ö§ß§Ú§Ö: ");
        scanf("%d", &s1.optr);
        printf("\n §é§Ú§ã§Ý§à §Ô§â§Ñ§Õ§Ñ§è§Ú§Û §ã§Ö§â§à§Ô§à: ");
        scanf("%d", &s1.grey);
        fwrite(&s1, sizeof(s1), 1, tf); // §Ù§Ñ§á§Ú§ã§î §Ó §æ§Ñ§Û§Ý §à§Õ§ß§à§Û §ã§ä§â§å§Ü§ä§å§â§í t1
        printf("\n §©§Ñ§Ü§à§ß§é§Ú§ä§î?  y/n \n\n ");
        choice = getch();
    } while (choice != 'y');
    fclose(tf);
}

void print(FILE* tf)//§á§â§à§ã§Þ§à§ä§â §æ§Ñ§Û§Ý§Ñ
{
    int i;
    tf = fopen("C:/file1.dat", "rb"); // §à§ä§Ü§â§í§ä§Ú§Ö §Ò§Ú§ß§Ñ§â§ß§à§Ô§à §æ§Ñ§Û§Ý§Ñ §Õ§Ý§ñ §é§ä§Ö§ß§Ú§ñ
    i = 1;
    fread(&s1, sizeof(s1), 1, tf); // §é§ä§Ö§ß§Ú§Ö §Ú§Ù §æ§Ñ§Û§Ý§Ñ §à§Õ§ß§à§Û §ã§ä§â§å§Ü§ä§å§â§í t1
    while (!feof(tf))
    {
        printf("model %s \n price %d \n x_size %f \n y_size %f \n optr %d \n grey %d \n", s1.model, s1.price, s1.x_size, s1.y_size, s1.optr, s1.grey);
        fread(&s1, sizeof(s1), 1, tf);
        i++;
    }
    getch();
}

void app(FILE* tf)//§Õ§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§Ö §Ó §æ§Ñ§Û§Ý
{
    char ch;
    setlocale(LC_ALL, "RUS");
    tf = fopen("C:/file1.dat", "ab"); // §à§ä§Ü§â§í§ä§Ú§Ö §Ò§Ú§ß§Ñ§â§ß§à§Ô§à §æ§Ñ§Û§Ý§Ñ §Õ§Ý§ñ §Õ§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§ñ
    printf("\n  §£§Ó§à§Õ §ä§à§Ó§Ñ§â§à§Ó \n");
    do
    {
        printf("\n §ß§Ñ§Ù§Ó§Ñ§ß§Ú§Ö: ");
        scanf("%s", &s1.model);
        printf("\n §è§Ö§ß§Ñ: ");
        scanf("%d", &s1.price);
        printf("\n §Ô§à§â§Ú§Ù§à§ß§ä§Ñ§Ý§î§ß§í§Û §â§Ñ§Ù§Þ§Ö§â §à§Ò§Ý§Ñ§ã§ä§Ú §ã§Ü§Ñ§ß§Ú§â§à§Ó§Ñ§ß§Ú§ñ: ");
        scanf("%f", &s1.x_size);
        printf("\n §Ó§Ö§â§ä§Ú§Ü§Ñ§Ý§î§ß§í§Û §â§Ñ§Ù§Þ§Ö§â §à§Ò§Ý§Ñ§ã§ä§Ú §ã§Ü§Ñ§ß§Ú§â§à§Ó§Ñ§ß§Ú§ñ: ");
        scanf("%f", &s1.y_size);
        printf("\n §à§á§ä§Ú§é§Ö§ã§Ü§à§Ö §â§Ñ§Ù§â§Ö§ê§Ö§ß§Ú§Ö: ");
        scanf("%d", &s1.optr);
        printf("\n §é§Ú§ã§Ý§à §Ô§â§Ñ§Õ§Ñ§è§Ú§Û §ã§Ö§â§à§Ô§à: ");
        scanf("%d", &s1.grey);
        fwrite(&s1, sizeof(s1), 1, tf);
        printf(" §©§Ñ§Ü§à§ß§é§Ú§ä§î?  y/n ");
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
    printf("§ã§à§â§ä§Ú§â§à§Ó§Ü§Ñ §á§à §è§Ö§ß§Ö \n");
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
    fseek(tf, -i, 1); // §Ó§à§Ù§Ó§â§Ñ§ä §ß§Ñ sizeof(t1) §Ò§Ñ§Û§ä §ß§Ñ§Ù§Ñ§Õ
    fwrite(&s1, sizeof(s11), 1, tf); // §Ù§Ñ§á§Ú§ã§î §Ú§Ù§Þ§Ö§ß§×§ß§ß§à§Û §ã§ä§â§å§Ü§ä§å§â§í §ß§Ñ §á§â§Ö§Ø§ß§Ö§Ö §Þ§Ö§ã§ä§à
    fread(&s11, sizeof(s11), 1, tf); // §é§ä§Ö§ß§Ú§Ö §Ú§Ù §æ§Ñ§Û§Ý§Ñ §à§Õ§ß§à§Û §ã§ä§â§å§Ü§ä§å§â§í t1  
    printf("model %s \n price %d \n x_size %f \n y_size %f \n optr %d \n grey %d \n", s11->model, s11->price, s11->x_size, s11->y_size, s11->optr, s11->grey);
    getch();
    fclose(tf);
    return 0;
}
