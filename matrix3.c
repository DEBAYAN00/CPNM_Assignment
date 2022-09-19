#include <stdio.h>
#include <conio.h>

int main()
{   
   
     FILE *fp;
    fp= fopen("Store_Matrix.txt","r");
    int sum = 0;
    int ra1, rb2, ca1, cb2;
    int a[20][20], b[20][20], ab[20][20];
    int i, j;
    printf("Enter 1st matrix row\n");
    scanf("%d", &ra1);
    printf("Enter 1st matrix column\n");
    scanf("%d", &ca1);
    printf("Enter 2nd matrix row\n");
    scanf("%d", &rb2);
    printf("Enter 2nd matrix column\n");
    scanf("%d", &cb2);

    if (ca1 != rb2)
    {
        printf("Matrix multiplication is not possible\n");
        return 0;
    }

    if (ca1 == rb2)
        printf("Matrix multiplication possible\n");

    printf("Enter element of 1st matrix\n");
    for (i = 0; i < ra1; i++)
    {
        for (j = 0; j < ca1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter element of 2nd matrix\n");
    for (i = 0; i < rb2; i++)
    {
        for (j = 0; j < cb2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    printf("Result : \n");

    for (i = 0; i < ra1; i++)
    {
        for (j = 0; j < cb2; j++)
        {
            for (int k = 0; k < ca1; k++)
            {
                

                sum += a[i][k] * b[k][j];
            }
            ab[i][j] = sum;
            sum = 0;
        }
    }
    for (i = 0; i < ra1; i++)
    {
        for (j = 0; j < cb2; j++)
        {
            fprintf(fp,"%d ", ab[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}