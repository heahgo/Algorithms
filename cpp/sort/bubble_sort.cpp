#include <cstdio>

void Swap(int* a, int* b) {
    if (a == b || *a == *b) return;
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

void BubbleSort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) Swap(&arr[j], &arr[j+1]);
        }
    }
}

void OptimizedBubbleSort(int *arr, int size) {
    int sorted_flag;
    for (int i = 0; i < size; i++) {
        sorted_flag = 1;
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                Swap(&arr[j], &arr[j+1]);
                sorted_flag = 0;
            }
        }
        if (sorted_flag == 1) return;
    }
}

int main() {
    int arr1[] = {123, 1245, 50, 38, 177, 463, 33};
    BubbleSort(arr1, 7);
    printf("Bubble Sort : ");
    PrintArr(arr1, 7);

    int arr2[] = {123, 1245, 50, 38, 177, 463, 33};
    OptimizedBubbleSort(arr2, 7);
    printf("Optimized Bubble Sort : ");
    PrintArr(arr2, 7);
}