#include <iostream>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string s;
        cin >> s;
        cout << s[0] << s[s.size() - 1] << '\n';
    }

    return 0;
}

// endl -> '\n'