#include <cstdio>

void selectionSort(int *a, int size) {
    int i, j, t, min, tmp;

    for (i = 0; i < size-1; i++) {
        min = 1;
        for (j = i+1; j < size; j++) {
            if (a[j] < a[min]) min = j;
        }
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
        printf("\n%d단계 : ", i+1);
        for (t = 0; t < size; t++) printf("%3d ", a[t]);
    }
}

int main() {
    int arr[] = {123, 1245, 50, 38, 177, 463, 33};
    selectionSort(arr, 7);
}