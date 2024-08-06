#include <iostream>
#include <sstream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int a = 0; a < T; a++)
    {
        string p, arr;
        int n;

        cin >> p >> n >> arr;

        deque<int> d;

        // 문자열 파싱
        arr.erase(0, 1);
        arr.erase(arr.size() - 1, arr.size());

        if (arr != "")
        {
            stringstream ss(arr);
            string s;
            char c = ',';

            while (getline(ss, s, c))
            {
                d.push_back(stoi(s));
            }
        }

        // 덱 조작
        bool isReverse = false, isError = false;
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == 'R')
            {
                isReverse = !isReverse;
            }
            else if (p[i] == 'D')
            {
                if (d.empty())
                {
                    isError = true;
                    break;
                }

                if (isReverse == false)
                {
                    d.pop_front();
                }
                else
                {
                    d.pop_back();
                }
            }
        }

        if (isError == true)
        {
            cout << "error" << '\n';
            continue;
        }

        // 덱 출력
        cout << '[';
        if (!d.empty())
        {
            if (isReverse == false)
            {
                for (int i = 0; i < d.size() - 1; i++)
                {
                    cout << d[i] << ',';
                }
                cout << d[d.size() - 1];
            }
            else
            {
                for (int i = d.size() - 1; i >= 1; i--)
                {
                    cout << d[i] << ',';
                }
                cout << d[0];
            }
        }
        cout << ']' << '\n';
    }

    return 0;
}

// endl -> '\n'