/*Нахождение общего сопротивление трех параллельно соединенных резисторов*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    /*Сопротивления*/
    float res1,res2,res3;

    scanf("%f %f %f",&res1,&res2,&res3);

    /*Общее сопротивление*/
    float totalres;

    /*Нахождение общего сопротивления*/
    totalres = 1/(1/res1+1/res2+1/res3);

    printf("%f",totalres);

    return 0;
}
