#include <cstdio>

void PrintArr(int* arr, int size) {
    printf("Arr : [");
    for (int i = 0; i < size; i++) {
        if (i == size-1) printf("%d]\n", arr[i]);
        else printf("%d, ", arr[i]);
    }
}

void QuickSort();

int main() {
    int arr[] = {123, 1245, 50, 38, 177, 463, 33};
    QuickSort();
    PrintArr(arr, 7);
}