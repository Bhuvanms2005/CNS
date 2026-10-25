#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char msg[100],enc[100],dec[100];
    int key,i;
    printf("Enter the message to encrypt: ");
    fgets(msg,sizeof(msg),stdin);
    printf("Enter the Key: ");
    scanf("%d",&key);
    key=((key%26)+26)%26;
    for(i=0;msg[i]!='\0';i++)
    {
        if(isupper(msg[i]))
        {
            enc[i]=(msg[i]-'A'+key)%26+'A';
        }
        else if(islower(msg[i]))
        {
            enc[i]=(msg[i]-'a'+key)%26+'a';
        
        }
        else
        {
            enc[i]=msg[i];
        }
    }
    enc[i]='\0';
    printf("Encrypted Mesage:%s\n",enc);
    for(i=0;enc[i]!='\0';i++)
    {
        if(isupper(enc[i]))
        {
            dec[i]=(enc[i]-'A'-key+26)%26+'A';
        }
        else if(islower(enc[i]))
        {
            dec[i]=(enc[i]-'a'-key+26)%26+'a';
        }
        else
        {
            dec[i]=enc[i];
        }
    }
    dec[i]='\0';
    printf("Decrypted Message:%s\n",dec);
    return 0;

}