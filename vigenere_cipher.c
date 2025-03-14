#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void vigenereEncryption(char *text, const char *key);

int main() {

    char str1[] = "attack";
    char str2[] = "retreat";
    char str3[] = "hold current position";

    // keyword
    char key1[] = "bladeb";
    char key2[] = "bladebl";
    char key3[] = "bladbladeblbladebla";

    // 출력 Original 및 Encrypted 결과
    printf("Original Text 1: %s\n", str1);
    vigenereEncryption(str1, key1);
    printf("Encrypted Text 1: %s\n\n", str1);

    printf("Original Text 2: %s\n", str2);
    vigenereEncryption(str2, key2);
    printf("Encrypted Text 2: %s\n\n", str2);

    printf("Original Text 3: %s\n", str3);
    vigenereEncryption(str3, key3);
    printf("Encrypted Text 3: %s\n", str3);

    return 0;
}

// 비제네르 암호화 함수 정의
void vigenereEncryption(char *text, const char *key) {
    int textLen = strlen(text);
    int keyLen = strlen(key);

    for (int i = 0, j = 0; i < textLen; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') { // 소문자일 경우 암호화 진행
            int textIndex = text[i] - 'a';  // 평문 문자 위치 ('a' 기준 0~25)
            int keyIndex = key[j % keyLen] - 'a'; // 키 문자 위치 ('a' 기준 0~25)
            text[i] = 'a' + (textIndex + keyIndex) % 26; // 암호문 계산
            j++; // 키 인덱스 증가
        }
        // 공백 등의 비문자는 패스
    }
}