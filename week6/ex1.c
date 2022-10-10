#include <stdio.h>
#include <malloc.h>

int n;

int *getWT(int const *at, int const *bt);

int *getCT(int const *at, int const *wt, int const *bt);

int *getTAT(int const *ct, int const *at);

float getAvg(int const *arr);

int main() {
    printf("Enter processes number: ");
    scanf("%d", &n);

    int *at = (int *) malloc(sizeof(int) * n);
    int *bt = (int *) malloc(sizeof(int) * n);
    printf("\nEnter arrival time and burst time for each process (separate it by space):\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", (at + i), (bt + i));

    int *wt = getWT(at, bt);
    int *ct = getCT(at, wt, bt);
    int *tat = getTAT(ct, at);

    printf("\n№   CT   TAT   WT\n");

    for (int i = 0; i < n; i++) {
        printf("%-4d", i + 1); // Process number
        printf("%-5d", *(ct + i)); // Completion time
        printf("%-6d", *(tat + i)); // Turn around time
        printf("%-5d\n", *(wt + i)); // Waiting time
    }
    printf("AWT = %f\n", getAvg(wt)); // Average Turnaround time
    printf("ATAT = %f\n", getAvg(tat)); // Average waiting time

    free(at);
    free(bt);
    free(wt);
    free(ct);
    free(tat);
    return 0;
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
    for (int i = 0; i < n; i++) {
        s += (float) arr[i];
    }
    return s / (float) n;
}