#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Insufficient arguments");
        return -1;
    }

    int FdSource = 0,FdDest = 0,iRet = 0;
    char Buffer[BLOCKSIZE] = {'\0'};

    FdSource = open(argv[1],O_RDONLY);
    if(FdSource == -1)
    {
        printf("Unable to open source file\n");
        close(FdSource);
        return -1;
    }

    FdDest = creat(argv[2],0777);
    if(FdDest == -1)
    {
        printf("Unable to create destination file\n");
        close(FdSource);
        return -1;
    }

    while((iRet = read(FdSource,Buffer,sizeof(Buffer))) != 0)
    {
        write(FdDest,Buffer,iRet);
        memset(Buffer,0,sizeof(Buffer));
    }

    close(FdSource);
    close(FdDest);

    return 0;
}