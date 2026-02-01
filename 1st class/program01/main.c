#include <stdio.h>
#include <math.h>
float f(float x)
{
    return x*x - 4;  
}
int main()
{
    float a, b, c, error;
    int i = 1;
    printf("Enter initial guesses a and b: ");
    scanf("%f %f", &a, &b);
    if (f(a) * f(b) >= 0)
    {
        printf("Invalid initial guesses.\n");
        return 0;
    }
    printf("Enter allowed error: ");
    scanf("%f", &error);
    printf("\nIter\t a\t\t b\t\t c\t\t f(c)\n");
    do
    {
        c = (a + b) / 2;
        printf("%d\t %.4f\t %.4f\t %.4f\t %.4f\n",
               i, a, b, c, f(c));
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
        i++;
    }
    while (fabs(f(c)) > error);
    printf("\nRoot = %.4f\n", c);
    return 0;
}
