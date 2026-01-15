#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{   
    struct stat sobj;
    int iRet = 0;

    iRet = stat("Demo.txt",&sobj);

    printf("Inode number : %lu\n",sobj.st_ino);

    printf("Hardlink count : %lu\n",sobj.st_nlink);

    printf("Total size : %lu\n",sobj.st_size);

    printf("Block size: %lu\n",sobj.st_blksize);

    return 0;
}