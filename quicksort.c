#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int n;

int main()
{
    clock_t st, end;
    printf("Enter the number of elements present in the array :");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() / 50;
    }

    st = clock();
    quicksort(a, 0, n - 1);
    end = clock();

    float d = (float)(end - st) / CLOCKS_PER_SEC;

    /*printf("The sorted Array :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }*/

    printf("\nThe time taken is: %f", d);
    return 0;
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int j = partition(a, low, high);
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int p = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    while (i <= j)
    {
        while (a[i] < p)
        {
            i++;
        }
        while (a[j] > p)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    if (i > j)
    {
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;
    }
    return j;
}