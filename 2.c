#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char msg[100],key[100],enc[100],dec[100];
    int i,k;
    printf("Enter the message to encrypt: ");
    fgets(msg,sizeof(msg),stdin);
    printf("Enter the Key: ");
    fgets(key,sizeof(key),stdin);
    for(i=0;msg[i]!='\0';i++)
    {
        if(isupper(msg[i]))
        {
            enc[i]=toupper(key[msg[i]-'A']);
        }
        else if(islower(msg[i]))
        {
            enc[i]=tolower(key[msg[i]-'a']);
        }
        else
        {
            enc[i]=msg[i];
        }
    }
    enc[i]='\0';
    printf("Encrypted message: %s", enc);
    for(i=0;enc[i]!='\0';i++)
    {
        if(isupper(enc[i]))
        {
           for(k=0;k<26;k++)
            {
                if(toupper(key[k]==enc[i]))
                {
                    break;
                }
            }
        dec[i]='A'+k;
        }
        else if(islower(enc[i]))
        {
            for(k=0;k<26;k++)
            {
                if(tolower(key[k]==enc[i]))
                {
                    break;
                }
            }
        dec[i]='a'+k;
        }
        else
        {
            dec[i]=enc[i];
        }
    }
    dec[i]='\0';
    printf("Decrypted message: %s", dec);
    return 0;
}