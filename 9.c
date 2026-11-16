#include<stdio.h>
#include<string.h>
#include<openssl/aes.h>
int main()
{
    AES_KEY enc_key,dec_key;
    unsigned char msg[]="Welcome to ISE";
    unsigned char encrypted[128];
    unsigned char decrypted[128];
    unsigned char key[16]="1234567890123456";
    unsigned char iv[AES_BLOCK_SIZE]="abcdefghijklmnop";
    int len=strlen((char *)msg);
    int pad=AES_BLOCK_SIZE-(len%AES_BLOCK_SIZE);
    int total=len+pad;
    AES_set_encrypt_key(key,128,&enc_key);
    AES_cbc_encrypt(msg,encrypted,total,&enc_key,iv,AES_ENCRYPT);
    printf("Encrypted Message:");
    for(int i=0;i<total;i++)
    {
        printf("%02X",encrypted[i]);
    }
    AES_set_decrypt_key(key,128,&dec_key);
    unsigned char iv2[AES_BLOCK_SIZE]="abcdefghijklmnop";
    AES_cbc_encrypt(encrypted,decrypted,total,&dec_key,iv2,AES_DECRYPT);
    printf("\nDecrypted Message:%s\n",decrypted);
    return 0;
}