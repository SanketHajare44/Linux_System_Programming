#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{   
    int iRet = 0;
    int fd = 0;

    fd = open("Demo.txt",O_RDWR);

    iRet = ftruncate(fd,5);

    if(iRet == 0)
    {
        printf("Truncate is Succesful\n");
    }
    else
    {
        printf("There is issue  in ftruncate \n");
    }

    return 0;
}