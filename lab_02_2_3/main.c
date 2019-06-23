/*
Вычисление фунции с точностью. Вычисление погрешности.
*/

#include <stdio.h>
#include <math.h>

int scanf(const char * restrict format, ...);

int fact(int n)
{
    if (n>1)
        return n*fact(n-2);
    else
        return 1;
}

float func(float x, float eps)
{
    float sfunc;
    int n=1;
    sfunc = x;

    while (fact(n)*pow(x,n+2)/fact(n+1)/(n+2) > eps)
    {
        sfunc += fact(n)*pow(x,n+2)/fact(n+1)/(n+2);
        n+=2;
    }
    return sfunc;
}

int main()
{
    float x;
    float eps;
    float f,s;
    float deltaabs,deltaotn;
    int vvodx,vvodeps;

    printf("Input X ");
    vvodx = scanf("%f",&x);

    printf("Input eps ");
    vvodeps = scanf("%f",&eps);

    if (1==vvodeps && 1==vvodx)
    {
        f = asin(x);
        s = func(x,eps);
        deltaabs = fabs(f-s);
        deltaotn = deltaabs/f;
        if (f != 0)
            printf("%1.4f\n%1.4f\n%1.4f\n%1.4f",s,f,deltaabs,deltaotn);
        else
            printf("%1.4f\n%1.4f\n%1.4f\n-",s,f,deltaabs);
    }
    else
        printf("Incorrect input");
    return 0;
}
