/*
 Нахождение периметра треугольника по координатам вершин
*/

#include <stdio.h>
#include <math.h>

/*Вычисление стороны треугольника*/
#define SqrtPow(a,b,c,d) sqrt(pow(a-b,2)+pow(c-d,2))

int main(void)
{
    /*первые координаты*/
    float x1,y1;
    scanf("%f%f",&x1,&y1);

    /*вторые координаты*/
    float x2,y2;
    scanf("%f%f",&x2,&y2);

    /*третьи координаты*/
    float x3,y3;
    scanf("%f%f",&x3,&y3);

    /*периметр*/
    float perimetr;

    /*вычисление периметра*/
    perimetr = SqrtPow(x1,x2,y1,y2)+SqrtPow(x1,x3,y1,y3)+SqrtPow(x2,x3,y2,y3);

    printf("%f",perimetr);

    return 0;
}
