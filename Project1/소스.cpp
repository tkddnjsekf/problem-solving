#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <conio.h>

using namespace std;

int roman_to_arabic(string roman) {
    map<char, int> roman_map = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
    map<char, int> roman_map2 = { {'I', 10}, {'V', 10}, {'X', 100}, {'L', 100}, {'C', 1000}, {'D', 1000}, {'M', 10000} };
    vector<int> numGroup;
    int arabic = 0;
    char prev = ' ';
    int sameCount = 0;

    for (char c : roman) {
        if (c == prev) {
            sameCount++;
            if (sameCount == 3) {
                cout << "�߸��� �Է�1 - 4��Ÿ �ߺ�" << endl;
                return -1;
            }
        }
        else {
            sameCount = 0;
        }
        if (roman_map.find(c) == roman_map.end()) {
            cout << "�߸��� �Է�2 - �θ��ڰ� �ƴ�" << endl;
            return -1;
        }
        if (prev != ' ' && roman_map[c] > roman_map[prev]) {
            if (roman_map2[c] / roman_map2[prev] <= 10) {
                arabic += roman_map[c] - 2 * roman_map[prev];
                numGroup[numGroup.size() - 1] = roman_map[c] - roman_map[prev];
            }
            else {
                cout << "�߸��� �Է�3 - �������ڿ� ��������� ���̰� �ʹ� ŭ" << endl;
                return -1;
            }
        }
        else {
            if (arabic + roman_map[c] >= floor(arabic / roman_map2[c]) * roman_map2[c] + roman_map2[c]) {
                cout << "�߸��� �Է�4 - ���� �ڸ��� ���ڷ� ū �ڸ��� ������Ŵ" << endl;
                return -1;
            }
            arabic += roman_map[c];
            numGroup.push_back(roman_map[c]);
        }
        prev = c;
    }
    int max = numGroup[0];
    for (int i = 1; i < numGroup.size(); i++) {
        if (numGroup[i] > max) {
            cout << "�߸��� �Է�5 - ū������ ���� �� ���� ����" << endl;
            return -1;
        }
        max = numGroup[i];
    }
    return arabic;
}

int main() {
    string roman;

    while (true) {
        roman = "";
        cout << "�θ��� �� (�����Ϸ��� 'esc' �Է�) ";
        while (true) {
            char c = _getch();
            if (c == 27) {
                return 0;
            }
            else if (c == 13) {
                break;
            }
            else if (c == 8) {
                if (roman.size() > 0) {
                    cout << c;
                    cout << " ";
                    cout << c;
                    roman.pop_back();
                }
            }
            else {
                roman.push_back(c);
                cout << c;
            }
        }
        cout << endl;

        int arabic = roman_to_arabic(roman);
        if (arabic != -1) {
            cout << "����: " << arabic << endl;
        }
    }

    return 0;
}