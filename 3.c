#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char msg[100],key[100],a[5][5],text[200];
    int used[26]={0};
    int i,j,k=0,n=0;
    int r1,c1,r2,c2;
    printf("Enter the message to encrypt: ");
    fgets(msg,sizeof(msg),stdin);
    printf("Enter the Key: ");
    fgets(key,sizeof(key),stdin);
    used[9]=1;
    for(i=0;key[i]!='\0';i++)
    {
        char ch=toupper(key[i]);
        if(ch>='A' && ch<='Z')
        {
            if(ch=='J')
            {
                ch='I';
            }
            if(!used[ch-'A'])
            {
                a[k/5][k%5]=ch;
                used[ch-'A']=1;
                k++;
            }
        }
    }
    for(i=0;i<26;i++)
    {
        if(!used[i])
        {
            a[k/5][k%5]='A'+i;
            k++;
        }
    }
    for(i=0;msg[i]!='\0';i++)
    {
        char ch=toupper(msg[i]);
        if(ch>='A' && ch<='Z')
        {
            if(ch=='J')
            {
                ch='I';
            }
            text[n++]=ch;
        }
    }
    text[n]='\0';
    n=0;
    while(text[n]!='\0')
    {
        char x=text[n++],y;
        if(text[n]=='\0')
        {
            y='x';
        }
        else if(text[n]==x)
        {
            y='X';
        }
        else
        {
            y=text[n++];
        }
        r1=c1=r2=c2=0;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(a[i][j]==x)
                {
                    r1=i;
                    c1=j;
                }
                if(a[i][j]==y)
                {
                    r2=i;
                    c2=j;
                }
            }
        }
        if(r1==r2)
        {
            printf("%c%c",a[r1][(c1+1)%5],a[r2][(c2+1)%5]);
        }
        else if(c1==c2)
        {
            printf("%c%c",a[(r1+1)%5][c1],a[(r2+1)%5][c2]);
        
        }
        else
        {
            printf("%c%c",a[r1][c2],a[r2][c1]);
        }
    }
    return 0;
}