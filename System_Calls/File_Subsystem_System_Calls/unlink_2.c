#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{   int iRet = 0;

    iRet = unlink("Demo.txt");

    if(iRet==0)
    {
        printf("Unlink is succesfull\n");
    }

    return 0;
}