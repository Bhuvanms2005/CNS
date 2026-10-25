#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int key[3][3],i,j,k,n,sum;
    char msg[100];
    printf("Enter the message to encrypt:");
    scanf("%s",msg);
    printf("Enter the size o the key matrix:");
    scanf("%d",&n);
    printf("Enter the key matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&key[i][j]);
        }
    }
    int len=strlen(msg);
    for(i=0;i<len;i++)
    {
        msg[i]=toupper(msg[i]);
    }
    while(len%n!=0)
    {
        msg[len++]='X';
    }
    msg[len]='\0';
    printf("Encrypted message: ");
    for(i=0;i<len;i+=n)
    {
        for(j=0;j<n;j++)
        {
            sum=0;
            for(k=0;k<n;k++)
            {
                sum+=key[j][k]*(msg[i+k]-'A');
            }
            printf("%c", (sum % 26) + 'A');
        }
    }
    return 0;
}