#include <iostream>
using namespace std;

int Z(int N, int r, int c, int num)
{
    if (N == 1)
    {
        if (r == 0)
        {
            if (c == 0)
            {
                return num;
            }
            else
            {
                return num + 1;
            }
        }
        else
        {
            if (c == 0)
            {
                return num + 2;
            }
            else
            {
                return num + 3;
            }
        }
    }
    else
    {
        int exp2 = 1, exp4 = 1;
        for (int i = 0; i < N; i++)
        {
            exp2 *= 2; // 2 ^ N
            exp4 *= 4; // 2 ^ (N * 2)
        }
        exp4 /= 4; // 2 ^ (N * 2 - 2)

        if (r < exp2 / 2)
        {
            if (c < exp2 / 2)
            {
                return Z(N - 1, r, c, num);
            }
            else
            {
                return Z(N - 1, r, c - exp2 / 2, num + exp4);
            }
        }
        else
        {
            if (c < exp2 / 2)
            {
                return Z(N - 1, r - exp2 / 2, c, num + exp4 * 2);
            }
            else
            {
                return Z(N - 1, r - exp2 / 2, c - exp2 / 2, num + exp4 * 3);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, r, c;
    cin >> N >> r >> c;

    int res = Z(N, r, c, 0);
    cout << res << '\n';

    return 0;
}

// endl -> '\n'