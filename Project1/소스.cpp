#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int romanToDecimal(char* roman) {
    int i, decimal = 0, len = strlen(roman);
    int prev = 0, curr = 0, count = 0;
    int prev_char = 0;

    for (i = 0; i < len; i++) {
        switch (roman[i]) {
        case 'I':
            curr = 1;
            break;
        case 'V':
            curr = 5;
            break;
        case 'X':
            curr = 10;
            break;
        case 'L':
            curr = 50;
            break;
        case 'C':
            curr = 100;
            break;
        case 'D':
            curr = 500;
            break;
        case 'M':
            curr = 1000;
            break;
        default:
            printf("잘못된 입력입니다.\n");
            return -1;
        }
        if (prev_char && curr != prev_char) {
            if (!((prev_char == 1 && (curr == 5 || curr == 10)) ||
                (prev_char == 10 && (curr == 50 || curr == 100)) ||
                (prev_char == 100 && (curr == 500 || curr == 1000)))) {
                printf("잘못된 입력입니다.\n");
                return -1;
            }
        }

        // 동일한 문자가 두 개 이상 붙어있는 경우 처리
        prev_char = curr;
        if (curr == prev) {
            count++;
            if (curr == 5 || curr == 50 || curr == 500) { // LL, VV, DD
                printf("잘못된 입력입니다.\n");
                return -1;
            }
            else if (count > 3) {
                printf("잘못된 입력입니다.\n");
                return -1;
            }
        }
        else {
            count = 1;
        }

        if (curr > prev && prev != 0) {
            if ((curr == 5 && (prev == 1 || prev == 10)) || // IV, IX
                (curr == 10 && (prev == 1 || prev == 5)) || // XL, XC
                (curr == 50 && (prev == 1 || prev == 10 || prev == 5 || prev == 100)) || // IL, IC, ID, IM
                (curr == 100 && (prev == 1 || prev == 10 || prev == 50))) { // CD, CM
                decimal -= prev;
                decimal += (curr - prev);
            }
            else if ((prev == 100 && (curr == 500 || curr == 1000)) || // CD, CM
                (prev == 10 && (curr == 50 || curr == 100)) || // XL, XC
                (prev == 1 && (curr == 5 || curr == 10))) { // IV, IX
                decimal -= prev;
                decimal += (curr - prev);
            }
            else {
                printf("잘못된 입력입니다.\n");
                return -1;
            }
        }
        else {
            decimal += curr;
        }

        prev = curr;
    }

    return decimal;
}

int main() {
    char roman[20];
    int decimal;

    while (1) {
        printf("로마 숫자를 입력하세요 (1~3999): ");
        scanf("%s", roman);

        if (strcmp(roman, "esc") == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        decimal = romanToDecimal(roman);
        if (decimal != -1) {
            printf("%s = %d\n", roman, decimal);
        }
    }

    return 0;
}
    