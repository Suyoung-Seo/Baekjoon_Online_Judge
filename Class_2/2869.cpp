#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, V;
    cin >> A >> B >> V;

    int day = (V - B) / (A - B);
    if ((V - B) % (A - B) != 0)
    {
        day++;
    }

    cout << day << '\n';

    return 0;
}

// endl -> '\n'