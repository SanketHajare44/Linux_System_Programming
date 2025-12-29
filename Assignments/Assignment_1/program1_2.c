/*
    Open File in Given Mode

    1.Accept file name and mode (R, W, RW, A) from user.

    2.Convert mode to flags (O_RDONLY, O_WRONLY, O_RDWR, O_APPEND | O_CREAT).

    3.Open file accordingly and display fd.
*/

#include<stdio.h>                      // I/O
#include<fcntl.h>                      // open()
#include<unistd.h>                     // close()
#include<string.h>                     // strerror(), strcmp()
#include<errno.h>                      // errno

int main()
{
    char filename[100];
    memset(filename,'\0',sizeof(filename));

    char mode[5];
    memset(mode,"\0",sizeof(mode));

    int fd;
    int flag = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter mode (R, W, RW, A): ");
    scanf("%s", mode);
    
    if (strcmp(mode, "R") == 0)         // comparing string
    {
        flag = O_RDONLY;
    }  
    else if (strcmp(mode, "W") == 0)
    {
        flag = O_WRONLY;
    }
    else if (strcmp(mode, "RW") == 0)
    {
        flag = O_RDWR;
    }
    else if (strcmp(mode, "A") == 0)
    {
        flag = O_APPEND | O_CREAT;
    }
    else
    {
        printf("Invalid mode\n");
        return 1;
    }

    fd = open(filename, flag, 0777);

    if (fd == -1)
    {
        printf("Error is : %s/n",strerror(errno));
        return 1;
    }

    printf("File opened successfully mode :\n");
    printf("File Descriptor: %d\n",fd);

    close(fd);
    return 0;
}


/*
    Demo.txt file is used

    Input1 = ./Demo.txt    Input2 = R       Output = File opened successfully mode :
                                                     File Descriptor: 3

    Input1 = ./Demo.txt    Input2 = W       Output = File opened successfully mode :
                                                     File Descriptor: 3

    Input1 = ./Demo.txt    Input2 = RW       Output = File opened successfully mode :
                                                     File Descriptor: 3

    Input1 = ./Demo.txt    Input2 = A       Output = File opened successfully mode :
                                                      File Descriptor: 3
*/
