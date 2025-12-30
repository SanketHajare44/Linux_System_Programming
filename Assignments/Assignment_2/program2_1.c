/*
    Read Whole File

    1.Accept file name and print full content on console.

    2.Use a buffer loop (read() until 0).

    3.Show total bytes read.
*/

#include<stdio.h>               // I/O
#include<fcntl.h>               // Open()
#include<unistd.h>              // read(), close()

int main(int argc, char *argv[])
{
    char FilName[50];
    char Arr[100];

    int fd = 0;
    int Bytes = 0, TotalBytes = 0;

    fd = open(argv[1], O_RDONLY);

    if(-1 == fd)
    {
        perror("open fail");
        return 1;
    }

    while((Bytes = read(fd, Arr, sizeof(Arr))) > 0)
    {
        write(1, Arr, Bytes);

        TotalBytes = TotalBytes + Bytes;
    }

    printf("\n");

    printf("Total no of bytes are read : %d\n",TotalBytes);

    close(fd);

    return 0;
}

/*

    Input : ./Demo.txt

    Output : India is my country
             Total no of bytes are read : 19

*/