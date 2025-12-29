/*
    Read N Bytes From File

    1.Accept file name and number of bytes N.

    2.Read exactly N bytes using read() and print on console.

    3.If file contains less than N, print only available bytes.
*/


#include<stdio.h>               // I/O           
#include<fcntl.h>               // open()
#include<unistd.h>              // close()
#include<errno.h>               // errno
#include<string.h>              // memset, strerror()

int main()
{
    char filename[50];
    memset(filename,'\0',sizeof(filename));

    char Arr[100];
    memset(Arr, '\0', sizeof(Arr));

    int fd = 0, No = 0;
    int iRet = 0;

    printf("Enter the name of file : \n");
    scanf("%s",filename);

    fd = open(filename,O_RDONLY);

    if(-1 == fd)
    {
        printf("Unable to open the file\n");
        printf("Reson : %s\n",strerror(errno));

        return 1;
    }

    printf("Enter how many bytes want to read : \n");
    scanf("%d",&No);

    iRet = read(fd, Arr, No);

    printf("Total number of bytes are read : %d\n",iRet);

    if(iRet > 0)
    {
        write(1, Arr, iRet);
        printf("\n");
    }

    close(fd);

    return 0;
}


/*

    Input1 = ./Demo.txt

    Input2 = 30   

    Output : Total number of bytes are read : 21
             MarvellousInfoSystems

*/

