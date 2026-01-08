#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
    int fd = 0;
    int iRet = 0;

    off_t offset = 0;

    char Buffer[100];

    fd = open("./LSP.txt",O_RDONLY);

    offset = lseek(fd,10,SEEK_SET);
    printf("Currrent offset is  : %ld\n",offset);      // 0

    iRet = read(fd,Buffer,5);

    printf("\n");
    write(1,Buffer,iRet);
    printf("\n");

    offset = lseek(fd,0,SEEK_CUR);
    printf("Currrent offset is  : %ld\n",offset);      // 10

    return 0;
}