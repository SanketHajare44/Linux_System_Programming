/*
    Find Largest File in Directory

    1. Accept directory name.

    2. Find largest regular file.

    3. Print file name and its size in bytes.
*/

#include<stdio.h>               // I/O
#include<sys/stat.h>            // struct stat
#include<dirent.h>              // opendir(), closedir()
#include<string.h>              // memset()


int main()
{   
    char DirName[50];
    memset(DirName, '\0', sizeof(DirName));


    char path[50];
    memset(path, '\0', sizeof(path));

    char FileName[50];
    memset(FileName, '\0', sizeof(FileName));

    struct dirent *ptr = NULL;

    struct stat sobj;

    DIR *dp = NULL;

    int MaxValue = 0;
    int iRet = 0;

    printf("Enter the Directory name : \n");
    scanf(" %[^\n]",DirName);

    dp = opendir(DirName);

    if(NULL == dp)
    {
        perror("fail opendir() resaon is");
        return -1;
    }

    while((ptr = readdir(dp)) != NULL)
    {   
        int i = 0, j = 0;

        if(strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
        {
            continue;
        }

        while(DirName[i] != '\0')
        {
            path[i] = DirName[i];
            i++;
        }

        path[i] = '/';
        i++;

        while(ptr->d_name[j] != '\0')
        {
            path[i] = ptr->d_name[j];
            i++;
            j++;
        }

        path[i] = '\0';

        iRet = stat(path,&sobj);

        if(iRet == -1)
        {
            perror("fail stat resaon is ");
            return -1;
        }

        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size > MaxValue)
            {
                MaxValue = sobj.st_size;

                strcpy(FileName, ptr->d_name);
            }
        }

    }

    printf("\nLargest File Name : %s\n", FileName);

    printf("Largest File Size : %d bytes\n", MaxValue);

    closedir(dp);

    return 0;
}

/*

    Input  : ./Test     Output : Largest File Name : Demo.txt
                                 Largest File Size : 19 bytes
                                 
                                 

*/