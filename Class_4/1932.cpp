#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i < n; i++)
    {
        arr[i][0] += arr[i - 1][0];
        for (int j = 1; j < i; j++)
        {
            if (arr[i - 1][j - 1] < arr[i - 1][j])
            {
                arr[i][j] += arr[i - 1][j];
            }
            else
            {
                arr[i][j] += arr[i - 1][j - 1];
            }
        }
        arr[i][i] += arr[i - 1][i - 1];
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (max < arr[i][j])
            {
                max = arr[i][j];
            }
        }
    }

    cout << max << '\n';

    return 0;
}