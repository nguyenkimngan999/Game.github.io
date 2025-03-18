#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void heapify(int* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[largest] < arr[left])
        largest = left;
    if(left < n && arr[largest] < arr[right])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
    
}

void heapsort(int* arr, int n) {

    for(int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for(long long i = n - 1; i >= 0; --i)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

long long patition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; ++j) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quicksort(int* arr, int low, int high) {
    if(low < high) {
        int pos = patition(arr, low, high);
        quicksort(arr, low, pos - 1);
        quicksort(arr, pos + 1, high);
    }
}

int main() {
    srand(time(0));
    int n;
    cout << "Nhap so luong phan tu mang it nhat la 100000: ";
    cin >> n;
    int* arr_1 = new int[n];
    int* arr_2 = new int[n];

    // nhập mảng
    for(long long i = 0; i < n; ++i) {
        arr_1[i] = rand();
        arr_2[i] = arr_1[i];
    }

    // đo thời gian của sắp xếp heap sort
    clock_t start = clock();
    heapsort(arr_1, n);
    clock_t end = clock();
    double t1 = (double) (end - start ) / CLOCKS_PER_SEC;

    // đo thời gian của sắp xếp quick sort
    start = clock();
    quicksort(arr_2, 0, n - 1);
    end = clock();
    double t2 = (double) (end - start) / CLOCKS_PER_SEC;
    
    cout << "Heap sort: " << t1 << endl;
    cout << "Quick sort: " << t2 << endl;
    // so sánh thời gian chạy của hai thuật toán
    double min = t1, max = t1;
    if(min < t2)
        min = t2;
    if(max > t2)
        max = t2;
    
    if(max == t1)
        cout << "The fastest algorithm: Heap Sort\n";
    else 
        cout << "The fastest algorithm: Quick Sort\n";

    if(min == t1) {
        cout << "The slowest algorithm: Heap Sort\n";
    }
    else 
        cout << "The slowest algorithm: Quick Sort\n";
    
    delete []arr_1;
    delete []arr_2;
    
    return 0;
}
