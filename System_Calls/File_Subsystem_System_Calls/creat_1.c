#include<fcntl.h>
#include<stdio.h>


int main()
{
    int fd = creat("LSP.txt",0777);
    
    if(fd == -1)
    {
        printf("unable to create file\n");
    }
    else
    {
        printf("File gets succesfully created with fd : %d\n",fd);
    }

    return 0;
}