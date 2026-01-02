#include<fcntl.h>
#include<stdio.h>

int main()
{   
    int fd = 0;
    
    fd = open("Second.c",O_CREAT,0777);

    if(fd == -1)
    {
        printf("Unable to create file\n");
    }
    else
    {
        printf("Files gets succesfully created with fd : %d\n",fd);
    }

    return 0;
}