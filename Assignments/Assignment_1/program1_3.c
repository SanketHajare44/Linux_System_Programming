/*
    Check File Access Permission

    1.Accept file name and mode (read/write/execute).

    2.Use access( ) to check permission for current process.

    3.Print “Accessible / Not accessible” with reason.
*/

#include<stdio.h>                      // I/O
#include<unistd.h>                     // close()
#include<errno.h>                      // errno
#include<string.h>                     // strerror(),

int main()
{
    char filename[50];
    memset(filename,'\0',sizeof(filename));
    int mode;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter permission number to check (4-Read, 2-Write, 1-Execute): ");
    scanf("%d", &mode);

    if (access(filename, mode) == 0)
    {
        printf("Accessible\n");
    }
    else
    {
        printf("Not accessible : %s\n",strerror(errno));
    }

    return 0;
}

/*
    Hello.txt file is created with only Read permession

    Input1 = ./Hello.txt    Input2 = 4      Output = Accessible
    
    Input1 = ./Hello.txt    Input2 = 2      Output = Not accessible: Permission denied

    Input1 = ./Hello.txt    Input2 = 1      Output = Not accessible: Permission denied      
*/
