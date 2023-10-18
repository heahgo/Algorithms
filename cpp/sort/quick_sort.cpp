#include <cstdio>

void Swap(int* a, int* b) {
    if (a == b) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void PrintArr(int* arr, int size) {
    printf("Arr : [");
    for (int i = 0; i < size; i++) {
        if (i == size-1) printf("%d]\n", arr[i]);
        else printf("%d, ", arr[i]);
    }
}

int RightPartition(int* arr, int left, int right) {
    int pivot = arr[right];
    int L = left - 1;
    for (int i = left; i < right; i++) {
        if (arr[i] <= pivot) Swap(&arr[++L], &arr[i]);
    }
    Swap(&arr[L+1], &arr[right]);
    return L+1;
} 

void RightQuickSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = RightPartition(arr, left, right);
        RightQuickSort(arr, left, mid-1);
        RightQuickSort(arr, mid+1, right);
    }
}

int main() {
    int arr1[] = {123, 1245, 50, 38, 177, 463, 33};
    RightQuickSort(arr1, 0, 6);
    PrintArr(arr1, 7);
}