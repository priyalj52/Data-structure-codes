#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n, arr[50];
    printf("enter the size of array\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enetr the %d element:", i);
        scanf("%d", &arr[i]);
    }

     for (int i = 0; i < n-1; i++)
     {       printf("after pass %d\n", i+1);
         for (int j = 0; j < n - i - 1; j++)
         {
            if (arr[j] > arr[j + 1])
               {  swap(&arr[j], &arr[j + 1]);
               }
             for (int i = 0; i < n; i++)
             {
                 printf("%d ", arr[i]);
             }
             printf("\n");
         }
     }
    
        printf("\n priyal jain,cse3,04376802720");
        return 0;
    }
