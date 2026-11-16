#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char msg[100],key[100];
    int i,j,len,klen,choice;
    printf("Enter the message: ");
    scanf("%s",msg);
    printf("Enter the key: ");
    scanf("%s",key);
    len=strlen(msg);
    klen=strlen(key);
    if(klen==0)
    {
        printf("Key cannot be empty");
        return 1;
    }
    printf("1. Encryption\n2. Decryption\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    for(i=0,j=0;i<len;i++)
    {
        if(isalpha((unsigned char) msg[i]))
        {
            char ch=toupper((unsigned char)msg[i]);
            char k=toupper((unsigned char)key[j%klen]);
            if(!isalpha((unsigned char)k))
            {
                printf("\nKey must contain only letters!\n");
                return 1;
            }
            if(choice==1)
            {
                ch=(ch-'A'+k-'A')%26+'A';
            }
            else if(choice==2)
            {
                ch=(ch-'A'-(k-'A')+26)%26+'A';
            }
            else
            {
                printf("\nInvalid choice!\n");
                return 1;
            }
            printf("%c", ch);
            j++;
        }
        else
        {
            printf("%c", msg[i]);
        }
    }
    printf("\n");
    return 0;
}