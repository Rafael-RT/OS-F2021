#include <stdio.h>

struct process{
    int num;
    int arrival;
    int burst;
    int ct;
    int tat;
    int wt;
};

void sortByArrival(int n, struct process *processes){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(processes[j].arrival > processes[j + 1].arrival){
                struct process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

void sortShortestJob(int n, struct process *processes){
    
    sortByArrival(n, processes);
    int index;
    int at = processes[0].arrival;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(processes[j].burst > processes[j + 1].burst && at == processes[j + 1].arrival){
                struct process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
    
    processes[0].ct = processes[0].burst + processes[0].arrival;
    processes[0].wt = 0;
    processes[0].tat = processes[0].burst;
    
    
    for(int i = 1; i < n; i++){
        int ct = processes[i - 1].ct;
        int low = processes[i].burst;
        
        for(int j = i; j < n; j++){
            if(ct >= processes[j].arrival && processes[j].burst <= low){
                low = processes[j].burst;
                index = j;
            }
        }
        processes[index].ct = ct + processes[index].burst;
        processes[index].tat = processes[index].ct - processes[index].arrival;
        processes[index].wt = processes[index].tat - processes[index].burst;
        
        struct process temp = processes[i];
        processes[i] = processes[index];
        processes[index] = temp;
        
    }    
}

void sortByNum(int n, struct process *processes){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(processes[j].num > processes[j + 1].num){
                struct process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

int main()
{
    int numProcess;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcess);
    struct process processes[numProcess];
    
    printf("Enter the arrival time and burst time for each process\n");
    
    for(int i = 0; i < numProcess; i++){
        processes[i].num = i + 1;
        printf("Arrival time of process #%d: ", i + 1);
        scanf("%d", &processes[i].arrival);
        printf("Burst time of process #%d: ", i + 1);
        scanf("%d", &processes[i].burst);
    }
    
    sortShortestJob(numProcess, processes);
    
    sortByNum(numProcess, processes);
    
    printf("\nP#\tAT\tBT\tCT\tTAT\tWT");
   
    int tatAvrg = 0;
    int wtAvrg = 0;
    for(int i = 0; i < numProcess; i++){
        wtAvrg += processes[i].wt;
        tatAvrg += processes[i].tat;
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d", i+1, processes[i].arrival, processes[i].burst, processes[i].ct, 
            processes[i].tat, processes[i].wt);
    }
    
    printf("\n\nAverage Turnaround Time: %f", (double)tatAvrg / numProcess);
    printf("\nAverage WT: %f\n", (double)wtAvrg / numProcess);
    
    return 0;
}

