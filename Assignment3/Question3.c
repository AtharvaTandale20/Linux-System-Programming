#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    int iRet = 0;

    char FilePath_Source[50] = {'\0'};
    char FilePath_Destination[50] = {'\0'};

    DIR *dp_source = NULL;

    struct dirent * entry = NULL;

    dp_source = opendir(argv[1]);
    if(dp_source == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp_source)) != NULL)
    {
        if((strcmp(entry->d_name,"..") == 0) || (strcmp(entry->d_name,".") == 0))
        {
            continue;
        }

        sprintf(FilePath_Source,"%s/%s",argv[1],entry->d_name);
        sprintf(FilePath_Destination,"%s/%s",argv[2],entry->d_name);

        iRet = rename(FilePath_Source,FilePath_Destination);
        if(iRet != 0)
        {
            printf("Unable to move file\n");
            return -1;
        }
    }

    printf("Files moved successfully\n");

    closedir(dp_source);

    return 0;
}