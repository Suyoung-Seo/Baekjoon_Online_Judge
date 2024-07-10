#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int score;

    cin >> score;

    if (score >= 90)
    {
        cout << 'A' << '\n';
    }
    else if (score >= 80)
    {
        cout << 'B' << '\n';
    }
    else if (score >= 70)
    {
        cout << 'C' << '\n';
    }
    else if (score >= 60)
    {
        cout << 'D' << '\n';
    }
    else
    {
        cout << 'F' << '\n';
    }

    return 0;
}

// endl -> '\n'