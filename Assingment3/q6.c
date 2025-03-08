#include <stdio.h>
void checkDifference(int ar1[], int ar2[], int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        int flag = 0;
        for (int j = 0; j < size2; j++)
        {
            if (ar1[i] == ar2[j])
            {
                flag = 1;

                break;
            }
               
        }
           if (!flag)
                {
                    printf("%d", ar1[i]);
                }
    }
}
int main()
{
    int ar1[] = {1, 2, 3, 4};
    int size1 = sizeof(ar1) / sizeof(ar1[0]);

    int ar2[] = {2, 4, 5, 6};
    int size2 = sizeof(ar2)/sizeof(ar2[0]); ;

     printf("the difference between ar1 and ar2 ");
    checkDifference(ar1, ar2, size1, size2);
    printf(" /n");
        return 0;
}