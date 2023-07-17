#include<stdio.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    int fd = 0;

    fd = mkdir(argv[1],0777);
    if(fd == -1)
    {
        printf("Unable to create a new directory\n");
        return -1;
    }
    else
    {
        printf("Directory is successfully created with fd : %d\n",fd);
    }

    return 0;
}