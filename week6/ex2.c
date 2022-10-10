#include <stdio.h>
#include <malloc.h>

int n;

void processSort(int *a, int *b, int st, int fn);

void SJFsort(int *at, int *bt);

int *getWT(int const *at, int const *bt);

int *getCT(int const *at, int const *wt, int const *bt);

int *getTAT(int const *ct, int const *at);

float getAvg(int const *arr);

void swap(int *x, int *y);

int main() {
    printf("Enter processes number: ");
    scanf("%d", &n);

    int *at = (int *) malloc(sizeof(int) * n);
    int *bt = (int *) malloc(sizeof(int) * n);
    printf("\nEnter arrival time and burst time for each process (separate it by space):\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", (at + i), (bt + i));

    processSort(at, bt, 0, n); // sort table by arrival time
    SJFsort(at, bt);

    int *wt = getWT(at, bt);
    int *ct = getCT(at, wt, bt);
    int *tat = getTAT(ct, at);

    printf("\n№   AT   BT   CT   TAT   WT\n");

    for (int i = 0; i < n; i++) {
        printf("%-4d", i + 1); // Process number
        printf("%-5d", *(at + i)); // Arrival time
        printf("%-5d", *(bt + i)); // Burst time
        printf("%-5d", *(ct + i)); // Completion time
        printf("%-6d", *(tat + i)); // Turn around time
        printf("%-5d\n", *(wt + i)); // Waiting time
    }
    printf("AWT = %.2f\n", getAvg(wt)); // Average Turnaround time
    printf("ATAT = %.2f\n", getAvg(tat)); // Average waiting time

    free(at);
    free(bt);
    free(wt);
    free(ct);
    free(tat);
    return 0;
}

void processSort(int *a, int *b, int st, int fn) {
    for (int i = 0; i < fn - st - 1; i++)
        for (int j = st; j < fn - i - 1; j++)
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
                swap(&b[j], &b[j + 1]);
            }
}

void SJFsort(int *at, int *bt) {
    int st = 0;
    for (int i = 1; i < n; i++) {
        if (at[i] == at[i - 1] && i != n - 1) continue;
        processSort(bt, at, st, i == n - 1 ? i + 1: i);
        st = i;
    }
}

int *getWT(int const *at, int const *bt) {
    int *wt = (int *) malloc(sizeof(int) * n);
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        if (at[i] == at[i - 1])
            wt[i] = bt[i - 1] + wt[i - 1];
        else wt[i] = 0;
    return wt;
}

int *getCT(int const *at, int const *wt, int const *bt) {
    int *ct = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        ct[i] = at[i] + wt[i] + bt[i];
    return ct;
}

int *getTAT(int const *ct, int const *at) {
    int *tat = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        tat[i] = ct[i] - at[i];
    return tat;
}

float getAvg(int const *arr) {
    float s = 0;
    for (int i = 0; i < n; i++)
        s += (float) arr[i];
    return s / (float) n;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
