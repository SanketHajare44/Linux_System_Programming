#include<stdio.h>
#include<unistd.h>

int main()
{   int iRet = 0;

    iRet = truncate("Demo.txt",10);
    if(iRet == 0)
    {
        printf("Truncate is Succesful\n");
    }
    else
    {
        printf("Truncate is not  Succesful\n");
    }

    return 0;
}