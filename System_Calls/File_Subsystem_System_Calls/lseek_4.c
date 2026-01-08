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

    memset(Buffer,'\0',SIZE_BUFFER);

    fd = open("Hole.txt",O_WRONLY | O_CREAT);

    if(fd < 0)
    {
        printf("Unable to open the file \n");
        printf("Reson : %s\n",strerror(errno));

        return -1;

    }

    printf("File successfully opend with fd : %d\n",fd);

    iRet = lseek(fd,4100,SEEK_SET);

    printf("Current offest is  : %d\n",iRet);

    write(fd,"END",1);

    printf("%d bytes gets written successfully\n",iRet);

    close(fd);

    return 0;
}
