#include <stdio.h>

struct process{
    int num;
    int arrival;
    int burst;
    int ct;
    int tat;
    int wt;
};

void sortShortestJob(int n, struct process *processes){
    for (int i=1;i<n;i++){
        for(int j=0;j<n-1;j++){
            if (processes[i].burst<processes[j].burst ){
                struct process temp = processes[i];
                processes[i]=processes[j];
                processes[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        if (processes[i].arrival<processes[0].arrival){
            struct process temp=processes[0];
            processes[0]=processes[i];
            processes[i]=temp;
        }
    }

    for(int j=1;j<n-1;j++){
        int t1=processes[j-1].burst+processes[j-1].arrival;
        for(int i=j;i<n;i++){
            if (processes[i].arrival<processes[j].arrival && t1>processes[i].arrival 
                && processes[i].burst<processes[j].burst){
                struct process temp=processes[j];
                processes[j]=processes[i];
                processes[i]=temp;
            }
        }
    }

}

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
    
    for(int i = 0; i < numProcess; i++){
        if(i == 0 || processes[i-1].ct <= processes[i].arrival){
            processes[i].wt = 0;
        }
        else{
            processes[i].wt = processes[i-1].ct - processes[i].arrival;
        }  
        processes[i].tat = processes[i].burst + processes[i].wt;
        processes[i].ct = processes[i].tat + processes[i].arrival;
    }
    
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

