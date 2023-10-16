#include <cstdio>

void Swap(int* a, int* b) {
    if (a == b) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int Selection(int *arr, int last_idx) {
    int idx = 0, tmp = arr[0];
    for (int i = 1; i <= last_idx; i++) {
        if (tmp < arr[i]) {
            idx = i;
            tmp = arr[i];
        }
    }
    return idx;
} 

void SelectionSort(int *arr, int size) {
    int idx = 0, last_idx = size-1;

    for (int i = 0; i < size; i++) {
        idx = Selection(arr, last_idx);
        Swap(&arr[idx], &arr[last_idx]);
        --last_idx;
    }   
}

void PrintArr(int* arr, int size) {
    printf("Arr : [");
    for (int i = 0; i < size; i++) {
        if (i == size-1) printf("%d]\n", arr[i]);
        else printf("%d, ", arr[i]);
    }
}

int main() {
    int arr[] = {123, 1245, 50, 38, 177, 463, 33};
    SelectionSort(arr, 7);
    PrintArr(arr, 7);
    // Swap(&arr[0], &arr[6]);
    // PrintArr(arr, 7);
}