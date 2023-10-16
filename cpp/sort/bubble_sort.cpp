#include <cstdio>

void bubbleSort(int *a, int size) {
    int i, j, t, tmp;
    for (i = size-1; i > 0; i--) {
        printf("\n %d단계>>", size-i);
        for (j = 0; j < i; j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
            printf("\n\t");
            for (t = 0; t < size; t++) printf("%3d ", a[t]);
        }
    }
}

int main() {
    int arr[] = {123, 1245, 50, 38, 177, 463, 33};
    bubbleSort(arr, 7);
}