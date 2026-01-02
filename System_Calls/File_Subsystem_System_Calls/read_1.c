#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main()
{
    int fd = 0;
    char Buffer[100] = {'\0'};
    int iRet = 0;

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
