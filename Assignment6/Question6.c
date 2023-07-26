#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    int fd = 0;
    int iRet = 0;

    fd = open(argv[1],O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    iRet = ftruncate(fd,1024);
    if(iRet == 0)
    {
        printf("Data has been successfully manipulated\n");
    }
    else
    {
        printf("Unable to remove data\n");
        return -1;
    }

    return 0;
}