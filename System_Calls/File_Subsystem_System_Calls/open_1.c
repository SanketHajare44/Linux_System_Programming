#include<fcntl.h>
#include<stdio.h>

int main()
{   
    int fd = 0;
    
    fd = open("First.c",O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("Files gets succesfully opened with if : %d\n",fd);
    }

    return 0;
}