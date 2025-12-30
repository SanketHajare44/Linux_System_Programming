/*
    Write String to File

    1.Accept file name and a string from user.

    2.Write the string into the file using write() system call.

    3.Open the file in append mode.

    4.Display the number of bytes written.
*/

#include<stdio.h>               // I/O
#include<fcntl.h>               // Open()
#include<unistd.h>              // write(), close()
#include<string.h>              // memset()

int main()
{   
    char FileName[50];
    memset(FileName, '\0', sizeof(FileName));

    char Arr[100];
    memset(Arr, '\0', sizeof(Arr));

    int fd, iRet;
    fd = 0;
    iRet = 0;

    printf("Enter the filename : \n");
    scanf("%s",FileName);

    printf("Enter the string : \n");
    scanf(" %[^\n]",Arr);

    fd = open(FileName, O_WRONLY | O_APPEND);

    if(-1 == fd)
    {
        perror("fail open() reson is");
        return 1;
    }
    
    iRet = write(fd, Arr, strlen(Arr));

    printf("The Total number of bytes are written : %d\n",iRet);

    close(fd);

    return 0;
}

/*
    ./Hello.txt file is used to write string on it 

    Input1 : ./Hello.txt
    Input2 : Jay Ganesh...

    Output : Jay Ganesh...  is Written on ./Hello.txt file

*/