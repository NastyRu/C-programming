/*Перевод времени в секундах в часы:минуты:секунды*/

#include <stdio.h>
#include <math.h>

#define secinhour 3600
#define secinmin 60

int main(void)
{
    /*Время в секундах*/
    int time;

    scanf("%d",&time);

    /*Время в различных единицах*/
    int seconds,hours,minutes;

    /*Вычисление частей*/
    hours = time/secinhour;
    minutes = (time%secinhour)/secinmin;
    seconds = (time%secinhour)%secinmin;

    printf("%d:%d:%d",hours,minutes,seconds);

    return 0;
}
