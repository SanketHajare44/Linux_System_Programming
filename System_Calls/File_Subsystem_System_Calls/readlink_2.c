#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

int main()
{   
    char Path[100];
    int iRet = 0;

    memset(Path,'\0',sizeof(Path));

    iRet  = readlink("./Test/LSPl.txt",Path,sizeof(Path));
    
    if(iRet == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    Path[iRet] = '\0';
    
    printf("Data from radlink is : %s\n",Path);

    return 0;
}