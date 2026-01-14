#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int iRet = 0;
    int fd = 0;
    char Arr[100];

    fd = open("./process.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open flle \n");
        return -1;
    }

    iRet = rename("./process.txt","./Test/Hello.txt");

    if(iRet == 0)
    {
        printf("rename succesfully\n");
    }
    else
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    iRet = read(fd,Arr,50);

    if(iRet != 0)
    {
        printf("Data from file is %s\n",Arr);
    }

    close(fd);

    return 0;
}