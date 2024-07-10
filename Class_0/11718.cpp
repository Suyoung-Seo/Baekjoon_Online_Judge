#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 100; i++)
    {
        string s;
        getline(cin, s);
        cout << s << '\n';
    }

    return 0;
}

// endl -> '\n'