#include <stdio.h>
#include <stdlib.h>

// Node structure representing a process
struct Process {
    int id;
    int timeRemaining;
    struct Process* next;
};

// Function to create a new process node
struct Process* createProcess(int id, int timeRemaining) {
    struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
    newProcess->id = id;
    newProcess->timeRemaining = timeRemaining;
    newProcess->next = NULL;
    return newProcess;
}

// Function to simulate time-sharing
void timeSharing(struct Process* head) {
    if (head == NULL) {
        printf("No processes to execute.\n");
        return;
    }

    struct Process* current = head;

    do {
        // Allocate a time slice of 10ms
        int timeSlice = 10;

        // Execute the process for the allocated time slice
        if (current->timeRemaining <= timeSlice) {
            printf("Process %d completed in %dms\n", current->id, current->timeRemaining);
            timeSlice = current->timeRemaining;
            current->timeRemaining = 0;
        } else {
            printf("Process %d executed for %dms\n", current->id, timeSlice);
            current->timeRemaining -= timeSlice;
        }

        // Move to the next process
        current = current->next;

    } while (current != head && current->timeRemaining > 0);

    printf("Time-sharing simulation completed.\n");
}

// Function to print the processes in the circular linked list
void printProcesses(struct Process* head) {
    if (head == NULL) {
        printf("No processes to display.\n");
        return;
    }

    struct Process* current = head;

    do {
        printf("Process %d: %dms\n", current->id, current->timeRemaining);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    // Create a circular linked list of processes
    struct Process* process1 = createProcess(1, 20);
    struct Process* process2 = createProcess(2, 15);
    struct Process* process3 = createProcess(3, 25);

    // Link the processes to form a circular list
    process1->next = process2;
    process2->next = process3;
    process3->next = process1;

    // Print the initial state of processes
    printf("Initial state of processes:\n");
    printProcesses(process1);

    // Simulate time-sharing
    timeSharing(process1);

    return 0;
}
