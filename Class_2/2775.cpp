#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[15][15] = {0};
    arr[0][1] = 1;

    for (int i = 1; i <= 14; i++)
    {
        arr[0][i] = i;
        arr[i][1] = 1;
    }

    for (int i = 1; i <= 14; i++)
    {
        for (int j = 2; j <= 14; j++)
        {
            arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
        }
    }

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int k, n;
        cin >> k >> n;

        cout << arr[k][n] << '\n';
    }

    return 0;
}

// endl -> '\n'