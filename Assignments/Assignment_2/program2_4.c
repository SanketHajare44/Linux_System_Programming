/*

    List Files with Type

    1.Accept directory name.

    2.Print each entry with its type: Regular / Directory / Link / FIFO / Socket / Char / Block

    3.Use lstat() for accurate type.

*/

#include<stdio.h>               // I/O
#include<string.h>              // memset()
#include<dirent.h>              // readdir()
#include<sys/stat.h>            // struct stat

int main()
{   
    char DirName[20];
    memset(DirName, '\0',sizeof(DirName));

    char path[50];
    memset(path, '\0', sizeof(path));

    DIR *dp = NULL;
    struct dirent *ptr = NULL;

    struct stat sobj;

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

        iRet = lstat(path,&sobj);

        if(-1 == iRet)
        {
            perror("lstat fail reason is ");
            return -1;
        }

        printf("%s\n",ptr->d_name);

        if(S_ISREG(sobj.st_mode))
        {
            printf("Regular file\n");
        }
        else if(S_ISDIR(sobj.st_mode))
        {
            printf("Directory\n");
        }
        else if(S_ISCHR(sobj.st_mode))
        {
            printf("Character device file\n");
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            printf("Symbolic Link file\n");
        }
        else if(S_ISSOCK(sobj.st_mode))
        {
            printf("Socket file\n");
        }
        else if(S_ISFIFO(sobj.st_mode))
        {
            printf("Pipe file\n");
        }
        else if(S_ISBLK(sobj.st_mode))
        {
            printf("Block device\n");
        }
        
    }
    
    closedir(dp);

    return 0;
}

/*

    Input  : ./Test     Output : Hello.txt
                                 Regular file
                                 Demo.txt
                                 Regular file

*/