#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int fd = 0;
    char Buffer[30] = "Hello World";

    fd = open(argv[1],O_RDWR);
    if(fd == -1)
    {
        printf("Unable to write file\n");
        return -1;
    }
    else
    {
        printf("File is Successfully written with fd : %d\n",fd);
    }

    write(fd,Buffer,strlen(Buffer));

    return 0;
}