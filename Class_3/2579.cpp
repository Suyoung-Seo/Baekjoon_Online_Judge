#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X;
    cin >> X;

    int *num = new int[X + 1];
    int *DP = new int[X + 1];

    for (int i = 1; i <= X; i++)
    {
        int a;
        cin >> a;

        num[i] = a;
    }

    DP[1] = num[1];
    DP[2] = num[1] + num[2];
    DP[3] = num[3];

    if (num[1] < num[2])
    {
        DP[3] += num[2];
    }
    else
    {
        DP[3] += num[1];
    }

    for (int i = 4; i <= X; i++)
    {
        DP[i] = num[i];

        if (DP[i - 2] <= num[i - 1] + DP[i - 3])
        {
            DP[i] += num[i - 1] + DP[i - 3];
        }
        else
        {
            DP[i] += DP[i - 2];
        }
    }

    cout << DP[X] << '\n';

    return 0;
}

// endl -> '\n'