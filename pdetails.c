#include <stdio.h>
#include <string.h>

struct Process {
    int pid;
    char processName[20];
    int arrivalTime;
    int completionTime;
    int executionTime;
};

void retrieveProcessDetails(struct Process *p) {
    printf("Process ID (pid): ");
    scanf("%d", &p->pid);
    printf("Process Name: ");
    scanf("%s", p->processName);
    printf("Arrival Time: ");
    scanf("%d", &p->arrivalTime);
    printf("Execution Time: ");
    scanf("%d", &p->executionTime);
    printf("Completion Time: ");
    scanf("%d", &p->completionTime);
}

void displayProcessDetails(struct Process processes[], int n) {
    printf("\nProcess Details:\n");
    printf("PID\tName\tArrival Time\tExecution Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t\t%d\t\t%d\n",
               processes[i].pid,
               processes[i].processName,
               processes[i].arrivalTime,
               processes[i].executionTime,
               processes[i].completionTime);
    }
}

void searchProcessByPid(struct Process processes[], int n, int searchPid) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (processes[i].pid == searchPid) {
            printf("\nProcess Found:\n");
            printf("PID: %d\n", processes[i].pid);
            printf("Name: %s\n", processes[i].processName);
            printf("Arrival Time: %d\n", processes[i].arrivalTime);
            printf("Execution Time: %d\n", processes[i].executionTime);
            printf("Completion Time: %d\n", processes[i].completionTime);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nNo process found with PID: %d\n", searchPid);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Process %d:\n", i + 1);
        retrieveProcessDetails(&processes[i]);
    }

    displayProcessDetails(processes, n);

    int searchPid;
    printf("\nEnter the PID to search for: ");
    scanf("%d", &searchPid);
    searchProcessByPid(processes, n, searchPid);

    return 0;
}
