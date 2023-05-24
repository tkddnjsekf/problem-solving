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
                        throw runtime_error("잘못된 %%포맷");
                    }
                    // 불필요 부분 삭제
                    pattern = pattern.substr(i + 2, pattern.length() - (i+2));
                    text = text.substr(i, text.length() - i);
                    //불필요한 부분을 앞에서 삭제함
                    //ex
                    /*
                        내 이름은 %s이고 이번학기 점수는 %d9999점이고 성적은 %c를 받았습니다.
                        내 이름은 멋진 이은석님이고 이번학기 점수는 989999점이고 성적은 A를 받았습니다.
                    */
                    //     VVV
                    /*
                        이고 이번학기 점수는 %d9999점이고 성적은 %c를 받았습니다.
                        멋진 이은석님이고 이번학기 점수는 989999점이고 성적은 A를 받았습니다.
                    */
                    if (state == Char)
                    {
                        cv.push_back(text.at(0));
                        text = text.substr(1, text.length() - 1);
                    }
                    else
                    {
                        // 패턴의 다음 %지점 또는 종료지점 탐색
                        int endIndex = pattern.length() - 1;
                        for (int j = pattern.length() - 1; j >= 0; j--)
                        {
                            if (pattern.at(j) == '%')
                            {
                                endIndex = j;
                            }
                        }
                        /*
                            endIndex는 %d등을 찾아서
                            "이고 이번학기 점수는 "을 추출하여

                            "(이고 이번학기 점수는 )%d9999점이고 성적은 %c를 받았습니다.
                            멋진 이은석님(이고 이번학기 점수는 )989999점이고 성적은 A를 받았습니다.
                            
                            한칸씩 슬라이딩 윈도우처럼 비교하면서
                            따옴표안의 내용이 전체 일치하도록 한다음
                            맨 앞에 남은 문자 ex "멋진 이은석님" 추출
                        */


                        // 0~endIndex까지 모두 일치 할 때 까지 text에서 슬라이딩 윈도우 사용
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
                                // 모두 일치 배열에 해당 값 추가
                                // 0~k-1 까지 유효문자
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

            //출력
            cout << "int(" << iv.size() << "개):";
            for(auto &elem : iv){
                cout << elem;
                if (&elem - &iv[0] != iv.size()-1)
                {
                    cout << ", ";
                }
            }
            cout << endl;
            cout << "char(" << cv.size() << "개):";
            for (auto& elem : cv) {
                cout << elem;
                if (&elem - &cv[0] != cv.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << endl;
            cout << "string(" << sv.size() << "개):";
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
            cout << "잘못된 입력입니다." << endl;
            cout << e.what() << endl;
            return -1;
        }
    }
    else
    {
        cout << "파일을 열 수 없습니다." << endl;
    }
    return 0;
}
