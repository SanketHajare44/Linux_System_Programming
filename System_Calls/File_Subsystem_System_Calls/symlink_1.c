#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>

int main()
{   
    int iRet = 0;

    iRet = symlink("DemoX.txt","Hello.txt");

    if(iRet==0)
    {
        printf("symlink is succesfull\n");
    }
    else
    {
        printf("%s\n",strerror(errno));
    }

    return 0;
}