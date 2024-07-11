#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    getline(cin, s);
    int blank = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            blank++;
        }
    }

    if (s[0] == ' ')
    {
        blank--;
    }

    if (s[s.size() - 1] == ' ')
    {
        blank--;
    }

    cout << blank + 1 << '\n';

    return 0;
}

// endl -> '\n'