#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{   
    struct stat sobj;
    int iRet = 0;

    iRet = stat("Demo.txt",&sobj);

    if(iRet == 0)
    {
        printf("stat works succesfully\n");
    }
    else
    {
        printf("There is issue in stat\n");
        return -1;
    }

    return 0;
}