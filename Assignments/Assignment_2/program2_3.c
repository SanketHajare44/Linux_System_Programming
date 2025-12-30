/*
   List All Files From Directory

    1.Accept directory name.

    2.Use opendir() / readdir() to print only names (skip . and ..). 
*/

#include<stdio.h>               // I/O
#include<string.h>              // memset()
#include<dirent.h>              // readdir()

int main()
{   
    char DirName[20];
    memset(DirName, '\0',sizeof(DirName));

    DIR *dp = NULL;
    struct dirent *ptr = NULL;

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
        if((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0))
        {
            continue;
        }

        printf("%s\n",ptr->d_name);
    }

    closedir(dp);

    return 0;
}

/*

    Input  : ./Test     Output : Hello.txt
                                 Demo.txt

*/