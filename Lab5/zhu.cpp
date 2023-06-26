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
            puts("  1 ¨C §ß§à§Ó§í§Û §æ§Ñ§Û§Ý");
            puts("  2 ¨C §á§â§à§ã§Þ§à§ä§â §æ§Ñ§Û§Ý§Ñ");
            puts("  3 ¨C §Õ§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§Ö §Ó §æ§Ñ§Û§Ý");
            puts("  4 ¨C §ã§à§â§ä§Ú§â§à§Ó§Ü§Ñ §á§à §à§Õ§ß§à§Þ§å §Ú§Ù §á§Ñ§â§Ñ§Þ§Ö§ä§â§à§Ó");
            puts("  0 - §Ó§í§ç§à§Õ");
            c = getch();
            switch (c)
            {
            case '1':input(tf); break;
            case '2':print(tf); break;
            case '3':app(tf); break;
            case '4':zapros(tf); break;
            case '0':; return 0;
            default: puts(" §ß§Ö§Ó§Ö§â§ß§í§Û §â§Ö§Ø§Ú§Þ");
            }
        }
    } while (getch() != 27);
}