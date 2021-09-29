#include <stdio.h>
/*
	The fastest of all is Shortest job next, followed by first in first out,
	and the slowest round robin. The last algorithm is used when 	
	the CPU has limited time, so it is the slowest. 
	It is best of course to use the SJN algorithm, 
	since it makes the best use of our resources and gives the best result.
*/
struct process{
    int num;
    int arrival;
    int burst;
    int ct;
    int tat;
    int wt;
    int remain;
};

void roundRobin(int n, struct process *processes, int quantum){
    int exec = 0;
    int count = 0;
    
    while(count != n){
        int currentAT = 0;
        
        for (int i = 0; i < n; i++){
            if (processes[i].arrival < currentAT) {
                currentAT = processes[i].arrival;
            }
        }
        
        if(exec < currentAT){
            exec = currentAT;
        }
        
        for(int i = 0; i < n; i++){
            if(processes[i].arrival <= exec && processes[i].remain > 0){
                
                if(processes[i].remain <= quantum){
                    exec += processes[i].remain;
                    processes[i].remain = 0;
                    processes[i].ct = exec;
                    processes[i].tat = processes[i].ct - processes[i].arrival;
                    processes[i].wt = processes[i].tat - processes[i].burst;
                    count++;
                    continue;
                }
                
                exec += quantum;
                processes[i].remain -= quantum;
                
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
    int numProcess, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcess);
    struct process processes[numProcess];
    
    printf("Enter the number of quantum: ");
    scanf("%d", &quantum);
    
    printf("Enter the arrival time and burst time for each process\n");
    
    for(int i = 0; i < numProcess; i++){
        processes[i].num = i + 1;
        printf("Arrival time of process #%d: ", i + 1);
        scanf("%d", &processes[i].arrival);
        printf("Burst time of process #%d: ", i + 1);
        scanf("%d", &processes[i].burst);
        processes[i].remain = processes[i].burst;
    }
    
    roundRobin(numProcess, processes, quantum);
    
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

