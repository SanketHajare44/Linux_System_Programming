#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main()
{
    int fd = 0;
    char Buffer[] = "ABCDEFGHIJKLMNOPQRSTEWXYZ";
    int iRet = 0;

    fd = open("Demo.txt",O_WRONLY);
    if(fd < 0)
    {
        printf("Unable to open the file \n");
        printf("Reson : %s\n",strerror(errno));

        return -1;

    }

    printf("File successfully opend with : %d\n",fd);

    iRet = write(fd, Buffer, 10);

    printf("%d bytes successfully written\n",iRet);

    close(fd);

    return 0;
}
