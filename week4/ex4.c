#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char com[256];
    
    fgets(com, sizeof(com), stdin);
    char** argv = (char**) malloc(256);
    
    argv[0] = (char*)malloc(sizeof(com));
    
    
    int j=0,k=0;
    for(int i = 0; i < sizeof(com);){
        if(com[i] != '\0' && com[i] != ' ' && com[i]!='\n'){	
            argv[j][k++] = com[i++];
	}
	else if (com[i] == ' '){
		j++;
		argv[j] = (char*)malloc(256);
		i++;
		k = 0;
	}	
	else{
		break;
	}
    }    
    
    if(fork() == 0){
        execvp(argv[0],argv);
    }
    
    
    return 0;
}
