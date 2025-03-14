#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void encryption(char *str, const char *key);

int main() {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char key[27];
    int used[26] = {0};

    srand(time(NULL));

    for (int i = 0; i < 26; i++) 
    {
        int randomIndex;
        do 
        {
            randomIndex = rand() % 26;  // Generate random index in the range [0, 25]
        } while (used[randomIndex]);

        key[i] = alphabet[randomIndex];
        used[randomIndex] = 1;

    }

    key[26] = '\0'; 

    printf("Random Key: %s\n\n", key);

    char str1[] = "attack";
    char str2[] = "retreat";
    char str3[] = "hold position";


    printf("Original Text 1: %s\n", str1);
    encryption(str1, key);
    printf("Encrypted Text 1: %s\n\n", str1);

    printf("Original Text 2: %s\n", str2);
    encryption(str2, key);
    printf("Encrypted Text 2: %s\n\n", str2);

    printf("Original Text 3: %s\n", str3);
    encryption(str3, key);
    printf("Encrypted Text 3: %s\n", str3);

    return 0;
}

void encryption(char *str, const char *key) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            int index = str[i] - 'a';  
            str[i] = key[index];
        }
    }
}