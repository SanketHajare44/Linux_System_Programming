/*
    Open File

    1.Accept file name from user and open it using open().

    2.Print: success message + returned file descriptor.

    3.Handle errors using perror().
*/

#include<stdio.h>                      // I/O
#include<fcntl.h>                      // open()
#include<unistd.h>                     // close()

int main()
{
    char filename[50];
    memset(filename,'\0',sizeof(filename));

    int fd;

    printf("Enter file name: ");
    scanf("%s",filename);

    fd = open(filename, O_RDONLY);

    if (-1 == fd)
    {
        perror("Error Opening file ");
        return 1;
    }

    printf("File opened successfully.\n");
    printf("File Descriptor: %d\n", fd);

    close(fd);

    return 0;
}

/*
    Demo.txt file is used

    Input = ./Demo.txt     Output = File opened successfully.
                                    File Descriptor: 3
*/