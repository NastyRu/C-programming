/*
Определение принадлежности точки треугольнику
*/

#include <stdio.h>
#include <math.h>

int scanf(const char * restrict format, ...);

float square(float x1,float y1,float x2,float y2,float x3,float y3)
{
    return fabs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))/2;
}

int main()
{
    float x1,y1,x2,y2,x3,y3;
    float xpoint,ypoint;
    float sqb,sq12,sq23,sq13;
    int vvodtriangle,vvodpoint;

    printf("Input coordinats tops of triangle ");
    vvodtriangle = scanf("%f,%f %f,%f %f,%f",&x1,&y1,&x2,&y2,&x3,&y3);

    printf("Input coordinats point ");
    vvodpoint = scanf("%f,%f",&xpoint,&ypoint);

    sqb = square(x1,y1,x2,y2,x3,y3);

    if (2==vvodpoint && 6==vvodtriangle && sqb)
    {
        sq12 = square(x1,y1,x2,y2,xpoint,ypoint);
        sq23 = square(xpoint,ypoint,x2,y2,x3,y3);
        sq13 = square(x1,y1,xpoint,ypoint,x3,y3);

        if ((sq12+sq23+sq13) > sqb)
            printf("Out triangle");
        else if (0 == sq12*sq13*sq23)
            printf("On the side of triangle");
        else
            printf("In triangle");
    }
    else
        printf("Incorrect coordinats");

    return 0;
}
