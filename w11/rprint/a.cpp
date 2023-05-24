#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

enum State
{
    None,
    String,
    Int,
    Char
};

int main()
{
    ifstream file("C:\\a.txt");
    vector<string> sv;
    vector<int> iv;
    vector<char> cv;

    if (file.is_open())
    {
        try
        {
            string pattern, text;
            getline(file, pattern);
            getline(file, text);

            int i = 0;
            State state = None;
            while (pattern.length() != 0 && i < pattern.length())
            {
                if (pattern.at(i) == '%')
                {
                    switch (pattern.at(i + 1))
                    {
                    case 's': // 1
                        state = String;
                        break;
                    case 'd': // 2
                        state = Int;
                        break;
                    case 'c': // 3
                        state = Char;
                        break;
                    default:
                        throw runtime_error("�߸��� %%����");
                    }
                    // ���ʿ� �κ� ����
                    pattern = pattern.substr(i + 2, pattern.length() - (i+2));
                    text = text.substr(i, text.length() - i);
                    //���ʿ��� �κ��� �տ��� ������
                    //ex
                    /*
                        �� �̸��� %s�̰� �̹��б� ������ %d9999���̰� ������ %c�� �޾ҽ��ϴ�.
                        �� �̸��� ���� ���������̰� �̹��б� ������ 989999���̰� ������ A�� �޾ҽ��ϴ�.
                    */
                    //     VVV
                    /*
                        �̰� �̹��б� ������ %d9999���̰� ������ %c�� �޾ҽ��ϴ�.
                        ���� ���������̰� �̹��б� ������ 989999���̰� ������ A�� �޾ҽ��ϴ�.
                    */
                    if (state == Char)
                    {
                        cv.push_back(text.at(0));
                        text = text.substr(1, text.length() - 1);
                    }
                    else
                    {
                        // ������ ���� %���� �Ǵ� �������� Ž��
                        int endIndex = pattern.length() - 1;
                        for (int j = pattern.length() - 1; j >= 0; j--)
                        {
                            if (pattern.at(j) == '%')
                            {
                                endIndex = j;
                            }
                        }
                        /*
                            endIndex�� %d���� ã�Ƽ�
                            "�̰� �̹��б� ������ "�� �����Ͽ�

                            "(�̰� �̹��б� ������ )%d9999���̰� ������ %c�� �޾ҽ��ϴ�.
                            ���� ��������(�̰� �̹��б� ������ )989999���̰� ������ A�� �޾ҽ��ϴ�.
                            
                            ��ĭ�� �����̵� ������ó�� ���ϸ鼭
                            ����ǥ���� ������ ��ü ��ġ�ϵ��� �Ѵ���
                            �� �տ� ���� ���� ex "���� ��������" ����
                        */


                        // 0~endIndex���� ��� ��ġ �� �� ���� text���� �����̵� ������ ���
                        for (int k = 0; k < text.length(); k++)
                        {
                            int match = 0;
                            for (int j = 0; j < endIndex; j++)
                            {
                                if (text.at(k + j) == pattern.at(j))
                                {
                                    match++;
                                }
                            }
                            if (match == endIndex)
                            {
                                // ��� ��ġ �迭�� �ش� �� �߰�
                                // 0~k-1 ���� ��ȿ����
                                switch (state)
                                {
                                case String:
                                    sv.push_back(text.substr(0, k));
                                    text = text.substr(k, text.length() - k);
                                    break;
                                case Int:
                                    iv.push_back(atoi(text.substr(0, k).c_str()));
                                    text = text.substr(k, text.length() - k);
                                    break;
                                }
                                break;
                            }
                        }
                    }
                    i = 0;
                }
                else
                {
                    i++;
                }
            }
            file.close();

            //���
            cout << "int(" << iv.size() << "��):";
            for(auto &elem : iv){
                cout << elem;
                if (&elem - &iv[0] != iv.size()-1)
                {
                    cout << ", ";
                }
            }
            cout << endl;
            cout << "char(" << cv.size() << "��):";
            for (auto& elem : cv) {
                cout << elem;
                if (&elem - &cv[0] != cv.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << endl;
            cout << "string(" << sv.size() << "��):";
            for (auto& elem : sv) {
                cout << elem;
                if (&elem - &sv[0] != sv.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << endl;
        }
        catch (const exception &e)
        {
            cout << "�߸��� �Է��Դϴ�." << endl;
            cout << e.what() << endl;
            return -1;
        }
    }
    else
    {
        cout << "������ �� �� �����ϴ�." << endl;
    }
    return 0;
}
