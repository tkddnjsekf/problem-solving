#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    unsigned char num;
    printf("unsigned char ���� ������ ���ڸ� �Է��ϼ���: ");
    scanf("%hhu", &num);
    if (num > 255) {
        printf("�Էµ� ���ڰ� unsigned char�� ������ ������ϴ�.\n");
        return 0;
    }
    unsigned char digits[10] = { 0 };
    int i = 0;
    while (num > 0) {
        digits[i++] = num % 10;
        num /= 10;
    }
    printf("�ݴ�� ����� ���: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%hhu", digits[j]);
    }
    printf("\n");
    return 0;
}
