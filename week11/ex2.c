#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>


int main(int argc, char *argv[]){
    DIR *dir;
    dir = opendir("/");
    struct dirent *dirp;

    while ((dirp = readdir(dir)) != NULL) {
        printf("%s\n", dirp->d_name);
    }

    closedir(dir);
    exit(EXIT_SUCCESS);
}
