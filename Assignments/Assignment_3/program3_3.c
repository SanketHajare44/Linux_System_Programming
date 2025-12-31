/*

    Move All Files (Dir → Dir)

    1.Accept source dir and destination dir.

    2.Move all regular files:

    3.Use rename() if same filesystem.

    4.Else copy + delete.

    5.Print count of moved files.

*/

#include<stdio.h>                   // I/O
#include<string.h>                  // Memset(), strerror() 
#include<errno.h>                   // errno
#include<dirent.h>                  // opendir(), closedir()
#include<sys/stat.h>                // struct stat
#include<unistd.h>                  // getcwd()

int main()
{
    char SrcDir[50];
    memset(SrcDir, '\0', sizeof(SrcDir));

    char DestDir[50];
    memset(DestDir, '\0', sizeof(DestDir));

    char SrcPath[700];
    memset(SrcPath, '\0', sizeof(SrcPath));

    char DestPath[700];
    memset(DestPath, '\0', sizeof(DestPath));

    char AbsolutePath[200];
    memset(AbsolutePath, '\0', sizeof(AbsolutePath));   

    struct dirent *ptr = NULL;
    char *path = NULL;
    struct stat sobj;
    
    int iCount = 0;
    int iRet = 0;
    DIR *dp = NULL;


    printf("Enter the Source directory : ");
    scanf(" %[^\n]",SrcDir);
    
    printf("Enter the Destination directory :");
    scanf(" %[^\n]",DestDir);


    dp = opendir(SrcDir);

    if(NULL == dp)
    {
        perror("opendir fail");
        return -1;
    }

    mkdir(DestDir, 0777);

    path = getcwd(AbsolutePath, sizeof(AbsolutePath));

    if(NULL == path)
    {
        printf("getcwd failed\n");
        perror("Reason is ");
        return -1;
    }

    while((ptr = readdir(dp)) != NULL)
    {
        if((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0))
        {
            continue;
        }

        snprintf(SrcPath, sizeof(SrcPath), "%s/%s/%s", AbsolutePath, SrcDir, ptr->d_name);

        iRet = stat(SrcPath,&sobj);

        if(iRet != 0)
        {
            printf("There is issue in stat\n");
            perror("Reason is");
            continue;
        }

        if(S_ISREG(sobj.st_mode))
        {
            snprintf(DestPath, sizeof(DestPath), "%s/%s/%s", AbsolutePath, DestDir, ptr->d_name);

            iRet = rename(SrcPath,DestPath);
            if(iRet == 0)
            {
                printf("rename succesfully\n");
                iCount++;
            }
            else
            {
                printf("%s\n",strerror(errno));
                return -1;
            }

        }
    }

    printf("Total regular files are moved : %d\n",iCount);
    closedir(dp);

    return 0;
}

/*
    Input1 : Test   //(It contains 2 regular files Hello.txt and Demo.txt)

    Input2 : Data

    Output : rename succesfully
             rename succesfully
             Total regular files are moved : 2

*/