#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X;

    cin >> X;

    int *DP = new int[X + 1];
    DP[2] = DP[3] = 1;

    for (int i = 4; i <= X; i++)
    {
        if (i % 6 == 0)
        {
            if (DP[i / 3] <= DP[i / 2] && DP[i / 3] <= DP[i - 1])
            {
                DP[i] = DP[i / 3] + 1;
            }
            else if (DP[i / 2] <= DP[i / 3] && DP[i / 2] <= DP[i - 1])
            {
                DP[i] = DP[i / 2] + 1;
            }
            else if (DP[i - 1] <= DP[i / 3] && DP[i - 1] <= DP[i / 2])
            {
                DP[i] = DP[i - 1] + 1;
            }
        }
        else if (i % 3 == 0)
        {
            if (DP[i / 3] <= DP[i - 1])
            {
                DP[i] = DP[i / 3] + 1;
            }
            else
            {
                DP[i] = DP[i - 1] + 1;
            }

        }
        else if (i % 2 == 0)
        {
            if (DP[i / 2] <= DP[i - 1])
            {
                DP[i] = DP[i / 2] + 1;
            }
            else
            {
                DP[i] = DP[i - 1] + 1;
            }
        }
        else
        {
            DP[i] = DP[i - 1] + 1;
        }
    }

    cout << DP[X] << '\n';

    return 0;
}

// endl -> '\n'