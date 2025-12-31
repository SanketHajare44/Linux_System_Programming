/*

    Check File Present in Directory

    1.Accept directory name and file name.

    2.Check whether that file exists in that directory.

    3.Print absolute matched path if found.

*/

#include<stdio.h>                   // I/O
#include<string.h>                  // memset()
#include<dirent.h>                  // opendir(), closedir()
#include<unistd.h>                  // getcwd()

int main()
{
    char DirName[50];
    memset(DirName, '\0', sizeof(DirName));

    char FileName[50];
    memset(FileName, '\0', sizeof(FileName));

    char AbsolutePath[300];
    memset(AbsolutePath, '\0', sizeof(AbsolutePath));

    char *path = NULL;
    
    DIR *dp = NULL;
    struct dirent *ptr;

    printf("Enter Directory name : ");
    scanf(" %[^\n]",DirName);

    printf("Enter file name : ");
    scanf(" %[^\n]",FileName);

    dp = opendir(DirName);

    if(NULL == dp)
    {
        perror("Directory open failed");
        closedir(dp);
        return -1;
    }

    path = getcwd(AbsolutePath, sizeof(AbsolutePath));

    if(NULL == path)
    {
        printf("getcwd failed\n");
        perror("Reason is ");
        
        return -1;
    }

    
    while((ptr = readdir(dp)) != NULL)
    {   
        if(strcmp(FileName, ptr->d_name) == 0)
        {   
            strcat(AbsolutePath, "/");
            strcat(AbsolutePath, DirName);
            strcat(AbsolutePath, "/");
            strcat(AbsolutePath, FileName);

            printf("File found at : %s\n",AbsolutePath);

            closedir(dp);

            return 0;
        }
    }

    closedir(dp);

    return 0;
}

/*
Input1 : Test    
Input2 : Hello.txt
Output : File found at : /home/sanket-hajare/PPA2/System_Programming/Assignments/Assignment_3/Test/Hello.txt

*/