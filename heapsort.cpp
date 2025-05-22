#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    srand(time(nullptr));

    for (int n = 1000; n <= 10000; n += 1000) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 100000;

        auto start = high_resolution_clock::now();
        heapSort(arr);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start).count();

        cout << "n = " << n << " -> Time taken: " << duration << " ns\n";
    }

    return 0;
}