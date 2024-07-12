#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        string s;
        cin >> s;
        if (s == "0")
        {
            break;
        }

        bool isPalin = true;

        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
            {
                isPalin = false;
                break;
            }
        }
        
        if (isPalin)
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }

    return 0;
}

// endl -> '\n'