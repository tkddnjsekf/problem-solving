#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

void toRoman(int num, char* roman) {
    // �ƶ��� ���ڿ� �θ� ���ڸ� ������Ű�� �迭
    int arabic[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    char* romanArr[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    // �θ� ���ڷ� ��ȯ�ϴ� ����
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
    printf("�ƶ��� ���ڸ� �Է��ϼ���: ");
    scanf("%d", &num);
    if (num < 1 || num > 3999) {
        printf("�Էµ� ���ڰ� ������ ������ϴ�.\n");
        return 0;
    }
    printf("�θ� ����: ");
    toRoman(num, roman);
    printf("%s\n", roman);
    return 0;
}