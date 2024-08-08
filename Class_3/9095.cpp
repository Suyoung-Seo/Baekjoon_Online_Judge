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
        int n;
        cin >> n;

        int *DP = new int[n + 1];
        DP[1] = 1;
        DP[2] = 2;
        DP[3] = 4;

        for (int i = 4; i <= n; i++)
        {
            DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
        }

        cout << DP[n] << '\n';
    }

    return 0;
}

// endl -> '\n'