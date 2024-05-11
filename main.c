#include <stdio.h>
#include <stdbool.h>

void QuickSort(int v[], int st, int dr) {
    if (st < dr) {
        // Pivotul este inițial v[st]
        int m = (st + dr) / 2;
        int aux = v[st];
        v[st] = v[m];
        v[m] = aux;
        int i = st, j = dr, d = 0;
        while (i < j) {
            if (v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        QuickSort(v, st, i - 1);
        QuickSort(v, i + 1, dr);
    }
}

void InsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int p = i;
        while (p > 0 && a[p] < a[p - 1]) {
            int aux = a[p];
            a[p] = a[p - 1];
            a[p - 1] = aux;
            p--;
        }
    }
}

void BubbleSort(int v[], int n) {
    bool sorted;
    do {
        sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sorted = false;
            }
        }
    } while (!sorted);
}

void SelectionSort(int X[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int p = i;
        for (int j = i + 1; j < n; j++) {
            if (X[j] < X[p]) {
                p = j;
            }
        }
        int aux = X[i];
        X[i] = X[p];
        X[p] = aux;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int X[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    int QSort[n];
    for (int i = 0; i < n; i++) {
        QSort[i] = X[i];
    }
    QuickSort(QSort, 0, n - 1);
    printf("Quick Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", QSort[i]);
    }
    printf("\n");

    int ISort[n];
    for (int i = 0; i < n; i++) {
        ISort[i] = X[i];
    }
    InsertionSort(ISort, n);
    printf("Insertion Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ISort[i]);
    }
    printf("\n");

    int BSort[n];
    for (int i = 0; i < n; i++) {
        BSort[i] = X[i];
    }
    BubbleSort(BSort, n);
    printf("Bubble Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", BSort[i]);
    }
    printf("\n");

    int SSort[n];
    for (int i = 0; i < n; i++) {
        SSort[i] = X[i];
    }
    SelectionSort(SSort, n);
    printf("Selection Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", SSort[i]);
    }
    printf("\n");

    return 0;
}
