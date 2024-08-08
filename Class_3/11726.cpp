#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int *DP = new int[n + 1];

    DP[1] = 1;
    DP[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
    }

    cout << DP[n] << '\n';

    return 0;
}

// endl -> '\n'