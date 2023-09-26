#include<stdio.h>
int main()
{
    char a;
    a=getchar();
    switch(a)
    {
        case 'a':
        case 'A':printf("Apple\n");break;
        case 'b':
        case 'B':printf("Banana\n");break;
        case 'g':
        case 'G':printf("Grape\n");break;
        case 'o':
        case 'O':printf("Orange\n");break;
        case 'p':
        case 'P':printf("Pear\n");break;
    }
    return 0;
}
