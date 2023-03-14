#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    unsigned char num;
    printf("unsigned char 범위 내에서 숫자를 입력하세요: ");
    scanf("%hhu", &num);
    if (num > 255) {
        printf("입력된 숫자가 unsigned char의 범위를 벗어났습니다.\n");
        return 0;
    }
    unsigned char digits[10] = { 0 };
    int i = 0;
    while (num > 0) {
        digits[i++] = num % 10;
        num /= 10;
    }
    printf("반대로 출력한 결과: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%hhu", digits[j]);
    }
    printf("\n");
    return 0;
}
