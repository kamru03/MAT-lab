#include<stdio.h>

int main()
{
    int i,j,k,n;
    float a[20][20], x[20], ratio;

    printf("Enter number of variables: ");
    scanf("%d",&n);

    printf("\nEnter coefficients of augmented matrix:\n");

    for(i=0;i<n;i++)
    {
        printf("\nEquation %d:\n",i+1);

        for(j=0;j<=n;j++)
        {
            if(j==n)
                printf("Constant term: ");
            else
                printf("Coefficient of x%d: ",j+1);

            scanf("%f",&a[i][j]);
        }
    }

    // Forward Elimination
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            ratio = a[j][i] / a[i][i];

            for(k=0;k<=n;k++)
            {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    x[n-1] = a[n-1][n] / a[n-1][n-1];

    for(i=n-2;i>=0;i--)
    {
        x[i] = a[i][n];

        for(j=i+1;j<n;j++)
        {
            x[i] = x[i] - a[i][j]*x[j];
        }

        x[i] = x[i] / a[i][i];
    }

    printf("\nSolution:\n");

    for(i=0;i<n;i++)
    {
        printf("x%d = %.3f\n",i+1,x[i]);
    }

    return 0;
}