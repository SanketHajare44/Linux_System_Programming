/*

    Copy File Contents (source → destination)

    1.Accept source_file and dest_file.

    2.Create destination if not exists (O_CREAT | O_TRUNC).

    3.Copy using buffered read() / write() loop.

    4.Preserve permissions (optional bonus using stat() + chmod()).

*/

#include<stdio.h>                   // I/O
#include<string.h>                  // memset()
#include<fcntl.h>                   // open()
#include<sys/stat.h>                // struct stat
#include<unistd.h>                  // read(), write(), close()

int main()
{
    char Source[50];
    memset(Source, '\0', sizeof(Source));

    char Destination[50];
    memset(Destination, '\0', sizeof(Destination));

    char Arr[1024];
    memset(Arr, '\0', sizeof(Arr));

    struct stat sobj;

    int fd1 = 0, fd2 = 0;
    int bytes = 0;

    printf("Enter source file : ");
    scanf(" %[^\n]",Source);

    printf("Enter Destination file : ");
    scanf(" %[^\n]",Destination);

    fd1 = open(Source, O_RDONLY);

    if(-1 == fd1)
    {
        perror("Unable to open Source file");
        close(fd1);
        return -1;
    }

    fd2 = open(Destination, O_WRONLY | O_CREAT | O_TRUNC, 0777);

    if(-1 == fd2)
    {
        perror("Unable to open destination file");
        close(fd2);
        return -1;
    }

    while((bytes = read(fd1, Arr, sizeof(Arr))) != 0)
    {
        write(fd2, Arr, bytes);
    }

    stat(Source, &sobj);
    chmod(Destination, sobj.st_mode);


    close(fd2);
    close(fd1);


    return 0;
}

/*

Source file is consider as program3_1.c and Destination file is Hello.txt create using the open()
system call

    Input1 : program3_1.c  Input2 : Hello.txt  Output : Copied all data on Hello.txt

*/