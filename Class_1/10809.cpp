#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;

    int alpha[26] = {0};

    for (int i = 0; i < S.size(); i++)
    {
        if (alpha[(int)S[i] - 97] == 0)
        {
            alpha[(int)S[i] - 97] = i + 1;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        cout << alpha[i] - 1 << ' ';
    }
    cout << '\n';

    return 0;
}

// endl -> '\n'