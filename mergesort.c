#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int n;

int main()
{
    clock_t st, end;
    printf("Enter the number of elements present in the array :");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }

    st = clock();
    merge_sort(a, 0, n - 1);
    end = clock();

    float d = (float)(end - st) / CLOCKS_PER_SEC;

    // printf("The sorted Array :");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", a[i]);
    // }

    printf("\nThe time taken is: %f", d);
    return 0;
}

void merge_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid;
        mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i = low;
    int k = low;
    int j = mid + 1;
    int b[high + 1];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= high)
    {
        b[k++] = a[j++];
    }
    for (int l = low; l <= high; l++)
    {
        a[l] = b[l];
    }
}