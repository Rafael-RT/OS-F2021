#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define max_length 255

typedef struct files
{
    int *i_nodes;
    char **names;
    int number;

} files_t;

void search_entire_directory(char *path, files_t *my_files)
{
    DIR *current = opendir(path);
    struct dirent *dirent_data;
    while((dirent_data = readdir(current)) != NULL)
    {
        if(dirent_data -> d_type != DT_DIR)
        {
            char path2file[max_length];
            strcpy(path2file, path);
            strcat(path2file, dirent_data -> d_name);
            struct stat stat_data;
            if (stat(path2file, &stat_data) != -1 && stat_data.st_nlink >= 2)
            {
                int match = 0;
                for(int i=0; i < my_files -> number; i++)
                {
                    if(my_files -> i_nodes[i] == dirent_data -> d_ino)
                    {
                        match = 1;
                        strcat(my_files -> names[i], ", ");
                        strcat(my_files -> names[i], dirent_data -> d_name);
                        break;
                    }
                }
                if(!match)
                {
                    my_files -> i_nodes[my_files -> number] = dirent_data -> d_ino;
                    strcpy(my_files -> names[my_files -> number], dirent_data -> d_name);
                    my_files -> number++;
                }
            }
        }
        else
        {
            if(strcmp(dirent_data -> d_name, ".") != 0
                    && strcmp(dirent_data -> d_name, "..") != 0)
            {
                char path2dir[max_length];
                strcpy(path2dir, path);
                strcat(path2dir, dirent_data -> d_name);
                strcat(path2dir, "/");
                search_entire_directory(path2dir, my_files);
            }
        }
    }
    closedir(current);
}

int main()
{
    DIR *tmp = opendir("./tmp/");
    if(tmp == NULL)
    {
        printf("There is no such directory.");
        return -1;
    }
    struct dirent *f;
    int n_files = 0;
    while((f = readdir(tmp)) != NULL)
        n_files++;
        
    closedir(tmp);
    files_t my_files;
    
    my_files.number = 0;
    my_files.i_nodes = malloc(n_files * sizeof(int));
    my_files.names = malloc(n_files * sizeof(char*));
    for (int i = 0; i < n_files; i++)
        my_files.names[i] = malloc(max_length * sizeof(char));
        
    search_entire_directory("./tmp/", &my_files);
    
    for(int i=0; i < my_files.number; i++)
        printf("Files %s have same i-node %d.\n", my_files.names[i], my_files.i_nodes[i]);
    return 0;
}
