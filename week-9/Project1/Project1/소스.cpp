#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
 * %d %f %c %s \t
 * 5���� Ű���� �����ϱ�
 * ���ڿ��� �����̶� ��ġ���� ���� ��� return -1�� ���� ����ص� ��
 */
#include <stdio.h>
#include <string.h>

int vr_scanf(const char* str, void* a, void* b, void* c, void* d)
{
    char input_str[1024] = { 0 };
    gets_s(input_str);

    int count = sscanf(input_str, str, a, b, c, d);
    if (count != 4) {
        return -1;
    }
    return 0;
}

int main()
{
    int a;
    char b;
    float c;
    char d[1024];

    printf("Enter values ����|���� �Ҽ���, ���� ������ ���Ѽ� �Է� �� ��: ");
    int result = vr_scanf("%d|%c %f,%s", &a, &b, &c, d);
    if (result == 0) {
        printf("Values entered: %d %c %f %s\n", a, b, c, d);
    }
    else {
        printf("Error\n");
    }

    return 0;
}
