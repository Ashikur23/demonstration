#include <stdio.h>      //printf scanf definitions
#include <stdlib.h>    
#include <string.h>

#define UPPER 32             //pre processor directives or macros
#define ASCII_A 65
#define ALPHA_COUNT 26

void menu(void);
void encryptRotationCipher(char [],int);	
void decryptRotationCipher(char [],int);
void encryptSubstitutionCipher(char[], char []);
void decryptSubstitutionCipher(char[], char[]);
void decryptCipherTextWithoutKeyUsingBruteForce(char msg[]);
void decryptUsingRotationCipherWithoutKeyUsingStatistical(char msg[]);


int main()
{
	int option, bytesToRotate, exitLoop=1;
	char str[500];
	char substitution_Arr[27] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // substitution array used to replace characters 'A' to 'Z'
	char msg[200];
	

	while (exitLoop)
	{
		menu();
		printf("\nSelect the option: ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			printf("Enter the string need to be encrypted: ");
			scanf(" %[^\n]%*c", str);   // this will take the whole line of sentences until it reaches '\0'
			printf("Enter no. of bytes to rotate: ");
			scanf("%d", &bytesToRotate);               // bytesToRotate is the key for encrypting the message
			encryptRotationCipher(str,bytesToRotate);  //function call for encrypt rotation 
			printf("\nEncrypted message with Rotation cipher is : %s\n", str);
			break;
		case 2:
			printf("Enter the encrypted string need to be decrypted: ");
	     	scanf(" %[^\n]%*c", str);  //it will take the multi words until it reaches '\0'
			printf("Enter no. of bytes to rotate as given for its encryption: ");
			scanf("%d", &bytesToRotate);   // bytesToRotate is the key for the message
			decryptRotationCipher(str,bytesToRotate);
			printf("\nDecrypted message with Rotation cipher is : %s\n", str);
			break;
		case 3:
			printf("Enter the string need to be encrypted: ");
			scanf(" %[^\n]%*c", str);  //taking multi words except white space punctuation which are unmodified copied to output
			encryptSubstitutionCipher(str, substitution_Arr);
			printf("\nEncrypted message with substitution cipher is : %s\n", str);
			break;
		case 4:
			printf("Enter the encrypted string need to be decrypted: ");
			scanf(" %[^\n]%*c", str); 
			decryptSubstitutionCipher(str, substitution_Arr);
			printf("\nDecrypted message with substitution cipher is : %s\n", str);
			break;
		case 5:
			printf("Enter the encrypted string need to be decrypted: ");
			scanf(" %[^\n]%*c", str);
			decryptCipherTextWithoutKeyUsingBruteForce(str);
			break;
		case 6:
			scanf(" %[^\n]%*c", msg);
			// first will encryp the message using rotation cipher
			encryptRotationCipher(msg, 7);
			printf("Encrypted message: %s\n", msg);
			decryptUsingRotationCipherWithoutKeyUsingStatistical(msg);
			break;
		case 7:
			exitLoop = 0;
			break;
		default:
			break;
		}  // end of switch case
	}  // end of while loop
	return 0;
}   // end of main function

// This function will print all the menu options to choose from
void menu()
{
	printf("*******************************************************************************");
	printf("\n1. Encryption of a message with a Rotation cipher");
	printf("\n2. Decryption of a message encrypted with a rotation cipher");
	printf("\n3. Encryption of a message with a substitution cipher");
	printf("\n4. Decryption of a message encrypted with a substitution cipher");
	printf("\n5. Decryption of a message without key using brute force attack");
	printf("\n6. Decryption of a message without key using Statistical Method");
	printf("\n7. Exit\n");
	printf("*******************************************************************************");
}

// Rotation cipher is also referred as Caesar cipher
// The function will encrypt the message as per the key which is no. of bytestoRotate 
// input : parameter 1 : the message which need to be encrypted
// input : parameter 2 - int bytestoRotate , will take the no. of bytes which we need to rotate in the given text
// return : does not return anything
void encryptRotationCipher(char message[],int bytesToRotate)
{
	char ch; int i;
	int size = 100;   
	for (i = 0; message[i] != '\0'; ++i)
	{
		ch = message[i];
		if (ch >= 'a' && ch <= 'z')
		{
			ch -= UPPER;                 // if letter is a lowercase, convert it into uppercase  ch=ch - UPPER
			ch = ((ch - ASCII_A + bytesToRotate) % ALPHA_COUNT) + ASCII_A;
			
		}
		else if (ch >= 'A' && ch <= 'Z')
		{ 
			ch = ((ch - ASCII_A + bytesToRotate) % ALPHA_COUNT) + ASCII_A;
		}
		message[i] = ch;

	}  // End of for loop
}

// This function will decrypt the encrypted message to its original text using key to rotate.
// input: parameter 1 : the encrypted message which need to be decrypted
// input : parameter 2 : the key which is the no. of bytes to rotate
// return : does not return anything
void decryptRotationCipher(char message[], int key)
{
	char ch; int i;
	
	for (i = 0; message[i] != '\0'; ++i)
	{
		ch = message[i];
		if (message[i] >= 'a' && message[i] <= 'z')  // checking if the letter is in lower case
		{
			ch = (ch - UPPER - key);
			if (ch < ASCII_A)
			{
				int temp = ASCII_A - ch; 
				ch = 90 - temp + 1;
			}
			
		}
		else if (message[i] >= 'A' && message[i] <= 'Z') // if the letter is in uppercase
		{
			ch = (ch - ASCII_A - key);
			if (ch < 0)
			{
				ch += ALPHA_COUNT;
			}
			ch = (ch % ALPHA_COUNT) + ASCII_A;
		}
		message[i] = ch;
	}
	
}

// The function will encrypt the message as per the elements in the substitution array 
// input : parameter 1 : the message msg which need to be encrypted
// input : parameter 2 - substitution array, which is static array 
// return : does not return anything
void encryptSubstitutionCipher(char msg[], char substitute[])
{
	int i;
	char ch;
	for (i = 0; msg[i] != '\0'; ++i)
	{
		ch = msg[i];
		if (ch >= 'a' && ch <= 'z')
			ch -= UPPER;     // to convert the letters in its corresponding upper case
		switch (ch)
		{
		case 'A':
			msg[i] = substitute[0];
			break;
		case 'B':
			msg[i] = substitute[1];
			break;
		case 'C':
			msg[i] = substitute[2];
			break;
		case 'D':
			msg[i] = substitute[3];
			break;
		case 'E':
			msg[i] = substitute[4];
			break;
		case 'F':
			msg[i] = substitute[5];
			break;
		case 'G':
			msg[i] = substitute[6];
			break;
		case 'H':
			msg[i] = substitute[7];
			break;
		case 'I':
			msg[i] = substitute[8];
			break;
		case 'J':
			msg[i] = substitute[9];
			break;
		case 'K':
			msg[i] = substitute[10];
			break;
		case 'L':
			msg[i] = substitute[11];
			break;
		case 'M':
			msg[i] = substitute[12];
			break;
		case 'N':
			msg[i] = substitute[13];
			break;
		case 'O':
			msg[i] = substitute[14];
			break;
		case 'P':
			msg[i] = substitute[15];
			break;
		case 'Q':
			msg[i] = substitute[16];
			break;
		case 'R':
			msg[i] = substitute[17];
			break;
		case 'S':
			msg[i] = substitute[18];
			break;
		case 'T':
			msg[i] = substitute[19];
			break;
		case 'U':
			msg[i] = substitute[20];
			break;
		case 'V':
			msg[i] = substitute[21];
			break;
		case 'W':
			msg[i] = substitute[22];
			break;
		case 'X':
			msg[i] = substitute[23];
			break;
		case 'Y':
			msg[i] = substitute[24];
			break;
		case 'Z':
			msg[i] = substitute[25];
			break;
		}  // end of switch case
	} // end of for loop
}

// The function will decrypt the message as per the elements in the substitution array 
// input : parameter 1 : the encrypted msg which need to be decrypted
// input : parameter 2 - substitution array, which is static array. Same array has been used to encrypt it. 
// return : does not return anything
void decryptSubstitutionCipher(char msg[], char substitute[])
{
	int i, j;
	for (i = 0; msg[i] != '\0'; ++i)
	{
		for (j = 0; j < 26; ++j)
		{
			if (msg[i] == substitute[j])
			{
				msg[i] = ASCII_A + j;
				break;
			}
		}
	}

}


// input : the encrypted message which needs to be decrypted 
// This function will decrypt the encrypted message to its original text without any key, by using brute force
// technique to find all possible 25 strings. 
// return : does not return anything

void decryptCipherTextWithoutKeyUsingBruteForce(char msg[])  // without the key
{
	int n = 25, i, temp; char *msg1;
	char ch;
	msg1 = (char*)malloc(strlen(msg) + 1);
	strcpy(msg1, msg);

	while (n-- > 0)					// All the 25 times for brute force analysis
	{
		for (i = 0; msg[i] != '\0'; ++i)
		{
			ch = msg[i];
			if (msg[i] >= 'a' && msg[i] <= 'z')
			{
				ch = (ch - UPPER - n);
				if (ch < ASCII_A)
				{
					temp = ASCII_A - ch;
					ch = 90 - temp + 1;
				}

			}
			else if (msg[i] >= 'A' && msg[i] <= 'Z')
			{
				ch = (ch - ASCII_A - n);
				if (ch < 0)
				{
					ch += ALPHA_COUNT;
				}
				ch = (ch % ALPHA_COUNT) + ASCII_A;
			}
			msg1[i] = ch;						// decrypting each letter and saving it in msg1 without altering
												// the original msg[]
		}  // End of for loop
		printf("Original Text with %d bytes rotation - %s\n", n, msg1);
	}  // End of while loop
}

// input : the encrypted message which needs to be decrypted 
// This function will decrypt the encrypted message to its original text without any key, by using statistical
// analysis, considering the most occurring character in any english sentence is letter 'E'.
// return : does not return anything
void decryptUsingRotationCipherWithoutKeyUsingStatistical(char msg[])
{
	// Billionaire entrepreneurs are sometimes known for their eccentric lifestyles but Twitter founder Jack Dorsey is being ridiculed on his own platform
	int count[3] = { 0,0,0 }; char maxChar[3] = { 0,0,0 };  // e  t  a    
	int i, p, cnt = 0;
	for (i = 0; msg[i] != '\0'; ++i)   // traversing the entire encrypted message
	{
		cnt = 0;
		char ch = msg[i];
		if (ch == ' ' || ch == maxChar[0] || ch == maxChar[1] || ch == maxChar[2])
			continue;
		for (p = 0; msg[p] != '\0'; p++)
		{
			if (ch == msg[p])
				cnt++;
		}

		if (cnt > count[0])
		{
			count[2] = count[1]; maxChar[2] = maxChar[1]; count[1] = count[0]; maxChar[1] = maxChar[0];
			count[0] = cnt; maxChar[0] = msg[i];
		}
		else if (cnt > count[1])
		{
			count[2] = count[1]; maxChar[2] = maxChar[1]; count[1] = cnt; maxChar[1] = msg[i];
		}
		else if (cnt > count[2])
		{
			count[2] = cnt; maxChar[2] = msg[i];
		}

	}  // end of outer for loop

	   // we have stored 3 maximum occuring characters in maxChar[], which are encrypted using rotation 
	   // By general rule of english, max character which occurs in any english sentence is 'E'
	   // considering the first max character in the array to be encrypted character 'E'... we can get the key
	   //and can use the same key for remaining characters to get the original text before encryption.
	   // we need to do the same process for other 2 remaining max characters considering them to be ecrypted character
	   // for 'E' and then we get 3 english sentences from the 3 maxchars from the encrypted string .... 
	   // One of the three will be our original text which we have decrypted successfully. 





