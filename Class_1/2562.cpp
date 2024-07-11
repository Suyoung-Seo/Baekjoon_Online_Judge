#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int min, idx = 1;
    cin >> min;

    for (int i = 0; i < 8; i++)
    {
        int temp;
        cin >> temp;
        if (min < temp)
        {
            min = temp;
            idx = i + 2;
        }
    }

    cout << min << '\n' << idx << '\n';

    return 0;
}

// endl -> '\n'