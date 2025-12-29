/*
    Display Complete File Information

    1.Accept file name and display file metadata using stat( ):

    2.Size, inode, permissions, hard links, owner uid/gid, file type, last access/modify time.
*/

#include<stdio.h>                      // I/O
#include<sys/stat.h>                   // stat()
#include<string.h>                     // memset()
#include <time.h>                      // ctime()

int main()
{   
    struct stat sobj;

    char FileName[50];
    memset(FileName,'\0',sizeof(FileName));

    int iRet = 0;

    printf("Enter the file name : \n");
    scanf("%s",FileName);

    iRet = stat(FileName,&sobj);

    if(iRet == -1)
    {
        perror("Error");
        return 1;
    }

    printf("File size : %lu\n",sobj.st_size);

    printf("Inode number : %lu\n",sobj.st_ino);

    printf("Permission number is : %o\n",sobj.st_mode & 0777);

    printf("Hardlink count : %lu\n",sobj.st_nlink);

    printf("Owner uid : %d\n",sobj.st_uid);

    printf("Owner gid : %d\n",sobj.st_gid);

    
    if(S_ISBLK(sobj.st_mode))
    {
        printf("Block Device\n");
    }
    else if(S_ISCHR(sobj.st_mode))
    {
        printf("Character Device\n");
    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf("Directory file\n");
    }
    else if(S_ISREG(sobj.st_mode))
    {
        printf("Regular file\n");
    }
    else if(S_ISSOCK(sobj.st_mode))
    {
        printf("Socket file\n");
    }
    else if(S_ISFIFO(sobj.st_mode))
    {
        printf("Pipe file\n");
    }
    else if(S_ISLNK(sobj.st_mode))
    {
        printf("Symbolic file\n");

    }

    printf("Last Access Time: %s\n",ctime(&sobj.st_atime));

    printf("Last Modify Time: %s\n", ctime(&sobj.st_mtime));

    return 0;
}


/*
   Input = ./Demo.txt

   Output : File size : 0
            Inode number : 7242347
            Permission number is : 664
            Hardlink count : 1
            Owner uid : 1000
            Owner gid : 1000
            Regular file
            Last Access Time: Mon Dec 29 12:04:42 2025

            Last Modify Time: Mon Dec 29 12:04:42 2025
      
*/

