/*

    Delete all empty regular files

    1.Accept directory name

    2.Delete files with size = 0 bytes(regular files only)

    3.Print names deleted + total deleted count

*/


#include<stdio.h>                   // I/O
#include<string.h>                  // memset(), strcmp()
#include<dirent.h>                  // opendir() closedir()
#include<sys/stat.h>                // struct stat
#include<unistd.h>                  // unlink()

int main()
{
    char DirName[50];
    memset(DirName, '\0', sizeof(DirName));

    char FilePath[500];
    memset(FilePath, '\0', sizeof(FilePath));

    DIR *dp = NULL;

    struct dirent *ptr = NULL;

    struct stat sobj;

    int iRet = 0;
    int iCount = 0;

    printf("Enter directory name : \n");
    scanf(" %[^\n]", DirName);

    dp = opendir(DirName);

    if(NULL == dp)
    {
        perror("opendir failed");

        return -1;
    }

    while((ptr = readdir(dp)) != NULL)
    {
        if((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0))
        {
            continue;
        }

        snprintf(FilePath, sizeof(FilePath),"%s/%s", DirName, ptr->d_name);

        iRet = stat(FilePath, &sobj);

        if(0 != iRet)
        {
            perror("stat failed");
            continue;
        }

        if(S_ISREG(sobj.st_mode) && sobj.st_size == 0)
        {
            iRet = unlink(FilePath);
            if(-1 == iRet)
            {
                perror("unlink failed");
            }

            printf("Deleted : %s\n",ptr->d_name);
            iCount++;
        }
    }

    printf("Total deleted file count : %d\n",iCount);

    closedir(dp);

    return 0;
}

/*
    Data Directory contains 2 file Hello.txt (6 bytes) and Demo.txt (0 bytes)

    Input : Data

    Output : Deleted : Demo.txt
             Total deleted file count : 1

*/