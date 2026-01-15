#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

int main()
{   
    char Path[100];
    memset(Path,'\0',sizeof(Path));

    int iRet = 0;
    int fd = 0;

    char Arr[20];
    memset(Arr,'\0',sizeof(Arr));

    
    iRet  = readlink("./Test/LSPl.txt",Path,sizeof(Path));
    
    if(iRet == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    Path[iRet] = '\0';
    
    printf("Data from radlink is : %s\n",Path);

    fd = open(Path,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file \n");
        return -1;
    }

    read(fd, Arr,10);

    printf("Data from original file  : %s\n",Arr);
    close(fd);

    return 0;
}