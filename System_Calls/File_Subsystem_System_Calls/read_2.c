#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#define SIZE_BUFFER 100

int main()
{
    int fd = 0;
    char Buffer[SIZE_BUFFER];
    int iRet = 0;

    memset(Buffer,'\0',SIZE_BUFFER);   // change compeleted

    fd = open("Demo.txt",O_RDONLY);

    if(fd < 0)
    {
        printf("Unable to open the file \n");
        printf("Reson : %s\n",strerror(errno));

        return -1;

    }

    printf("File successfully opend with fd : %d\n",fd);

    iRet = read(fd, Buffer, 10);

    printf("%d bytes successfully read\n",iRet);

    printf("Data from file : %s\n",Buffer);

    close(fd);

    return 0;
}
