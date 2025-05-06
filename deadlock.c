#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int Allocation[MAX][MAX], Request[MAX][MAX], Available[MAX];
bool Finish[MAX];
int Work[MAX];

int n, m;

bool canProceed(int i) {
    for (int j = 0; j < m; j++)
        if (Request[i][j] > Work[j])
            return false;
    return true;
}

void addToWork(int i) {
    for (int j = 0; j < m; j++)
        Work[j] += Allocation[i][j];
}

int main() {
    printf("Enter number of processes and resource types: ");
    scanf("%d%d", &n, &m);

    printf("Enter Allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &Allocation[i][j]);

    printf("Enter Request matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &Request[i][j]);

    printf("Enter Available resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &Available[i]);
        Work[i] = Available[i];
    }

    for (int i = 0; i < n; i++) {
        bool hasAllocation = false;
        for (int j = 0; j < m; j++)
            if (Allocation[i][j] != 0)
                hasAllocation = true;
        Finish[i] = !hasAllocation;
    }

    bool deadlock = false;
    while (true) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!Finish[i] && canProceed(i)) {
                addToWork(i);
                Finish[i] = true;
                found = true;
            }
        }
        if (!found)
            break;
    }

    printf("Deadlocked Processes: ");
    for (int i = 0; i < n; i++) {
        if (!Finish[i]) {
            printf("P%d ", i);
            deadlock = true;
        }
    }

    if (deadlock)
        printf("\nDeadlock detected.\n");
    else
        printf("\nNo deadlock detected.\n");

    return 0;
}
