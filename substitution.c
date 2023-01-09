#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
//Accept only one command line argument and quit if not valid
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    for (int n = 0; n < strlen(argv[1]); n++)
    {
//Verify key is 26 digits long
        if (strlen(argv[1]) != 26)
        {
            printf("Please use 26 alphabetical characters for key.\n");
            return 1;
        }
//Verify key is all alpha characters
        if (isalpha(argv[1][n]) == false)
        {
            printf("Please use 26 alphabetical characters for key.\n");
            return 1;
        }
        //Take one char from key and verify no repeats

        int count[26] = { 0 };

        for (int i = 0; i < strlen(argv[1]); i++)
        {
            int index = toupper(argv[1][i]) - 'A';

            if (count[index] > 0)
            {
                printf("Do not repeat characters.\n");
                return 1;
            }
            count[index]++;
        }
    }
    //Prompt for Plaintext:
    string plaintext = get_string("plaintext: ");

    //Print ciphertext

    printf("ciphertext: ");

//Output Ciphertext:, only change alphabetical characters and preserve case
    string dif = argv[1];

    for (int i = 'A'; i <= 'Z'; i++)
    {
        dif[i - 'A'] = toupper(dif[i - 'A']) - i;
    }

    for (int s = 0; s < strlen(plaintext); s++)
    {
        if (isalpha(plaintext[s]))
        {
            plaintext[s] = plaintext[s] + dif[plaintext[s] - (isupper(plaintext[s]) ? 'A' : 'a')];
        }
        printf("%c", plaintext[s]);
    }
//Print new line and exit
    printf("\n");
}
