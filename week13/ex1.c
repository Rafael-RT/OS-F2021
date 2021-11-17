#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define separator_state "\n=======\nState\n=======\n"
#define separator_verdict "\n=======\nVerdict\n=======\n"

#define n 5 // Number of processes
#define m 3 // Number of resource types

typedef struct process_D {
    int id;
    int done;
    int C[m];
    int R[m];
} process_t;

int E[m];
int A[m];
process_t process[n];

void read_input(char* filename) {
    FILE *input;
    input = fopen(filename, "r");
    
    if (input == NULL) {
        printf("Input file doesn't exist!\n");
        return;
    }
    
    for (int j = 0; j < m; j++) {
        fscanf(input, "%d", &E[j]);
    }
    
    for (int j = 0; j < m; j++) {
        fscanf(input, "%d", &A[j]);
    }
    
    for (int PID = 0; PID < n; PID++) {
        process[PID].id = PID;
        process[PID].done = FALSE;
    }

    for (int PID = 0; PID < n; PID++) {
      for (int j = 0; j < m; j++) {
            fscanf(input, "%d", &process[PID].C[j]);
        }
    }

    for (int PID = 0; PID < n; PID++) {
      for (int j = 0; j < m; j++) {
            fscanf(input, "%d", &process[PID].R[j]);
        }
    }
}

void release_resources(int PID) {
    for (int j = 0; j < m; j++) {
        A[j] = A[j] + process[PID].C[j];
        process[PID].C[j] = 0;
        process[PID].R[j] = 0;
        process[PID].done = TRUE;
    }
}

int find_candidate() {
  for (int PID = 0; PID < n; PID++) {
    if (process[PID].done == TRUE) {
      continue;
    }

    for (int j = 0; j < m; j++) {
      if (process[PID].R[j] > A[j]) {
        break;
      }

      if (j + 1 == m) {
        return PID;
      }
    }
  }
  return -1;
}

void print_state(int verdict) {
    if (verdict == TRUE) {
      printf(separator_verdict);
    } else {
      printf(separator_state);
    }

    printf("Total exists: (");
    for (int j = 0; j < m; j++) {
        printf("%d", E[j]);
        
        if (j + 1 == m) {
            printf(")\n");
        } else {
            printf(", ");
        }
    }

    printf("Total available: (");
    for (int j = 0; j < m; j++) {
        printf("%d", A[j]);
        
        if (j + 1 == m) {
            printf(")\n");
        } else {
            printf(", ");
        }
    }

    for (int PID = 0; PID < n; PID++) {
        printf("Process %d ", process[PID].id);

        if (verdict == TRUE) {
          if (process[PID].done == FALSE) {
            printf("is deadlocked!\n");
          } else {
            printf("is done.\n"); 
          }

        } else {
          if (process[PID].done == FALSE) {
            printf("is not yet finished. Needs (");
            for (int j = 0; j < m; j++) {
                printf("%d", process[PID].R[j]);
                
                if (j + 1 == m) {
                  printf(") more.\n");
                } else {
                    printf(", ");
                }
            }
          } else {
            printf("is done.\n");
          }
        }
    }
}

int main(int argc, const char * argv[]) {
    int candidate;
    read_input("input_dl.txt");
  
    while (TRUE) {
      print_state(FALSE);

      candidate = find_candidate();
      if (candidate == -1){
        break;
      }

      release_resources(candidate);
    }

    print_state(TRUE);

    return 0;
}
