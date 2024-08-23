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

        int **sticker = new int *[2];

        for (int j = 0; j < 2; j++)
        {
            sticker[j] = new int[n];
            for (int k = 0; k < n; k++)
            {
                cin >> sticker[j][k];
            }
        }

        // DP[0][i] = DP[1][i-1]과 DP[1][i-2] 중 최댓값
        // DP[1][i] = DP[0][i-1]과 DP[0][i-2] 중 최댓값

        sticker[0][1] += sticker[1][0];
        sticker[1][1] += sticker[0][0];
        for (int j = 2; j < n; j++)
        {
            if (sticker[1][j - 1] > sticker[1][j - 2])
            {
                sticker[0][j] += sticker[1][j - 1];
            }
            else
            {
                sticker[0][j] += sticker[1][j - 2];
            }

            if (sticker[0][j - 1] > sticker[0][j - 2])
            {
                sticker[1][j] += sticker[0][j - 1];
            }
            else
            {
                sticker[1][j] += sticker[0][j - 2];
            }
        }

        if (sticker[0][n - 1] > sticker[1][n - 1])
        {
            cout << sticker[0][n - 1] << '\n';
        }
        else
        {
            cout << sticker[1][n - 1] << '\n';
        }
    }

    return 0;
}