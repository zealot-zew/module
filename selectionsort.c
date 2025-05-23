#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionsort(int a[], int n)
{
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main()
{
    int n;
    clock_t start, end;
    printf("Enter the number of elements :");
    scanf("%d", &n);
    int a[n];

    // printf("Enter the elements of the array :");
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() / 50;
    }

    start = clock();
    selectionsort(a, n);
    end = clock();

    float d = (float)(end - start) / CLOCKS_PER_SEC;

    /*printf("The elements of the sorted array are :");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }*/

    printf("The time taken to sort %d is %f sec", n, d);
    printf("\n");
    return 0;
}