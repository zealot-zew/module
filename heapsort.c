#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main()
{
    srand(time(NULL));

    for (int n = 1000; n <= 10000; n += 1000)
    {
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            arr[i] = rand() / 50;

        clock_t start = clock();
        heapSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000000.0;

        printf("n = %d -> Time taken: %.0f ns\n", n, time_taken);

        free(arr);
    }

    return 0;
}
