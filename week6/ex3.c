#include <stdio.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define BOOL int

int n, q;

void processSort(int *a, int *b, int st, int fn);

int *getWT(int const *bt);

int *getCT(int const *at, int const *wt, int const *bt);

int *getTAT(int const *bt, int const *wt);

float getAvg(int const *arr);

void swap(int *x, int *y);

int main() {
    printf("Enter processes number and quantum (separate them by space):\n");
    scanf("%d %d", &n, &q);

    int *at = (int *) malloc(sizeof(int) * n);
    int *bt = (int *) malloc(sizeof(int) * n);
    printf("\nEnter arrival time and burst time for each process (separate them by space):\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", (at + i), (bt + i));

    processSort(at, bt, 0, n); // sort table by arrival time

    int *wt = getWT(bt);
    int *ct = getCT(at, wt, bt);
    int *tat = getTAT(bt, wt);

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

int *getWT(int const *bt) {
    int *wt = (int *) malloc(sizeof(int) * n);
    int rem_bt[n], t = 0;
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];
    BOOL done;
    do {
        done = TRUE;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] <= 0) continue;
            done = FALSE;
            t += rem_bt[i] > q ? q : rem_bt[i];
            if (rem_bt[i] <= q) wt[i] = t - bt[i];
            rem_bt[i] = rem_bt[i] > q ? rem_bt[i] - q : 0;
        }
    } while (done != TRUE);
    return wt;
}

int *getCT(int const *at, int const *wt, int const *bt) {
    int *ct = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        ct[i] = at[i] + wt[i] + bt[i];
    return ct;
}

int *getTAT(int const *bt, int const *wt) {
    int *tat = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
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
