#include<fcntl.h>
#include<stdio.h>

int main()
{   
    int fd = 0;
    
    fd = open("Second.c",O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("Files gets succesfully opened with fd : %d\n",fd);
    }

    return 0;
}