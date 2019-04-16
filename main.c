#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(void);
	void encryptRotationCipher(char [],int);
	void decryptRotationCipher(char [],int);
	void encryptSubstitutionCipher(char[], char []);
	void decryptSubstitutionCipher(char[], char[]);
	void decryptCipherTextWithoutKeyUsingBruteForce(char msg[]);
	void decryptUsingRotationCipherWithoutKeyUsingStatistical(char msg[]);
	void Encrypt(int);
	void Decrypt(int);


#define UPPER 32
#define ASCII_A 65
#define ALPHA_COUNT 26

int main()
{
	int option, bytesToRotate, exitLoop=1;
	char str[200];
	char substitution_Arr[26] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // substitution array used to replace characters 'A' to 'Z'
	char msg[200];

	void menu(void);
	void encryptRotationCipher(char [],int);
	void decryptRotationCipher(char [],int);
	void encryptSubstitutionCipher(char[], char []);
	void decryptSubstitutionCipher(char[], char[]);
	void decryptCipherTextWithoutKeyUsingBruteForce(char msg[]);
	void decryptUsingRotationCipherWithoutKeyUsingStatistical(char msg[]);
	void Encrypt(int);
	void Decrypt(int);

	while (exitLoop)
	{
		menu();
		printf("\nSelect the option: ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			printf("Enter the string need to be encrypted: ");
			fflush(stdin);
			scanf("%s", str);
			printf("Enter no. of bytes to rotate: ");
			scanf("%d", &bytesToRotate);               // bytesToRotate is the key for encrypting the message
			//char msg[500] = "The seasoned comedienne actress revealed that she gets half the salary paid to Navjot Singh Sidhu for the show";
			encryptRotationCipher(str,bytesToRotate);
			printf("\nEncrypted message with Rotation cipher is : %s\n", str);
			break;
		case 2:
			printf("Enter the encrypted string need to be decrypted: ");
			scanf("%s", str);
			printf("Enter no. of bytes to rotate as given for its encryption: ");
			scanf("%d", &bytesToRotate);
			decryptRotationCipher(str,bytesToRotate);
			printf("\nDecrypted message with Rotation cipher is : %s\n", str);
			break;
		case 3:
			printf("Enter the string need to be encrypted: ");
			scanf("%s", str);
			encryptSubstitutionCipher(str, substitution_Arr);
			printf("\nEncrypted message with substitution cipher is : %s\n", str);
			break;
		case 4:
			printf("Enter the encrypted string need to be decrypted: ");
			scanf("%s", str);
			decryptSubstitutionCipher(str, substitution_Arr);
			printf("\nDecrypted message with substitution cipher is : %s\n", str);
			break;
		case 5:
			printf("Enter the encrypted string need to be decrypted: ");
			scanf("%s", str);
			decryptCipherTextWithoutKeyUsingBruteForce(str);
			break;
		case 6:
			strcpy(msg, "Billionaire entrepreneurs are sometimes known for their eccentric lifestyles but Twitter founder Jack Dorsey is being ridiculed on his own platform");
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
	system("pause");
	return 0;
}

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
	char ch; int i, temp;
	int size = 100;
	fflush(stdin);
	//scanf("%[^\n]%*c", message);
	//fgets(message,100,stdin);
	
	for (i = 0; message[i] != '\0'; ++i)
	{
		ch = message[i];
		if (ch >= 'a' && ch <= 'z')
		{
			ch -= UPPER;                 // if letter is a lowercase, convert it into uppercase
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
// input : parameter 1 : the key which is the no. of bytes to rotate
// return : does not return anything
void decryptRotationCipher(char message[], int key)
{
	char ch; int i;
	//fgets(message,100,stdin);
	for (i = 0; message[i] != '\0'; ++i)
	{
		ch = message[i];
		if (message[i] >= 'a' && message[i] <= 'z')  // if the letter is in lowercase
		{
			ch = (ch - UPPER - key);
			if (ch < ASCII_A)
			{
				int temp = ASCII_A - ch; 
				ch = 90 - temp +1;
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
