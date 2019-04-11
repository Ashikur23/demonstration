#include <stdio.h>
#include <string.h>

void menu();
void convertToUpper(char *p);
void encrypt(char[],int);
void decrypt(char[],int);

int main()
{
    int key,mes;
    printf("Enter Message:");
    scanf("%d",mes);
    printf("Enter Key:");
    scanf("%d",&key);
    char str[50];
  
    if(key > 0 && key < 26)
    {
        menu();
        Encrypt(str,key);
        printf("\nEncrypted message as: %s\n", str);

        Decrypt(str,key);
        printf("Decrypted message as: %s", str);
    }
    else
        printf("\n Key is invalid");
        
        return(0);
}

void menu()
{
    printf("*******************************************************************************");
    printf("\n1. Encryption of a message with a Rotation cipher");
    printf("\n2. Decryption of a message encrypted with a rotation cipher");
    printf("\n3. Encryption of a message with a substitution cipher");
    printf("\n4. Decryption of a message encrypted with a substitution cipher");
    printf("\n5. Decryption of a message encrypted with a rotation cipher given cypher text only");
    printf("\n6. Decryption of a message encrypted with a substitution cipher given cypher text only");
    printf("\n7. Exit\n");
    printf("*******************************************************************************");
}

void convertToUpper(char *p)
{
    int i;
    for(i = 0; p[i] != '\0'; ++i)
    {
        if(p[i] >= 97 && p[i] <= 122)
            p[i] = p[i] - 32;
    }
}

void encrypt(char message[],int key){
    int i, ch;
    int change, temp, key_temp;

    for(i = 0; message[i] != '\0'; ++i)
    {
		ch = message[i];
		if( (ch >=65 && ch <=90 ) )
        {
            change = ch + key;
            if(change <= 90)
            {
                ch = ch + key;
            }
            else
            {
                temp = 90 - ch;
                key_temp = key - temp;
                ch = 64 + key_temp;
            }
            message[i] = ch;
        }
        else
        if( (ch >= 97 && ch <= 122 ) )
        {
            change = ch + key;
            if(change <= 122)
            {
                ch = ch + key;
            }
            else
            {
                temp = 122 - ch;
                key_temp = key - temp;
                ch = 96 + key_temp;
            }
            message[i] = ch;
        }
    }
}

void decrypt(char msg[],int key){
    int i, ch;
    int change, temp, key_temp;

    for(i = 0; msg[i] != '\0'; ++i)
    {
		ch = msg[i];

		if( (ch >=65 && ch <=90) )
        {
            if((ch - key) >= 65)
            {
                ch = ch - key;
            }
            else
            {
                temp = ch - 65;
                key_temp = key - temp;
                ch = 91 - key_temp;
            }
            msg[i] = ch;
        }
        else if( (ch >= 97 && ch <= 122 ) )
        {
            if( (ch - key)  >= 97)
            {
                ch = ch - key;
            }
            else
            {
                temp = ch - 97;
                key_temp = key - temp;
                ch = 123 - key_temp;
            }
            msg[i] = ch;
        }
    }

}
