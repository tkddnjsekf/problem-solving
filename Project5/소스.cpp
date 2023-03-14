#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

void toRoman(int num, char* roman) {
    // 아라비아 숫자와 로마 숫자를 대응시키는 배열
    int arabic[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    char* romanArr[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    // 로마 숫자로 변환하는 과정
    int i = 0;
    while (num > 0) {
        int j = num / arabic[i];
        for (int k = 0; k < j; k++) {
            strcat(roman, romanArr[i]);
            num -= arabic[i];
        }
        i++;
    }
}

int main() {
    int num;
    char roman[100] = "";
    printf("아라비아 숫자를 입력하세요: ");
    scanf("%d", &num);
    if (num < 1 || num > 3999) {
        printf("입력된 숫자가 범위를 벗어났습니다.\n");
        return 0;
    }
    printf("로마 숫자: ");
    toRoman(num, roman);
    printf("%s\n", roman);
    return 0;
}