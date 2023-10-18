#include <cstdio>

void Swap(int* a, int* b) {
    if (a == b) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void PrintArr(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i == size-1) printf("%d]\n", arr[i]);
        else printf("%d, ", arr[i]);
    }
}

void InsertionSort(int* arr, int size) {
    int idx, item;
    for (int i = 0; i < size-1; i++) {
        idx = i;
        item = arr[i+1];
        while (idx >= 0 && item < arr[idx]) {
            arr[idx+1] = arr[idx];
            idx--;
        }
        arr[idx+1] = item;
    } 
} 

int main() {
    int arr[] = {123, 1245, 50, 38, 177, 463, 33};
    InsertionSort(arr, 7);
    printf("Insertion Sort : ");
    PrintArr(arr, 7);
}