/* Задача 1. Вариант 5.
Является ли последовательность цифр числа упорядоченной по возрастанию
*/

#include <stdio.h>

#define yes 1
#define no 0
#define razr 10

int proverka(int num, int ost)
{
    while (num > 0)
    {
        if (num%razr < ost)
        {
            ost = num%razr;
            num = num/razr;
        }
        else
            return no;
    }
    return yes;
}

int main(void)
{
    int num;
    int ost;

    printf("Input data ");
    scanf("%d",&num);

    ost = num%razr;
    num = num/razr;

    printf("%d",proverka(num,ost));

    return 0;
}
