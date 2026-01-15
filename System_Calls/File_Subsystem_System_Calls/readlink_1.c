#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

int main()
{   
    int fd = 0;

    fd = open("./Test/LSPl.tct",O_RDONLY);

    if(fd == -1)
    {
        printf("unable to open the file : %d\n",strerror(errno));
        return -1;
    }

    printf("File opened with fd : %d\n",fd);

    close(fd);

    return 0;
}