#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    map<int, int> S;

    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;

        if (str == "add")
        {
            int num;
            cin >> num;
            if (S.find(num) == S.end())
            {
                S.insert(make_pair(num, 1));
            }
        }
        else if (str == "remove")
        {
            int num;
            cin >> num;
            if (S.find(num) != S.end())
            {
                S.erase(num);
            }
        }
        else if (str == "check")
        {
            int num;
            cin >> num;
            if (S.find(num) != S.end())
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (str == "toggle")
        {
            int num;
            cin >> num;
            if (S.find(num) == S.end())
            {
                S.insert(make_pair(num, 1));
            }
            else
            {
                S.erase(num);
            }
        }
        else if (str == "all")
        {
            for (int i = 1; i <= 20; i++)
            {
                if (S.find(i) == S.end())
                {
                    S.insert(make_pair(i, 1));
                }
            }
        }
        else if (str == "empty")
        {
            S.clear();
        }
    }

    return 0;
}

// endl -> '\n'