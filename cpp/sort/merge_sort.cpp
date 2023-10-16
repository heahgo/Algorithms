#include <cstdio>

void PrintArr(int* arr, int size) {
    printf("Arr : [");
    for (int i = 0; i < size; i++) {
        if (i == size-1) printf("%d]\n", arr[i]);
        else printf("%d, ", arr[i]);
    }
}

void Merge(int* arr, int* tmp, int left, int right) { 
    int mid = (left + right) / 2;
    int L = left;
    int R = mid + 1;
    int k = left;
    while (L <= mid && R <= right) {
        if (arr[L] <= arr[R]) {
            tmp[k] = arr[L];
            L += 1;
            k += 1;

        } else {
            tmp[k] = arr[R];
            R += 1;
            k += 1;
        }
    }
    if (L > mid) {
        for (int i = R; i < right + 1; i++) {
            tmp[k] = arr[i];
            k += 1;
        }
    } else {
        for (int i = L; i < mid + 1; i++) {
            tmp[k] = arr[i];
            k += 1;
        }  
    }
    for (int i = left; i < right + 1; i++) {
        arr[i] = tmp[i];
    }
}

void MergeSort(int* arr, int* tmp, int left, int right) {
    if (left == right) return;
        
    int mid = (left + right) / 2;
    MergeSort(arr, tmp, left, mid);
    MergeSort(arr, tmp, mid+1, right);
    Merge(arr, tmp, left, right);
} 

int main() {
    int arr[] = {123, 1245, 50, 38, 177, 463, 33};
    int tmp[] = {0, 0, 0, 0, 0, 0 ,0};
    MergeSort(arr, tmp, 0, 6);
    PrintArr(arr, 7);
}