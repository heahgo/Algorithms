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

// left pivot quick sort 

int LeftPartition(int* arr, int left, int right) {
    int pivot = arr[left];
    int L = left;
    for (int i = left+1; i <= right; i++) {
        if (arr[i] <= pivot) Swap(&arr[++L], &arr[i]);
    }
    Swap(&arr[L], &arr[left]);
    return L;
}

void LeftQuickSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = LeftPartition(arr, left, right);
        LeftQuickSort(arr, left, mid-1);
        LeftQuickSort(arr, mid+1, right);
    }
}

// middle pivot quick sort

int MiddlePartition(int* arr, int left, int right) {
    int mid = (left + right) / 2;
    int pivot = arr[mid];
    Swap(&arr[mid], &arr[left]);
    int L = left;
    for (int i = left+1; i <= right; i++) {
        if (arr[i] <= pivot) Swap(&arr[++L], &arr[i]);
    }
    Swap(&arr[L], &arr[left]);
    return L;
}

void  MiddleQuickSort(int* arr, int left, int right) {
    if (left < right) {
        int mid =  MiddlePartition(arr, left, right);
        MiddleQuickSort(arr, left, mid-1);
        MiddleQuickSort(arr, mid+1, right);
    }
}

// right pivot quick sort 

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


#define pivot_left 0
#define pivot_middle 1
#define pivot_right 2

void QuickSort(int*arr, int left, int right, int pivot_type) {
    if (pivot_type != pivot_left && pivot_type != pivot_middle && pivot_type !=  pivot_right)
        return;

    switch (pivot_type) {
        case pivot_left:
            LeftQuickSort(arr, left, right);
            break;
        case pivot_middle:
            MiddleQuickSort(arr, left, right);
            break;
        case pivot_right:
            RightQuickSort(arr, left, right);
            break;
    }
}

int main() {
    
    int arr1[] = {123, 1245, 50, 38, 177, 463, 33};
    QuickSort(arr1, 0, 7, pivot_left);
    printf("Left Pivot : ");
    PrintArr(arr1, 8);
    
    int arr2[] = {123, 1245, 50, 38, 177, 463, 33};
    QuickSort(arr2, 0, 7, pivot_middle);
    printf("Middle Pivot : ");
    PrintArr(arr2, 8);

    int arr3[] = {123, 1245, 50, 38, 177, 463, 33};
    QuickSort(arr3, 0, 7, pivot_right);
    printf("Right Pivot : ");
    PrintArr(arr3, 8);
}